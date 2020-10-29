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
# Compilation de HOMARD_00

SET(HOMARD_00_SOURCES
    ./hoapcv.F
    ./hoapec.F
    ./hoapem.F
    ./hoapes.F
    ./hoapls.F
    ./hoavcv.F
    ./hoavec.F
    ./hoavli.F
    ./hoavlm.F
    ./hocmsa.F
    ./hocrma.F
    ./hodeci.F
    ./hoinco.F
    ./hoinit.F
    ./holect.F
    ./holopt.F
    ./holver.F
    ./homajc.F
    ./hoprin.F
    ./hostop.F
    ./hosufr.F
    )

INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/src/tool/HOMARD_00 ../Includes_Generaux)

SET ( CMAKE_Fortran_FLAGS "-ffixed-line-length-0 -fdefault-double-8 -fdefault-real-8 -fdefault-integer-8 -fimplicit-none -O2" )

ADD_LIBRARY (HOMARD_00 ${HOMARD_00_SOURCES})

INSTALL(TARGETS HOMARD_00 EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})
