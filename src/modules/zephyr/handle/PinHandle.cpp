#include "PinHandle.h"

IOHandleGPIO::IOHandleGPIO(ZephyrIODeviceController *paDeviceCtrl)
    : IOHandle(static_cast<forte::core::io::IODeviceController*>(paDeviceCtrl), IOMapper::UnknownDirection, CIEC_ANY::e_BOOL) {}

void IOHandleGPIO::onObserver(IOObserver *paObserver) {
  DEVLOG_INFO("IOHandleGPIO::onObserver\n");
  IOHandle::onObserver(paObserver);
  mDirection = paObserver->getDirection();
}

void IOHandleGPIO::dropObserver() {
  DEVLOG_INFO("IOHandleGPIO::dropObserver\n");
  IOHandle::dropObserver();
  mDirection = IOMapper::UnknownDirection;
}

void IOHandleGPIO::get(CIEC_ANY &paState) {
  DEVLOG_INFO("IOHandleGPIO::get\n");
  static_cast<CIEC_BOOL &>(paState) = CIEC_BOOL(true);
}

void IOHandleGPIO::set(const CIEC_ANY &paState) {
  (void)paState;
  DEVLOG_INFO("IOHandleGPIO::set\n");
}
          
// void forte::core::io::IOHandle::onChange()
// Use this to notify IOHandle of asynchronous value changes, i.e. IRQs
