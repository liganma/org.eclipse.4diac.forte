#include "ZephyrIODeviceController.h"
#include <handler/ZephyrIODeviceController.h>
#include <handle/PinHandle.h>

DEFINE_HANDLER(ZephyrIODeviceController);

ZephyrIODeviceController::ZephyrIODeviceController(CDeviceExecution& paDeviceExecution) 
: forte::core::io::IODeviceController(paDeviceExecution){
}

ZephyrIODeviceController::~ZephyrIODeviceController() {
  DEVLOG_INFO("ZephyrIODeviceController dtor\n");
}

ZephyrIODeviceController::IOHandle *
ZephyrIODeviceController::initHandle(HandleDescriptor *paHandleDescriptor) {
  auto desc = static_cast<ZephyrIOHandleDescriptor *>(paHandleDescriptor);
  IOHandle *handle = new IOHandleGPIO(this, desc->mDirection);
  return static_cast<IOHandle *>(handle);
}

void ZephyrIODeviceController::setConfig(struct forte::core::io::IODeviceController::Config* paConfig) {
  DEVLOG_INFO("ZephyrIODeviceController::setConfig\n");
  if (isAlive()) {
    DEVLOG_ERROR("ZephyrIODeviceController::setConfig: Cannot change configuration while running.\n");
    return;
  }
  mConfig = *static_cast<Config*>(paConfig);
}

void ZephyrIODeviceController::handleChangeEvent(IOHandle* paHandle) {
  (void)paHandle;
  mUpdateSema.inc();
}

void ZephyrIODeviceController::runLoop() {
  DEVLOG_INFO("ZephyrIOHandleDeviceController::runLoop\n");
  while (isAlive()) {
    if (mConfig.updateInterval > 0) {
      mUpdateSema.timedWait(mConfig.updateInterval * 1000000ULL); // update interval ms to ns
    } else {
      mUpdateSema.waitIndefinitely();
    }

    checkForInputChanges();

    if (hasError()) {
      break;
    }

  }
  DEVLOG_INFO("ZephyrIODeviceController::runLoop done\n");
}

bool ZephyrIODeviceController::isHandleValueEqual(IOHandle* paHandle) {
  switch(paHandle->getIOHandleDataType()) {
  case CIEC_ANY::e_BOOL:
    return static_cast<IOHandleGPIO*>(paHandle)->equal();
    break;
  default:
    return false;
    break;
  }
}

