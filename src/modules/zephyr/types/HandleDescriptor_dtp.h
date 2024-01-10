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

#pragma once

#include "forte_struct.h"

#include "forte_byte.h"
#include "iec61131_functions.h"
#include "forte_array_common.h"
#include "forte_array.h"
#include "forte_array_fixed.h"
#include "forte_array_variable.h"


class CIEC_HandleDescriptor final : public CIEC_STRUCT {
  DECLARE_FIRMWARE_DATATYPE(HandleDescriptor)

  public:
    CIEC_HandleDescriptor();

    CIEC_HandleDescriptor(const CIEC_BYTE &paDirection);

    CIEC_BYTE var_Direction;

    size_t getStructSize() const override {
      return 1;
    }

    const CStringDictionary::TStringId* elementNames() const override {
      return scmElementNames;
    }

    CStringDictionary::TStringId getStructTypeNameID() const override;

    void setValue(const CIEC_ANY &paValue) override;

    CIEC_ANY *getMember(size_t) override;
    const CIEC_ANY *getMember(size_t) const override;

  private:
    static const CStringDictionary::TStringId scmElementNames[];

};


