/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Trovis5578ez
 *** Description: Service Interface Function Block Type
 *** Version:
 ***     1.0: 2023-11-15/kaar -  -
 *************************************************************************/

#include "Trovis5578ez_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Trovis5578ez_fbt_gen.cpp"
#endif

#include "criticalregion.h"
#include "resource.h"

DEFINE_FIRMWARE_FB(FORTE_Trovis5578ez, g_nStringIdTrovis5578ez)

const CStringDictionary::TStringId FORTE_Trovis5578ez::scmDataInputNames[] = {g_nStringIdQI, g_nStringIdIN1, g_nStringIdOUT1, g_nStringIdOUT2, g_nStringIdUpdateInterval};
const CStringDictionary::TStringId FORTE_Trovis5578ez::scmDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdWSTRING, g_nStringIdWSTRING, g_nStringIdTIME};
const CStringDictionary::TStringId FORTE_Trovis5578ez::scmDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS};
const CStringDictionary::TStringId FORTE_Trovis5578ez::scmDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING};
const TDataIOID FORTE_Trovis5578ez::scmEIWith[] = {0, 1, scmWithListDelimiter};
const TForteInt16 FORTE_Trovis5578ez::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_Trovis5578ez::scmEventInputNames[] = {g_nStringIdINIT};
const TDataIOID FORTE_Trovis5578ez::scmEOWith[] = {0, 1, scmWithListDelimiter, 0, 1, scmWithListDelimiter};
const TForteInt16 FORTE_Trovis5578ez::scmEOWithIndexes[] = {0, 3};
const CStringDictionary::TStringId FORTE_Trovis5578ez::scmEventOutputNames[] = {g_nStringIdINITO, g_nStringIdIND};
const SFBInterfaceSpec FORTE_Trovis5578ez::scmFBInterfaceSpec = {
  1, scmEventInputNames, scmEIWith, scmEIWithIndexes,
  2, scmEventOutputNames, scmEOWith, scmEOWithIndexes,
  5, scmDataInputNames, scmDataInputTypeIds,
  2, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

FORTE_Trovis5578ez::FORTE_Trovis5578ez(const CStringDictionary::TStringId paInstanceNameId, CResource *const paSrcRes) :
    CFunctionBlock(paSrcRes, &scmFBInterfaceSpec, paInstanceNameId),
    var_conn_QO(var_QO),
    var_conn_STATUS(var_STATUS),
    conn_INITO(this, 0),
    conn_IND(this, 1),
    conn_QI(nullptr),
    conn_IN1(nullptr),
    conn_OUT1(nullptr),
    conn_OUT2(nullptr),
    conn_UpdateInterval(nullptr),
    conn_QO(this, 0, &var_conn_QO),
    conn_STATUS(this, 1, &var_conn_STATUS) {
};

void FORTE_Trovis5578ez::setInitialValues() {
  var_QI = 0_BOOL;
  var_IN1 = u""_WSTRING;
  var_OUT1 = u""_WSTRING;
  var_OUT2 = u""_WSTRING;
  var_UpdateInterval = 0_TIME;
  var_QO = 0_BOOL;
  var_STATUS = u""_WSTRING;
}

void FORTE_Trovis5578ez::deregister_handles() {
//  for (int i = 0; i < pin_cnt; i++) {
//    if (mRegistered[i] != nullptr) {
//      IOMapper::getInstance().deregisterHandle(*mRegistered[i]);
//    }
//  }
}

void FORTE_Trovis5578ez::register_handles() {
//  uint32_t base = st_PortInAdapter().GPIO_Port_Addr();
//  auto port = reinterpret_cast<GPIO_TypeDef *>(base);

//  for (int i = 0; i < pin_cnt; i++) {
//    auto id = static_cast<CIEC_WSTRING *>(getDI(i));

    // Only initialize pins that have an id.
//    if (id->empty())
//      continue;

//    mRegistered[i] = id;

    // Create a GPIO pin handle using the port struct to identify the MMIO port and
    // a bit mask to identify the pin.
//    EliteBoardDeviceController::EliteBoardHandleDescriptor descr(id->getValue(), port, 1 << i);
//    auto ctrl = getExtEvHandler<EliteBoardDeviceController>(*this);

//    IOMapper::getInstance().registerHandle(id->getValue(), ctrl.initHandle(&descr));
//  }
}

void FORTE_Trovis5578ez::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventINITID:
      deregister_handles();
      register_handles();

      sendAdapterEvent(0, scmEventINITOID, paECET);
      break;
  }
}

void FORTE_Trovis5578ez::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventINITID: {
      readData(0, var_QI, conn_QI);
      readData(1, var_IN1, conn_IN1);
      break;
    }
    default:
      break;
  }
}

void FORTE_Trovis5578ez::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventINITOID: {
      writeData(0, var_QO, conn_QO);
      writeData(1, var_STATUS, conn_STATUS);
      break;
    }
    case scmEventINDID: {
      writeData(0, var_QO, conn_QO);
      writeData(1, var_STATUS, conn_STATUS);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_Trovis5578ez::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_QI;
    case 1: return &var_IN1;
    case 2: return &var_OUT1;
    case 3: return &var_OUT2;
    case 4: return &var_UpdateInterval;
  }
  return nullptr;
}

CIEC_ANY *FORTE_Trovis5578ez::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_QO;
    case 1: return &var_STATUS;
  }
  return nullptr;
}

CEventConnection *FORTE_Trovis5578ez::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_INITO;
    case 1: return &conn_IND;
  }
  return nullptr;
}

CDataConnection **FORTE_Trovis5578ez::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_QI;
    case 1: return &conn_IN1;
    case 2: return &conn_OUT1;
    case 3: return &conn_OUT2;
    case 4: return &conn_UpdateInterval;
  }
  return nullptr;
}

CDataConnection *FORTE_Trovis5578ez::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_QO;
    case 1: return &conn_STATUS;
  }
  return nullptr;
}

