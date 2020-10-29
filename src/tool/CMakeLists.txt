# Copyright (C) 2016-2020  CEA/DEN, EDF R&D
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
cmake_minimum_required (VERSION 2.8)
PROJECT (Homard C Fortran)

SET(${PROJECT_NAME_UC}_VERSION_MAJOR 11)
SET(${PROJECT_NAME_UC}_VERSION_MINOR 99)
SET(${PROJECT_NAME_UC}_VERSION_PATCH 0)
SET(${PROJECT_NAME_UC}_VERSION ${${PROJECT_NAME_UC}_VERSION_MAJOR}.${${PROJECT_NAME_UC}_VERSION_MINOR}.${${PROJECT_NAME_UC}_VERSION_PATCH})

INCLUDE(FortranCInterface)
FortranCInterface_HEADER(${CMAKE_BINARY_DIR}/FC.h)

# libraries to build
SET(DIRLIBS
  HOMARD_00
  Suivi_Frontiere
  Information
  Modification
  AV_Conversion
  Decision
  Creation_Maillage
  AP_Conversion
  ES_Xfig
  ES_HOMARD
  ES_MED
  Utilitaire
  Gestion_MTU
  Dependance_Machine
 )

FOREACH(dir Includes_Generaux ${DIRLIBS})
        ADD_SUBDIRECTORY(${dir})
ENDFOREACH()

# libraries to link with
SET(_link_LIBRARIES
  ${MEDFILE_F_LIBRARIES}
  ${HDF5_LIBRARIES}
)

# Main binary
SET ( CMAKE_Fortran_FLAGS "-ffixed-line-length-0 -fdefault-double-8 -fdefault-real-8 -fdefault-integer-8 -fimplicit-none -O2" )

ADD_EXECUTABLE(homard.out homard.f)

TARGET_LINK_LIBRARIES(homard.out ${DIRLIBS} ${_link_LIBRARIES})

INSTALL(TARGETS homard.out EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_BINS})

