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

  struct Config : forte::core::io::IODeviceController::Config {
    unsigned int updateInterval = 0; // Sets the period for the data update cycle, default 0 means infinite.
  };

  enum HandleType {
    Bit,
  };

  class ZephyrIOHandleDescriptor
    : public forte::core::io::IODeviceController::HandleDescriptor {
  public:
    HandleType mType;

    ZephyrIOHandleDescriptor(std::string const &paId,
      forte::core::io::IOMapper::Direction paDirection, HandleType paType)
      : HandleDescriptor(paId, paDirection), mType(paType) {}
  };

  IOHandle* initHandle(HandleDescriptor* paHandleDescriptor) override;

  void setConfig(struct forte::core::io::IODeviceController::Config* paConfig) override;

  void handleChangeEvent(IOHandle *paHandle) override;

protected:
  const char *init() override {
    DEVLOG_INFO("ZephyrIODeviceController::init\n");
    return nullptr;
  }
  void runLoop() override;
  void deInit() override {
    DEVLOG_INFO("ZephyrIODeviceController::deInit\n");
  }

  bool isHandleValueEqual(IOHandle* paHandle) override;

  struct Config mConfig;
  CSemaphore mUpdateSema;
};

#endif /* ifndef ZEPHYRIO_DEVICE_CONTROLLER_H */
