/************************************************************************************
 Copyright (c) 2024 KT Elektronik GmbH
 This program and the accompanying materials are made available under the
 terms of the Eclipse Public License 2.0 which is available at
 http://www.eclipse.org/legal/epl-2.0.

 SPDX-License-Identifier: EPL-2.0
 
 Contributors:
  Dirk Kaar - initial API and implementation and/or initial documentation
 ************************************************************************************/

#include "IOHandleGPIO.h"
 
IOHandleGPIO::IOHandleGPIO(IODeviceController *paDeviceCtrl, IOMapper::Direction paDirection,
  gpio_dt_spec* paGpioSpec, gpio_flags_t paFlags) :
  IOHandle(paDeviceCtrl, paDirection, CIEC_ANY::e_BOOL), mGpioSpec(paGpioSpec) {
  if (!gpio_is_ready_dt(getGpioSpec())) {
    DEVLOG_ERROR("IOHandleGPIO::IOHandleGPIO: device %s is not ready\n",
      getGpioSpec()->port->name);
    return;
  }
  const gpio_flags_t ioFlags = paFlags & ~GPIO_INT_MASK;
  int ret = gpio_pin_configure_dt(getGpioSpec(), ioFlags);
  if (ret != 0) {
    DEVLOG_ERROR("IOHandleGPIO::IOHandleGPIO: error %d, failed to configure %s pin %d\n",
      ret, getGpioSpec()->port->name, getGpioSpec()->pin);
    return;
  }
  const gpio_flags_t intFlags = paFlags & GPIO_INT_MASK;
  if (isOutput() || 0 == intFlags) { return; }
  ret = gpio_pin_interrupt_configure_dt(getGpioSpec(), intFlags);
  if (ret != 0) {
    DEVLOG_ERROR("IOHandleGPIO::IOHandleGPIO: error %d, failed to configure interrupt on %s pin %d\n",
      ret, getGpioSpec()->port->name, getGpioSpec()->pin);
    return;
  }
  gpio_init_callback(&mGpioCallbackCtx.gpio_cb_data, irq_callback, BIT(getGpioSpec()->pin));
  mGpioCallbackCtx.self = this;
  gpio_add_callback(getGpioSpec()->port, &mGpioCallbackCtx.gpio_cb_data);
}

IOHandleGPIO::~IOHandleGPIO() {
  DEVLOG_INFO("IOHandleGPIO dtor\n");
}

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
  DEVLOG_DEBUG("IOHandleGPIO::get\n");
  auto value = gpio_pin_get_dt(getGpioSpec());
  static_cast<CIEC_BOOL &>(paState) = CIEC_BOOL(value);
  mLastValue = value;
}

void IOHandleGPIO::set(const CIEC_ANY &paState) {
  DEVLOG_DEBUG("IOHandleGPIO::set\n");
  const CIEC_BOOL value = static_cast<const CIEC_BOOL &>(paState);
  gpio_pin_set_dt(getGpioSpec(), value);
  mController->handleChangeEvent(this);
}

bool IOHandleGPIO::equal() {
  DEVLOG_DEBUG("IOHandleGPIO::equal\n");
  bool value = gpio_pin_get_dt(getGpioSpec());
  bool eq = (value == mLastValue);
  return eq;
}

void IOHandleGPIO::irq_callback(const struct device* dev, struct gpio_callback* cb, uint32_t pins) {
  DEVLOG_DEBUG("IOHandleGPIO::irq_callback\n");
  gpio_callback_context_t* ctx = CONTAINER_OF(cb, gpio_callback_context_t, gpio_cb_data);
  // Use this to notify IOHandle of asynchronous value changes, i.e. IRQs
  ctx->self->onChange();
}

