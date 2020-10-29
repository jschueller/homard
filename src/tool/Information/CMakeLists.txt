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
# Compilation de Information

SET(Information_SOURCES
    ./inconv.F
    ./infami.F
    ./infc00.F
    ./infc01.F
    ./infc02.F
    ./infc03.F
    ./infc32.F
    ./infc33.F
    ./infc34.F
    ./infc35.F
    ./infc36.F
    ./infc37.F
    ./infca1.F
    ./infca2.F
    ./infcas.F
    ./infcom.F
    ./inffre.F
    ./infoar.F
    ./infofo.F
    ./infohe.F
    ./infomp.F
    ./infono.F
    ./infope.F
    ./infopf.F
    ./infopy.F
    ./infoqu.F
    ./infote.F
    ./infotr.F
    ./infova.F
    ./infovi.F
    ./infovo.F
    ./infqen.F
    ./infve0.F
    ./infve1.F
    ./infve2.F
    ./infve3.F
    ./infve4.F
    ./infve5.F
    ./infve6.F
    ./infve7.F
    ./infvec.F
    ./ininfm.F
    ./initer.F
    ./inqur1.F
    ./inqur2.F
    ./inqure.F
    )

INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/src/tool/Information ../Includes_Generaux)

SET ( CMAKE_Fortran_FLAGS "-ffixed-line-length-0 -fdefault-double-8 -fdefault-real-8 -fdefault-integer-8 -fimplicit-none -O2" )

ADD_LIBRARY (Information ${Information_SOURCES})

INSTALL(TARGETS Information EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})
