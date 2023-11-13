#/************************************************************************************
# Copyright (c) 2023 KT Elektronik GmbH
# This program and the accompanying materials are made available under the
# terms of the Eclipse Public License 2.0 which is available at
# http://www.eclipse.org/legal/epl-2.0.
#
# SPDX-License-Identifier: EPL-2.0
#
# Contributors:
#  Dirk Kaar - initial API and implementation and/or initial documentation
# ************************************************************************************/
 
if("${FORTE_ARCHITECTURE}" STREQUAL "Zephyr")
forte_add_module(ZEPHYR OFF "I/O support for the Zephyr OS")

forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#######################################################
# ZEPHYR
#######################################################

forte_add_sourcefile_hcpp(processinterface)
forte_set_process_interface("Zephyr" IX QX)

endif("${FORTE_ARCHITECTURE}" STREQUAL "Zephyr")
