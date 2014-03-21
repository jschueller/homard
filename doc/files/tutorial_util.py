# -*- coding: iso-8859-1 -*-
# Copyright (C) 2011-2014  CEA/DEN, EDF R&D
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
"""
Python script for HOMARD
Copyright EDF-R&D 2014
"""
__revision__ = "V1.0"

import os
import sys
#========================================================================
#========================================================================
def gzip_gunzip(data_dir, num_tuto, option) :
  """
Compression/Uncompression of the med files of a directory such as tutorial_x.nn.med
data_dir: directory
num_tuto: number of the tutorial
option  : 1: compression, -1: uncompression
Copyright EDF-R&D 2014
  """
#
  ficloc_basis = "tutorial_%d" % num_tuto
#
  ok = True
  num = -1
#
# Uncompression
#
  if ( option == -1 ) :
#
    while ok :
      num += 1
      ficloc = ficloc_basis + ".%02d.med" % num
      nomfic = os.path.join(data_dir, ficloc)
      if not os.path.isfile(nomfic) :
        ficloc += ".gz"
        nomfic = os.path.join(data_dir, ficloc)
        if os.path.isfile(nomfic) :
          os.system("gunzip "+nomfic)
        else :
          ok = False
          break
#
    ficloc = ficloc_basis + ".fr.med"
    nomfic = os.path.join(data_dir, ficloc)
    if not os.path.isfile(nomfic) :
      ficloc += ".gz"
      nomfic = os.path.join(data_dir, ficloc)
      if os.path.isfile(nomfic) :
        os.system("gunzip "+nomfic)
#
# Compression
#
  elif ( option == 1 ) :
#
    while ok :
      num += 1
      ficloc = ficloc_basis + ".%02d.med.gz" % num
      nomfic = os.path.join(data_dir, ficloc)
      if not os.path.isfile(nomfic) :
        ficloc = ficloc_basis + ".%02d.med" % num
        nomfic = os.path.join(data_dir, ficloc)
        if os.path.isfile(nomfic) :
          os.system("gzip "+nomfic)
        else :
          ok = False
          break
#
    ficloc = ficloc_basis + ".fr.med.gz"
    nomfic = os.path.join(data_dir, ficloc)
    if not os.path.isfile(nomfic) :
      ficloc = ficloc_basis + ".fr.med"
      nomfic = os.path.join(data_dir, ficloc)
      if os.path.isfile(nomfic) :
        os.system("gzip "+nomfic)
#
  return
#
#========================================================================
#========================================================================
