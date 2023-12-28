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

#include "ZephyrIO_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "ZephyrIO_fbt_gen.cpp"
#endif

#include <handle/PinHandle.h>

DEFINE_FIRMWARE_FB(FORTE_ZephyrIO, g_nStringIdZephyrIO)

const CStringDictionary::TStringId FORTE_ZephyrIO::scmDataInputNames[] = {g_nStringIdQI, g_nStringIdIN1, g_nStringIdOUT1, g_nStringIdOUT2, g_nStringIdUpdateInterval};
const CStringDictionary::TStringId FORTE_ZephyrIO::scmDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdWSTRING, g_nStringIdWSTRING, g_nStringIdTIME};
const CStringDictionary::TStringId FORTE_ZephyrIO::scmDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS};
const CStringDictionary::TStringId FORTE_ZephyrIO::scmDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING};
const TDataIOID FORTE_ZephyrIO::scmEIWith[] = {0, 1, 2, 3, 4, scmWithListDelimiter};
const TForteInt16 FORTE_ZephyrIO::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_ZephyrIO::scmEventInputNames[] = {g_nStringIdINIT};
const TDataIOID FORTE_ZephyrIO::scmEOWith[] = {0, 1, scmWithListDelimiter, 0, 1, scmWithListDelimiter};
const TForteInt16 FORTE_ZephyrIO::scmEOWithIndexes[] = {0, 3};
const CStringDictionary::TStringId FORTE_ZephyrIO::scmEventOutputNames[] = {g_nStringIdINITO, g_nStringIdIND};
const SFBInterfaceSpec FORTE_ZephyrIO::scmFBInterfaceSpec = {
  1, scmEventInputNames, scmEIWith, scmEIWithIndexes,
  2, scmEventOutputNames, scmEOWith, scmEOWithIndexes,
  5, scmDataInputNames, scmDataInputTypeIds,
  2, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

FORTE_ZephyrIO::FORTE_ZephyrIO(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    forte::core::io::IOConfigFBController(paContainer, &scmFBInterfaceSpec, paInstanceNameId),
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

FORTE_ZephyrIO::~FORTE_ZephyrIO() {
  DEVLOG_INFO("FORTE_ZephyrIO dtor\n");
}

void FORTE_ZephyrIO::setInitialValues() {
  var_QI = 0_BOOL;
  var_IN1 = u""_WSTRING;
  var_OUT1 = u""_WSTRING;
  var_OUT2 = u""_WSTRING;
  var_UpdateInterval = 0_TIME;
  var_QO = 0_BOOL;
  var_STATUS = u""_WSTRING;
}

void FORTE_ZephyrIO::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventINITID: {
      readData(0, var_QI, conn_QI);
      readData(1, var_IN1, conn_IN1);
      readData(2, var_OUT1, conn_OUT1);
      readData(3, var_OUT2, conn_OUT2);
      readData(4, var_UpdateInterval, conn_UpdateInterval);
      break;
    }
    default:
      break;
  }
}

void FORTE_ZephyrIO::writeOutputData(const TEventID paEIID) {
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

CIEC_ANY *FORTE_ZephyrIO::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_QI;
    case 1: return &var_IN1;
    case 2: return &var_OUT1;
    case 3: return &var_OUT2;
    case 4: return &var_UpdateInterval;
  }
  return nullptr;
}

CIEC_ANY *FORTE_ZephyrIO::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_QO;
    case 1: return &var_STATUS;
  }
  return nullptr;
}

CEventConnection *FORTE_ZephyrIO::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_INITO;
    case 1: return &conn_IND;
  }
  return nullptr;
}

CDataConnection **FORTE_ZephyrIO::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_QI;
    case 1: return &conn_IN1;
    case 2: return &conn_OUT1;
    case 3: return &conn_OUT2;
    case 4: return &conn_UpdateInterval;
  }
  return nullptr;
}

CDataConnection *FORTE_ZephyrIO::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_QO;
    case 1: return &conn_STATUS;
  }
  return nullptr;
}

forte::core::io::IODeviceController* FORTE_ZephyrIO::createDeviceController(CDeviceExecution& paDeviceExecution) {
  return new ZephyrIODeviceController(paDeviceExecution);
}

void FORTE_ZephyrIO::setConfig() {
  ZephyrIODeviceController::Config config;
  config.updateInterval = var_UpdateInterval.getInMilliSeconds();
  getDeviceController()->setConfig(&config);
}

void FORTE_ZephyrIO::onStartup(CEventChainExecutionThread * const paECET) {
  // Initialize handles
  size_t initialDIOffset = 1;
  size_t numberOfInputs = 1;
  size_t numberOfOutputs = 2;

  for (size_t i = 0; i < numberOfInputs; i++) {
    std::string id = static_cast<CIEC_WSTRING*>(getDI(initialDIOffset + i))->getValue();

    ZephyrIODeviceController::ZephyrIOHandleDescriptor descr(
      id, forte::core::io::IOMapper::In, ZephyrIODeviceController::Bit);

    initHandle(&descr);
  }
  for (size_t i = 0; i < numberOfOutputs; i++) {
    std::string id = static_cast<CIEC_WSTRING*>(getDI(initialDIOffset + numberOfInputs + i))->getValue();

    ZephyrIODeviceController::ZephyrIOHandleDescriptor descr(
      id, forte::core::io::IOMapper::Out, ZephyrIODeviceController::Bit);

    initHandle(&descr);
  }

  started(paECET);
}

