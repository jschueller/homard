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
# Compilation de Decision

SET(Decision_SOURCES
    ./deard0.F
    ./debil1.F
    ./debila.F
    ./decfs0.F
    ./decfs1.F
    ./decfs2.F
    ./decfs3.F
    ./decfsu.F
    ./decine.F
    ./decora.F
    ./decpt0.F
    ./decpte.F
    ./decr02.F
    ./decr03.F
    ./decr05.F
    ./dedco1.F
    ./dedco2.F
    ./dedcon.F
    ./dedera.F
    ./dedin1.F
    ./dedin2.F
    ./dedini.F
    ./deeli1.F
    ./deelig.F
    ./dehist.F
    ./dehmaj.F
    ./dehom1.F
    ./dehomo.F
    ./dehova.F
    ./dehovf.F
    ./deiard.F
    ./deiari.F
    ./deiarr.F
    ./deihed.F
    ./deihei.F
    ./deiher.F
    ./deinb1.F
    ./deinbi.F
    ./deinfi.F
    ./deini0.F
    ./deini2.F
    ./deini3.F
    ./deini4.F
    ./deini5.F
    ./deinii.F
    ./deinit.F
    ./deinnu.F
    ./deinod.F
    ./deinoi.F
    ./deinor.F
    ./deinri.F
    ./deinse.F
    ./deinst.F
    ./deinti.F
    ./deinun.F
    ./deinz0.F
    ./deinz1.F
    ./deinz2.F
    ./deinzr.F
    ./deiped.F
    ./deipei.F
    ./deiper.F
    ./deipyd.F
    ./deipyi.F
    ./deipyr.F
    ./deiqud.F
    ./deiqui.F
    ./deiqur.F
    ./deisa1.F
    ./deisa2.F
    ./deisau.F
    ./deisfa.F
    ./deisno.F
    ./deisv0.F
    ./deisv1.F
    ./deisv2.F
    ./deisv3.F
    ./deisv4.F
    ./deisv5.F
    ./deisv6.F
    ./deisv7.F
    ./deisv8.F
    ./deited.F
    ./deitei.F
    ./deiter.F
    ./deitrd.F
    ./deitri.F
    ./deitrr.F
    ./deiuc0.F
    ./deiucm.F
    ./delis1.F
    ./delist.F
    ./deraff.F
    ./derco1.F
    ./derco2.F
    ./derco3.F
    ./derco4.F
    ./derco5.F
    ./derco6.F
    ./derco7.F
    ./derco8.F
    ./derco9.F
    ./dercon.F
    ./desmaj.F
    )

INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/src/tool/Decision ../Includes_Generaux)

SET ( CMAKE_Fortran_FLAGS "-ffixed-line-length-0 -fdefault-double-8 -fdefault-real-8 -fdefault-integer-8 -fimplicit-none -O2" )

ADD_LIBRARY (Decision ${Decision_SOURCES})

INSTALL(TARGETS Decision EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})
