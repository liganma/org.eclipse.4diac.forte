/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: ZephyrIO
 *** Description: Service Interface Function Block Type
 *** Version:
 ***     1.0: 2023-11-15/kaar -  -
 *************************************************************************/

#pragma once

#include "funcbloc.h"
#include "forte_bool.h"
#include "forte_wstring.h"
#include "HandleDescriptor_dtp.h"
#include "forte_time.h"
#include "iec61131_functions.h"
#include "forte_array_common.h"
#include "forte_array.h"
#include "forte_array_fixed.h"
#include "forte_array_variable.h"
#include "core/io/configFB/io_configFB_controller.h"
#include <extevhandlerhelper.h>
#include "handler/ZephyrIODeviceController.h"


class FORTE_ZephyrIO final : public forte::core::io::IOConfigFBController {
  DECLARE_FIRMWARE_FB(FORTE_ZephyrIO)

  using IOHandle = forte::core::io::IOHandle;
  using IOMapper = forte::core::io::IOMapper;

  private:
    static const CStringDictionary::TStringId scmDataInputNames[];
    static const CStringDictionary::TStringId scmDataInputTypeIds[];
    static const CStringDictionary::TStringId scmDataOutputNames[];
    static const CStringDictionary::TStringId scmDataOutputTypeIds[];
    static const TEventID scmEventINITID = 0;
    static const TDataIOID scmEIWith[];
    static const TForteInt16 scmEIWithIndexes[];
    static const CStringDictionary::TStringId scmEventInputNames[];
    static const TEventID scmEventINITOID = 0;
    static const TEventID scmEventINDID = 1;
    static const TDataIOID scmEOWith[];
    static const TForteInt16 scmEOWithIndexes[];
    static const CStringDictionary::TStringId scmEventOutputNames[];

    static const SFBInterfaceSpec scmFBInterfaceSpec;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

    forte::core::io::IODeviceController* createDeviceController(CDeviceExecution& paDeviceExecution) override;
    void setConfig() override;
    void onStartup(CEventChainExecutionThread * const paECET) override;

  public:
    FORTE_ZephyrIO(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);
    ~FORTE_ZephyrIO() override;

    CIEC_BOOL var_QI;
    CIEC_WSTRING var_gpio4_3;
    CIEC_WSTRING var_gpio4_7;
    CIEC_HandleDescriptor var_desc_gpio4_3;
    CIEC_HandleDescriptor var_desc_gpio4_7;
    CIEC_TIME var_UpdateInterval;

    CIEC_BOOL var_QO;
    CIEC_WSTRING var_STATUS;

    CIEC_BOOL var_conn_QO;
    CIEC_WSTRING var_conn_STATUS;

    CEventConnection conn_INITO;
    CEventConnection conn_IND;

    CDataConnection *conn_QI;
    CDataConnection *conn_gpio4_3;
    CDataConnection *conn_gpio4_7;
    CDataConnection *conn_desc_gpio4_3;
    CDataConnection *conn_desc_gpio4_7;
    CDataConnection *conn_UpdateInterval;

    CDataConnection conn_QO;
    CDataConnection conn_STATUS;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_INIT(const CIEC_BOOL &paQI, const CIEC_WSTRING &pagpio4_3, const CIEC_WSTRING &pagpio4_7, const CIEC_HandleDescriptor &padesc_gpio4_3, const CIEC_HandleDescriptor &padesc_gpio4_7, const CIEC_TIME &paUpdateInterval, CIEC_BOOL &paQO, CIEC_WSTRING &paSTATUS) {
      var_QI = paQI;
      var_gpio4_3 = pagpio4_3;
      var_gpio4_7 = pagpio4_7;
      var_desc_gpio4_3 = padesc_gpio4_3;
      var_desc_gpio4_7 = padesc_gpio4_7;
      var_UpdateInterval = paUpdateInterval;
      executeEvent(scmEventINITID, nullptr);
      paQO = var_QO;
      paSTATUS = var_STATUS;
    }

    void operator()(const CIEC_BOOL &paQI, const CIEC_WSTRING &pagpio4_3, const CIEC_WSTRING &pagpio4_7, const CIEC_HandleDescriptor &padesc_gpio4_3, const CIEC_HandleDescriptor &padesc_gpio4_7, const CIEC_TIME &paUpdateInterval, CIEC_BOOL &paQO, CIEC_WSTRING &paSTATUS) {
      evt_INIT(paQI, pagpio4_3, pagpio4_7, padesc_gpio4_3, padesc_gpio4_7, paUpdateInterval, paQO, paSTATUS);
    }
};


