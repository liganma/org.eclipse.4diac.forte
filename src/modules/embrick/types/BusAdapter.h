/*******************************************************************************
 * Copyright (c) 2016 - 2018 Johannes Messmer (admin@jomess.com), fortiss GmbH
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *   Johannes Messmer - initial API and implementation and/or initial documentation
 *   Jose Cabral - Cleaning of namespaces
 *******************************************************************************/

#ifndef SRC_MODULES_EMBRICK_TYPES_BUSCONFIGADAPTER_H_
#define SRC_MODULES_EMBRICK_TYPES_BUSCONFIGADAPTER_H_

#include <io/configFB/io_adapter_multi.h>
#include <typelib.h>
#include <forte_bool.h>
#include <forte_uint.h>

class EBBusAdapter: public forte::core::io::IOConfigFBMultiAdapter {
DECLARE_ADAPTER_TYPE(EBBusAdapter)

private:
private:
  static const CStringDictionary::TStringId scmDataInputNames[];
  static const CStringDictionary::TStringId scmDataInputTypeIds[];

  static const CStringDictionary::TStringId scmDataOutputNames[];
  static const CStringDictionary::TStringId scmDataOutputTypeIds[];
public:

  CIEC_UINT &UpdateInterval() {
    return *static_cast<CIEC_UINT*>((isSocket()) ? getDO(3) : getDI(3));
  }

private:
  static const TForteInt16 scmEIWithIndexes[];
  static const TDataIOID scmEIWith[];
  static const CStringDictionary::TStringId scmEventInputNames[];

  static const TForteInt16 scmEOWithIndexes[];
  static const TDataIOID scmEOWith[];
  static const CStringDictionary::TStringId scmEventOutputNames[];

  static const SFBInterfaceSpec scmFBInterfaceSpecSocket;

  static const SFBInterfaceSpec scmFBInterfaceSpecPlug;

public:
  ADAPTER_CTOR_FOR_IO_MULTI(EBBusAdapter){
};

private:
  static const TForteUInt8 scmSlaveConfigurationIO[];
  static const TForteUInt8 scmSlaveConfigurationIONum;

  ~EBBusAdapter() override = default;

};

#endif //close the ifdef sequence from the beginning of the file

