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
 
IOHandleGPIO::IOHandleGPIO(IODeviceController *paDeviceCtrl, IOMapper::Direction paDirection) :
  IOHandle(paDeviceCtrl, paDirection, CIEC_ANY::e_BOOL) {}

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
  DEVLOG_INFO("IOHandleGPIO::get\n");
  static_cast<CIEC_BOOL &>(paState) = CIEC_BOOL(true);
}

void IOHandleGPIO::set(const CIEC_ANY &paState) {
  (void)paState;
  DEVLOG_INFO("IOHandleGPIO::set\n");
  mController->handleChangeEvent(this);
}

bool IOHandleGPIO::equal() {
  bool eq;
  CIEC_BOOL value;
  DEVLOG_INFO("IOHandleGPIO::equal\n");
  get(value);
  eq = (value == mLastValue);
  if (!eq) mLastValue.setValue(value);
  return eq;
}

// void forte::core::io::IOHandle::onChange()
// Use this to notify IOHandle of asynchronous value changes, i.e. IRQs
