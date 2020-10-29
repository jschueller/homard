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
# Compilation de Gestion_MTU

SET(Gestion_MTU_SOURCES
    ./gagpmc.F
    ./gagpmf.F
    ./gasgmc.F
    ./gballo.F
    ./gbalme.F
    ./gbaloj.F
    ./gbcara.F
    ./gbdnoe.F
    ./gbdnof.F
    ./gbdtoj.F
    ./gbgeno.F
    ./gbitos.F
    ./gblboj.F
    ./gblibe.F
    ./gbminu.F
    ./gbntcr.F
    ./gbntde.F
    ./gbobal.F
    ./gbpart.F
    ./gbralo.F
    ./gmadoj.F
    ./gmalog.F
    ./gmaloi.F
    ./gmaloj.F
    ./gmalor.F
    ./gmalos.F
    ./gmalot.F
    ./gmatoj.F
    ./gmcata.F
    ./gmcmpr.F
    ./gmcpal.F
    ./gmcpgp.F
    ./gmcpoj.F
    ./gmdesa.F
    ./gmdesg.F
    ./gmdesi.F
    ./gmdesr.F
    ./gmdess.F
    ./gmdmp.F
    ./gmdmpg.F
    ./gmdmpi.F
    ./gmdmpr.F
    ./gmdmps.F
    ./gmdmpt.F
    ./gmdtoj.F
    ./gmecat.F
    ./gmecpr.F
    ./gmextg.F
    ./gminfo.F
    ./gminge.F
    ./gmitob.F
    ./gmlanm.F
    ./gmlboj.F
    ./gmliat.F
    ./gmmaxi.F
    ./gmmess.F
    ./gmmod.F
    ./gmmodg.F
    ./gmmodi.F
    ./gmmodr.F
    ./gmmods.F
    ./gmmoge.F
    ./gmnomc.F
    ./gmntve.F
    ./gmobal.F
    ./gmprot.F
    ./gmprsx.F
    ./gmsgoj.F
    ./gmshfi.F
    ./gmshfr.F
    ./gmshfs.F
    ./gmstat.F
    ./gmstop.F
    ./gmtyoj.F
    ./gtbila.F
    ./gtdems.F
    ./gtfims.F
    ./gtinfo.F
    ./gtinit.F
    ./gtlanm.F
    ./gtmess.F
    ./gtnoms.F
    ./gtstop.F
    ./gttabl.F
    ./gubila.F
    ./gucara.F
    ./guenst.F
    ./gufefi.F
    ./guferm.F
    ./gufeul.F
    ./gufiul.F
    ./guinfg.F
    ./guinfo.F
    ./guinfu.F
    ./guinit.F
    ./gulanm.F
    ./gumess.F
    ./gumoge.F
    ./guoufs.F
    ./guouge.F
    ./gurbbu.F
    ./gusost.F
    ./gustat.F
    ./gustop.F
    ./gutabl.F
    ./ugdhco.F
    ./ugdhfc.F
    ./ugdhlc.F
    ./ugfia3.F
    ./ugfino.F
    ./uginit.F
    ./uglanm.F
    ./ugstop.F
    ./ugtabl.F
    ./ugtac2.F
    ./ugtaci.F
    ./ugtacl.F
    ./ugtacr.F
    ./ugtacs.F
    )

INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/src/tool/Gestion_MTU ../Includes_Generaux)

SET ( CMAKE_Fortran_FLAGS "-ffixed-line-length-0 -fdefault-double-8 -fdefault-real-8 -fdefault-integer-8 -fimplicit-none -O2" )

ADD_LIBRARY (Gestion_MTU ${Gestion_MTU_SOURCES})

INSTALL(TARGETS Gestion_MTU EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})
