#ifndef PIN_HANDLE_H
#define PIN_HANDLE_H

#include <core/io/mapper/io_handle.h>
#include <core/io/mapper/io_observer.h>
#include <handler/ZephyrIODeviceController.h>
#include <stdint.h>

class ZephyrIODeviceController;

class IOHandleGPIO : public forte::core::io::IOHandle {
  using IOObserver = forte::core::io::IOObserver;
  using IOHandle = forte::core::io::IOHandle;
  using IOMapper = forte::core::io::IOMapper;

public:
  IOHandleGPIO(ZephyrIODeviceController *paDeviceCtrl);
  void get(CIEC_ANY &) override;
  void set(const CIEC_ANY &) override;

protected:
  void onObserver(IOObserver *paObserver) override;
  void dropObserver() override;

private:
};

#endif
