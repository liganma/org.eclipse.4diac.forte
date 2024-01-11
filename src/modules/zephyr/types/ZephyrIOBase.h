/************************************************************************************
 Copyright (c) 2024 KT Elektronik GmbH
 This program and the accompanying materials are made available under the
 terms of the Eclipse Public License 2.0 which is available at
 http://www.eclipse.org/legal/epl-2.0.

 SPDX-License-Identifier: EPL-2.0
 
 Contributors:
  Dirk Kaar - initial API and implementation and/or initial documentation
 ************************************************************************************/

#pragma once

#include "funcbloc.h"
#include "forte_bool.h"
#include "forte_time.h"
#include "forte_wstring.h"
#include "iec61131_functions.h"
#include "forte_array_common.h"
#include "forte_array.h"
#include "forte_array_fixed.h"
#include "forte_array_variable.h"
#include "core/io/configFB/io_configFB_controller.h"
#include <extevhandlerhelper.h>

class FORTE_ZephyrIOBase : public forte::core::io::IOConfigFBController {

  protected:
    using IOHandle = forte::core::io::IOHandle;
    using IOMapper = forte::core::io::IOMapper;

    static constexpr size_t initialDIOffset = 1;

  private:
    static constexpr size_t numberOfIOs = 0;

    forte::core::io::IODeviceController* createDeviceController(CDeviceExecution& paDeviceExecution) override;
    void setConfig() override;
    void onStartup(CEventChainExecutionThread * const paECET) override;

  public:
    FORTE_ZephyrIOBase(forte::core::CFBContainer &paContainer, const SFBInterfaceSpec *paInterfaceSpec, const CStringDictionary::TStringId paInstanceNameId);
    ~FORTE_ZephyrIOBase() override;
};

