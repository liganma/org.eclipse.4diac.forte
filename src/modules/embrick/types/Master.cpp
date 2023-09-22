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

#include "Master.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Master_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(EmbrickMaster, g_nStringIdEBMaster)

const CStringDictionary::TStringId EmbrickMaster::scmDataInputNames[] = {
    g_nStringIdQI, g_nStringIdBusInterface, g_nStringIdBusSelectPin,
    g_nStringIdBusInitSpeed, g_nStringIdBusLoopSpeed,
    g_nStringIdSlaveUpdateInterval };

const CStringDictionary::TStringId EmbrickMaster::scmDataInputTypeIds[] = {
    g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUDINT,
    g_nStringIdUDINT, g_nStringIdUINT };

const CStringDictionary::TStringId EmbrickMaster::scmDataOutputNames[] = {
    g_nStringIdQO, g_nStringIdSTATUS };

const CStringDictionary::TStringId EmbrickMaster::scmDataOutputTypeIds[] = {
    g_nStringIdBOOL, g_nStringIdWSTRING };

const TForteInt16 EmbrickMaster::scmEIWithIndexes[] = { 0 };
const TDataIOID EmbrickMaster::scmEIWith[] = { 0, 3, 5, 4, 1, 2, scmWithListDelimiter };
const CStringDictionary::TStringId EmbrickMaster::scmEventInputNames[] = {
    g_nStringIdINIT };

const TDataIOID EmbrickMaster::scmEOWith[] = { 0, 1, scmWithListDelimiter, 0, 1, scmWithListDelimiter };
const TForteInt16 EmbrickMaster::scmEOWithIndexes[] = { 0, 3, -1 };
const CStringDictionary::TStringId EmbrickMaster::scmEventOutputNames[] = {
    g_nStringIdINITO, g_nStringIdIND };

const SAdapterInstanceDef EmbrickMaster::scmAdapterInstances[] = { {
    g_nStringIdEBBusAdapter, g_nStringIdBusAdapterOut, true } };

const SFBInterfaceSpec EmbrickMaster::scmFBInterfaceSpec = { 1,
    scmEventInputNames, scmEIWith, scmEIWithIndexes, 2,
    scmEventOutputNames, scmEOWith, scmEOWithIndexes, 6,
    scmDataInputNames, scmDataInputTypeIds,
    2, scmDataOutputNames, scmDataOutputTypeIds,
    0, nullptr,
    1, scmAdapterInstances };

void EmbrickMaster::setInitialValues() {
  BusInterface() = 1_UINT;
  BusSelectPin() = 49_UINT;
  BusInitSpeed() = 300000_UDINT;
  BusLoopSpeed() = 700000_UDINT;
  SlaveUpdateInterval() = 25_UINT;
}


forte::core::io::IODeviceController* EmbrickMaster::createDeviceController(CDeviceExecution& paDeviceExecution) {
  return new EmbrickBusHandler(paDeviceExecution);
}

void EmbrickMaster::setConfig() {
  EmbrickBusHandler::Config config;
  config.mBusInterface = BusInterface().operator TForteUInt16();
  config.mBusSelectPin = BusSelectPin().operator TForteUInt16();
  config.mBusInitSpeed = BusInitSpeed().operator TForteUInt32();
  config.mBusLoopSpeed = BusLoopSpeed().operator TForteUInt32();
  getDeviceController()->setConfig(&config);
}

void EmbrickMaster::onStartup() {
  BusAdapterOut().UpdateInterval() = SlaveUpdateInterval();

  forte::core::io::IOConfigFBMultiMaster::onStartup();
}


