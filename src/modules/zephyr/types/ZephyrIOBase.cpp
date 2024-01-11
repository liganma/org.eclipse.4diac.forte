/************************************************************************************
 Copyright (c) 2024 KT Elektronik GmbH
 This program and the accompanying materials are made available under the
 terms of the Eclipse Public License 2.0 which is available at
 http://www.eclipse.org/legal/epl-2.0.

 SPDX-License-Identifier: EPL-2.0
 
 Contributors:
  Dirk Kaar - initial API and implementation and/or initial documentation
 ************************************************************************************/

#include "ZephyrIOBase.h"
#include "handler/IODeviceController.h"

FORTE_ZephyrIOBase::FORTE_ZephyrIOBase(forte::core::CFBContainer &paContainer, const SFBInterfaceSpec *paInterfaceSpec, const CStringDictionary::TStringId paInstanceNameId) :
    forte::core::io::IOConfigFBController(paContainer, paInterfaceSpec, paInstanceNameId) {
};

FORTE_ZephyrIOBase::~FORTE_ZephyrIOBase() {
  DEVLOG_INFO("FORTE_ZephyrIOBase dtor\n");
}

forte::core::io::IODeviceController* FORTE_ZephyrIOBase::createDeviceController(CDeviceExecution& paDeviceExecution) {
  return new IODeviceController(paDeviceExecution);
}

void FORTE_ZephyrIOBase::setConfig() {
  IODeviceController::Config config;
  config.updateInterval =
    static_cast<CIEC_TIME*>(getDI(FORTE_ZephyrIOBase::initialDIOffset + FORTE_ZephyrIOBase::numberOfIOs))->getInMilliSeconds();
  getDeviceController()->setConfig(&config);
}

void FORTE_ZephyrIOBase::onStartup(CEventChainExecutionThread * const paECET) {
/*
  // Initialize handles
  for (size_t i = 0; i < FORTE_ZephyrIOBase::numberOfIOs; i++) {
    std::string id = static_cast<CIEC_WSTRING*>(getDI(FORTE_ZephyrIOBase::initialDIOffset + i))->getValue();
    // do not use verbatim, only for reference to copy & paste in FBT instance class:
    IOHandleGPIODescriptor descr(id, IOMapper::Out);
    initHandle(&descr);
  }

  started(paECET);
*/
}
