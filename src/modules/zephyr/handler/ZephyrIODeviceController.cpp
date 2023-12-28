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

void ZephyrIODeviceController::runLoop() {
  DEVLOG_INFO("ZephyrIOHandleDeviceController::runLoop\n");
  while (isAlive()) {
    CThread::sleepThread(mConfig.updateInterval);
  }
  DEVLOG_INFO("ZephyrIODeviceController::runLoop done\n");
}

