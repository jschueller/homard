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
# Compilation de ES_MED

SET(ES_MED_SOURCES
    ./esdesc.F
    ./esech1.F
    ./esech2.F
    ./esech3.F
    ./esemm0.F
    ./esemm1.F
    ./esemmb.F
    ./esemmc.F
    ./esemmd.F
    ./esemmf.F
    ./esemmq.F
    ./esemno.F
    ./eses11.F
    ./esesm1.F
    ./esesmd.F
    ./eslch1.F
    ./eslch2.F
    ./eslch3.F
    ./eslch4.F
    ./eslch5.F
    ./eslch6.F
    ./eslch7.F
    ./eslch8.F
    ./eslent.F
    ./eslimd.F
    ./eslmm1.F
    ./eslmm2.F
    ./eslmmb.F
    ./eslmmc.F
    ./eslmmd.F
    ./eslmmf.F
    ./eslmmn.F
    ./eslmno.F
    ./eslnma.F
    ./eslnof.F
    ./eslnom.F
    ./eslnum.F
    ./eslpg1.F
    ./eslpg2.F
    ./eslpr1.F
    ./eslsc1.F
    ./eslsch.F
    ./eslsm0.F
    ./eslsm1.F
    ./eslsm2.F
    ./eslsm3.F
    ./eslsm4.F
    ./eslsm5.F
    ./eslsmd.F
    ./esouvl.F
    ./esveri.F
    )

INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/src/tool/ES_MED ../Includes_Generaux)

SET ( CMAKE_Fortran_FLAGS "-ffixed-line-length-0 -fdefault-double-8 -fdefault-real-8 -fdefault-integer-8 -fimplicit-none -O2" )

ADD_LIBRARY (ES_MED ${ES_MED_SOURCES})

INSTALL(TARGETS ES_MED EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})
