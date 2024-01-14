/************************************************************************************
 Copyright (c) 2024 KT Elektronik GmbH
 This program and the accompanying materials are made available under the
 terms of the Eclipse Public License 2.0 which is available at
 http://www.eclipse.org/legal/epl-2.0.

 SPDX-License-Identifier: EPL-2.0
 
 Contributors:
  Dirk Kaar - initial API and implementation and/or initial documentation
 ************************************************************************************/

#ifndef IOHANDLEGPIO_H
#define IOHANDLEGPIO_H

#include <core/io/mapper/io_observer.h>
#include <handler/IODeviceController.h>
#include <handler/IOHandleGPIODescriptor.h>
#include <stdint.h>

class IODeviceController;

class IOHandleGPIO : public forte::core::io::IOHandle {
  using IOObserver = forte::core::io::IOObserver;
  using IOHandle = forte::core::io::IOHandle;
  using IOMapper = forte::core::io::IOMapper;

public:
  IOHandleGPIO(IODeviceController *paDeviceCtrl, IOMapper::Direction paDirection,
    gpio_dt_spec* paGpioSpec, gpio_flags_t paFlags);
  ~IOHandleGPIO() override;
  void get(CIEC_ANY &) override;
  void set(const CIEC_ANY &) override;
  bool equal();

protected:
  void onObserver(IOObserver *paObserver) override;
  void dropObserver() override;
  gpio_dt_spec* getGpioSpec() const { return mGpioSpec; }

private:
  static void irq_callback(const struct device* dev, struct gpio_callback* cb, uint32_t pins);

  gpio_dt_spec* mGpioSpec;
  struct gpio_callback_context_t {
    struct gpio_callback gpio_cb_data;
    IOHandleGPIO* self;
  };
  gpio_callback_context_t mGpioCallbackCtx;
  bool mLastValue;
};

#endif // IOHANDLEGPIO_H

