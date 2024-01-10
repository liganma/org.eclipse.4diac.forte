/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: HandleDescriptor
 *** Description: A Template for a Data Type
 *** Version:
 ***     1.0: 2024-01-08/kaar -  -
 *************************************************************************/

#include "HandleDescriptor_dtp.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "HandleDescriptor_dtp_gen.cpp"
#endif

#include "forte_byte.h"
#include "iec61131_functions.h"
#include "forte_array_common.h"
#include "forte_array.h"
#include "forte_array_fixed.h"
#include "forte_array_variable.h"

DEFINE_FIRMWARE_DATATYPE(HandleDescriptor, g_nStringIdHandleDescriptor);

const CStringDictionary::TStringId CIEC_HandleDescriptor::scmElementNames[] = {g_nStringIdDirection};

CIEC_HandleDescriptor::CIEC_HandleDescriptor() :
    CIEC_STRUCT(),
    var_Direction(0_BYTE) {
}

CIEC_HandleDescriptor::CIEC_HandleDescriptor(const CIEC_BYTE &paDirection) :
    CIEC_STRUCT(),
    var_Direction(paDirection) {
}

CStringDictionary::TStringId CIEC_HandleDescriptor::getStructTypeNameID() const {
  return g_nStringIdHandleDescriptor;
}

void CIEC_HandleDescriptor::setValue(const CIEC_ANY &paValue) {
  if (paValue.getDataTypeID() == e_STRUCT) {
    auto &otherStruct = static_cast<const CIEC_STRUCT &>(paValue);
    if (g_nStringIdHandleDescriptor == otherStruct.getStructTypeNameID()) {
      operator=(static_cast<const CIEC_HandleDescriptor &>(paValue));
    }
  }
}

CIEC_ANY *CIEC_HandleDescriptor::getMember(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Direction;
  }
  return nullptr;
}

const CIEC_ANY *CIEC_HandleDescriptor::getMember(const size_t paIndex) const {
  switch(paIndex) {
    case 0: return &var_Direction;
  }
  return nullptr;
}

