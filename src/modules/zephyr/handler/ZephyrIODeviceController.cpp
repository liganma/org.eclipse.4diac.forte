#include "ZephyrIODeviceController.h"
#include <handler/ZephyrIODeviceController.h>
#include <handle/PinHandle.h>

DEFINE_HANDLER(ZephyrIODeviceController);

ZephyrIODeviceController::ZephyrIODeviceController(CDeviceExecution& paDeviceExecution) 
: forte::core::io::IODeviceController(paDeviceExecution){
}

ZephyrIODeviceController::~ZephyrIODeviceController() {}

ZephyrIODeviceController::IOHandle *
ZephyrIODeviceController::initHandle(HandleDescriptor *paHandleDescriptor) {
  DEVLOG_INFO("ZephyrIODeviceController::initHandle\n");
  auto desc = static_cast<ZephyrIOHandleDescriptor *>(paHandleDescriptor);
  (void)desc;
  IOHandle *handle = new IOHandleGPIO(this);
  return static_cast<IOHandle *>(handle);
}
