#ifndef ZEPHYRIO_DEVICE_CONTROLLER_H
#define ZEPHYRIO_DEVICE_CONTROLLER_H

#include "core/io/device/io_controller.h"
#include "core/io/mapper/io_handle.h"
#include "extevhan.h"

class ZephyrIODeviceController : public forte::core::io::IODeviceController {
public:
  using HandleDescriptor = forte::core::io::IODeviceController::HandleDescriptor;
  using IOMapper = forte::core::io::IOMapper;
  using IOHandle = forte::core::io::IOHandle;

  DECLARE_HANDLER(ZephyrIODeviceController);

  class ZephyrIOHandleDescriptor
    : public forte::core::io::IODeviceController::HandleDescriptor {
  public:
    ZephyrIOHandleDescriptor(std::string const &paId,
      forte::core::io::IOMapper::Direction paDirection)
      : HandleDescriptor(paId, paDirection) { (void)paDirection; }

    ZephyrIOHandleDescriptor(std::string const &paId)
      : HandleDescriptor(paId, IOMapper::UnknownDirection) {}
  };


  IOHandle* initHandle(HandleDescriptor* paHandleDescriptor) override;

  void setConfig(Config *paConfig) override {
    (void)paConfig;
    DEVLOG_INFO("ZephyrIOHandleDescriptor::setConfig\n");
    if (isAlive()) {
      DEVLOG_ERROR("ZephyrIOHandleDescriptor::setConfig: Cannot change configuration while running.\n");
      return;
    }
  }
  const char *init() override {
    DEVLOG_INFO("ZephyrIOHandleDescriptor::init\n");
    const char *x = "";
    return x;
  }
  void runLoop() override {
    DEVLOG_INFO("ZephyrIOHandleDescriptor::runLoop\n");
    while (isAlive()) {
    }
    DEVLOG_INFO("ZephyrIOHandleDescriptor::runLoop done\n");
  }
  void deInit() override {
    DEVLOG_INFO("ZephyrIOHandleDescriptor::deInit\n");
  }
};

#endif /* ifndef ZEPHYRIO_DEVICE_CONTROLLER_H */
