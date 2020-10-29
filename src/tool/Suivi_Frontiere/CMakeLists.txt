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
# Compilation de Suivi_Frontiere

SET(Suivi_Frontiere_SOURCES
    ./sfbatr.F
    ./sfbatt.F
    ./sfcaf1.F
    ./sfcaf2.F
    ./sfcafr.F
    ./sfcoaq.F
    ./sfcofa.F
    ./sfcoi1.F
    ./sfcoin.F
    ./sfcon1.F
    ./sfcona.F
    ./sfconq.F
    ./sfconv.F
    ./sfcot1.F
    ./sfcot2.F
    ./sfcotl.F
    ./sfcovo.F
    ./sfctri.F
    ./sfcvco.F
    ./sfcvgf.F
    ./sfdefg.F
    ./sffa01.F
    ./sffa02.F
    ./sffa03.F
    ./sffa05.F
    ./sffaf1.F
    ./sffaf2.F
    ./sffaf3.F
    ./sffaff.F
    ./sfgrf0.F
    ./sfgrf1.F
    ./sfgrf2.F
    ./sfgrf3.F
    ./sfgrfa.F
    ./sfgrfb.F
    ./sfgrou.F
    ./sfindr.F
    ./sflgeo.F
    ./sflise.F
    ./sfliso.F
    ./sfmop2.F
    ./sfnnfl.F
    ./sfnofl.F
    ./sfnuli.F
    ./sfpop2.F
    ./sfprep.F
    ./sfseno.F
    ./sfslin.F
    ./sftqqu.F
    ./sftqtr.F
    )

INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/src/tool/Suivi_Frontiere ../Includes_Generaux)

SET ( CMAKE_Fortran_FLAGS "-ffixed-line-length-0 -fdefault-double-8 -fdefault-real-8 -fdefault-integer-8 -fimplicit-none -O2" )

ADD_LIBRARY (Suivi_Frontiere ${Suivi_Frontiere_SOURCES})

INSTALL(TARGETS Suivi_Frontiere EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})
