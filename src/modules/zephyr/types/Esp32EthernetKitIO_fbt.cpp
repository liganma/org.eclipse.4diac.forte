/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Esp32EthernetKitIO
 *** Description: Template for Modular IO with Esp32EthernetKit board
 *** Version:
 ***     1.0: 2024-01-13/Dirk O. Kaar -  -
 *************************************************************************/

#include "Esp32EthernetKitIO_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Esp32EthernetKitIO_fbt_gen.cpp"
#endif

#include <handler/IOHandleGPIODescriptor.h>

DEFINE_FIRMWARE_FB(FORTE_Esp32EthernetKitIO, g_nStringIdEsp32EthernetKitIO)

const CStringDictionary::TStringId FORTE_Esp32EthernetKitIO::scmDataInputNames[] = {g_nStringIdQI, g_nStringIdLED0, g_nStringIdSW0, g_nStringIdUpdateInterval};
const CStringDictionary::TStringId FORTE_Esp32EthernetKitIO::scmDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdTIME};
const CStringDictionary::TStringId FORTE_Esp32EthernetKitIO::scmDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS};
const CStringDictionary::TStringId FORTE_Esp32EthernetKitIO::scmDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING};
const TDataIOID FORTE_Esp32EthernetKitIO::scmEIWith[] = {0, 3, 1, 2, scmWithListDelimiter};
const TForteInt16 FORTE_Esp32EthernetKitIO::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_Esp32EthernetKitIO::scmEventInputNames[] = {g_nStringIdINIT};
const TDataIOID FORTE_Esp32EthernetKitIO::scmEOWith[] = {0, 1, scmWithListDelimiter};
const TForteInt16 FORTE_Esp32EthernetKitIO::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_Esp32EthernetKitIO::scmEventOutputNames[] = {g_nStringIdINITO};
const SFBInterfaceSpec FORTE_Esp32EthernetKitIO::scmFBInterfaceSpec = {
  1, scmEventInputNames, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, scmEOWith, scmEOWithIndexes,
  4, scmDataInputNames, scmDataInputTypeIds,
  2, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

FORTE_Esp32EthernetKitIO::FORTE_Esp32EthernetKitIO(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    FORTE_ZephyrIOBase(paContainer, &scmFBInterfaceSpec, paInstanceNameId),
    var_UpdateInterval(40000000_TIME),
    var_conn_QO(var_QO),
    var_conn_STATUS(var_STATUS),
    conn_INITO(this, 0),
    conn_QI(nullptr),
    conn_LED0(nullptr),
    conn_SW0(nullptr),
    conn_UpdateInterval(nullptr),
    conn_QO(this, 0, &var_conn_QO),
    conn_STATUS(this, 1, &var_conn_STATUS) {
};

void FORTE_Esp32EthernetKitIO::setInitialValues() {
  var_QI = 0_BOOL;
  var_LED0 = ""_STRING;
  var_SW0 = ""_STRING;
  var_UpdateInterval = 40000000_TIME;
  var_QO = 0_BOOL;
  var_STATUS = ""_STRING;
}

void FORTE_Esp32EthernetKitIO::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventINITID: {
      readData(0, var_QI, conn_QI);
      readData(3, var_UpdateInterval, conn_UpdateInterval);
      readData(1, var_LED0, conn_LED0);
      readData(2, var_SW0, conn_SW0);
      break;
    }
    default:
      break;
  }
}

void FORTE_Esp32EthernetKitIO::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventINITOID: {
      writeData(0, var_QO, conn_QO);
      writeData(1, var_STATUS, conn_STATUS);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_Esp32EthernetKitIO::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_QI;
    case 1: return &var_LED0;
    case 2: return &var_SW0;
    case 3: return &var_UpdateInterval;
  }
  return nullptr;
}

CIEC_ANY *FORTE_Esp32EthernetKitIO::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_QO;
    case 1: return &var_STATUS;
  }
  return nullptr;
}

CEventConnection *FORTE_Esp32EthernetKitIO::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_INITO;
  }
  return nullptr;
}

CDataConnection **FORTE_Esp32EthernetKitIO::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_QI;
    case 1: return &conn_LED0;
    case 2: return &conn_SW0;
    case 3: return &conn_UpdateInterval;
  }
  return nullptr;
}

CDataConnection *FORTE_Esp32EthernetKitIO::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_QO;
    case 1: return &conn_STATUS;
  }
  return nullptr;
}

namespace {
  struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led0), gpios, {0});
  struct gpio_dt_spec sw0 = GPIO_DT_SPEC_GET_OR(DT_ALIAS(sw0), gpios, {0});
  struct gpio_spec_mod {
    gpio_dt_spec* spec;
    gpio_flags_t flags;
  };
  gpio_spec_mod gpio_spec_mods[] = {
    { &led0, GPIO_OUTPUT },
    { &sw0, GPIO_INPUT | GPIO_INT_EDGE_BOTH },
  };
};

void FORTE_Esp32EthernetKitIO::onStartup(CEventChainExecutionThread * const paECET) {
  // Initialize handles
  for (size_t i = 0; i < FORTE_Esp32EthernetKitIO::numberOfIOs; i++) {
    const auto id = std::string(*static_cast<CIEC_STRING*>(getDI(FORTE_ZephyrIOBase::initialDIOffset + i)));
    if (!gpio_spec_mods[i].spec) {
      DEVLOG_ERROR("FORTE_Esp32EthernetKitIO::onStartup: id %s, device spec is null\n", id.c_str());
      continue;
    }
    IOHandleGPIODescriptor descr(
      id,
      (gpio_spec_mods[i].flags & GPIO_OUTPUT) ? IOMapper::Out : IOMapper::In,
      gpio_spec_mods[i].spec,
      gpio_spec_mods[i].flags);
    initHandle(&descr);
  }

  FORTE_ZephyrIOBase::onStartup(paECET);
}

