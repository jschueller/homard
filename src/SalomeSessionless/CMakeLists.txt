# Copyright (C) 2021  CEA/DEN, EDF R&D, OPEN CASCADE
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
# See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
#

include(${SWIG_USE_FILE})

include_directories(
  ${KERNEL_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/src/HOMARD_I
  ${PROJECT_SOURCE_DIR}/src/HOMARD
  ${PROJECT_SOURCE_DIR}/src/FrontTrack
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PROJECT_BINARY_DIR}/idl
)

SET(_bin_SCRIPTS HOMARD_SalomeSessionless.py )

SALOME_INSTALL_SCRIPTS("${_bin_SCRIPTS}" ${SALOME_INSTALL_PYTHON} DEF_PERMS)

SET(HOMARDHelper_HEADERS HOMARDHelper.h HOMARDHelper.i)
SET(HOMARDHelper_SOURCES HOMARDHelper.cxx ${HOMARDHelper_HEADERS})
SET_SOURCE_FILES_PROPERTIES(HOMARDHelper.i PROPERTIES CPLUSPLUS ON)
SET_SOURCE_FILES_PROPERTIES(HOMARDHelper.i PROPERTIES SWIG_FLAGS "-py3")
SET_SOURCE_FILES_PROPERTIES(HOMARDHelper_wrap.cpp PROPERTIES COMPILE_FLAGS "-DHAVE_CONFIG_H")
SET(_swig_SCRIPTS ${CMAKE_CURRENT_BINARY_DIR}/HOMARDHelper.py )
IF(${CMAKE_VERSION} VERSION_LESS "3.8.0") 
  SWIG_ADD_MODULE(HOMARDHelper python ${HOMARDHelper_SOURCES})
ELSE()
  SWIG_ADD_LIBRARY(HOMARDHelper LANGUAGE python SOURCES ${HOMARDHelper_SOURCES})
ENDIF()
SWIG_LINK_LIBRARIES(HOMARDHelper ${PYTHON_LIBRARIES} ${PLATFORM_LIBS} HOMARDEngine )
install(TARGETS _HOMARDHelper DESTINATION ${SALOME_INSTALL_LIBS})
install(FILES ${HOMARDHelper_HEADERS} DESTINATION ${SALOME_INSTALL_HEADERS})
SALOME_INSTALL_SCRIPTS("${_swig_SCRIPTS}"  ${SALOME_INSTALL_BINS} EXTRA_DPYS "${SWIG_MODULE_HOMARDHelper_REAL_NAME}")
