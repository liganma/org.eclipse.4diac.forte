#############################################################################
# Copyright (c) 2023 KT Elektronik GmbH
# This program and the accompanying materials are made available under the
# terms of the Eclipse Public License 2.0 which is available at
# http://www.eclipse.org/legal/epl-2.0.
#
# SPDX-License-Identifier: EPL-2.0
# 
# Contributors:
#  Dirk Kaar - initial API and implementation and/or initial documentation
#############################################################################

if ("${FORTE_ARCHITECTURE}" STREQUAL "Zephyr")
forte_add_io(ZEPHYR "Support for the Zephyr OS")

if(FORTE_IO_ZEPHYR)

forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#############################################################################
# Zephyr FBs
#############################################################################

add_subdirectory(handler)
forte_add_sourcefile_hcpp(handle/PinHandle)
forte_add_sourcefile_hcpp(types/ZephyrIO_fbt)
forte_add_sourcefile_hcpp(types/io/zephyr/HandleDescriptor_dtp)

endif(FORTE_IO_ZEPHYR)
endif("${FORTE_ARCHITECTURE}" STREQUAL "Zephyr")
