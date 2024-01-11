/************************************************************************************
 Copyright (c) 2024 KT Elektronik GmbH
 This program and the accompanying materials are made available under the
 terms of the Eclipse Public License 2.0 which is available at
 http://www.eclipse.org/legal/epl-2.0.

 SPDX-License-Identifier: EPL-2.0
 
 Contributors:
  Dirk Kaar - initial API and implementation and/or initial documentation
 ************************************************************************************/

#ifndef IOHANDLEGPIODESCRIPTOR_H
#define IOHANDLEGPIODESCRIPTOR_H

#include <handler/IOHandleDescriptor.h>

class IOHandleGPIODescriptor : public IOHandleDescriptor {
public:
  IOHandleGPIODescriptor(std::string const &paId, forte::core::io::IOMapper::Direction paDirection) :
    IOHandleDescriptor(paId, paDirection, Gpio) {}
};

#endif // IOHANDLEGPIODESCRIPTOR_H
