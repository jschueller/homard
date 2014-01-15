// Copyright (C) 2011-2013  CEA/DEN, EDF R&D
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
//

#include "MonEditYACS.h"

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include "HomardQtCommun.h"
#include <utilities.h>

using namespace std;

// -------------------------------------------------------------
/* Constructs a MonEditYACS
    herite de MonCreateYACS
*/
// -------------------------------------------------------------
MonEditYACS::MonEditYACS ( bool modal,
                           HOMARD::HOMARD_Gen_var myHomardGen,
                           QString Name ):
   MonCreateYACS(myHomardGen, Name)
{
    MESSAGE("Debut de MonEditYACS" << Name.toStdString().c_str());
    setWindowTitle(QObject::tr("HOM_YACS_EDIT_WINDOW_TITLE"));
    _Name = Name;
    aYACS = myHomardGen->GetYACS(_Name.toStdString().c_str());
    InitValEdit();
}
// ------------------------------
MonEditYACS::~MonEditYACS()
// ------------------------------
{
}
// ------------------------------
void MonEditYACS::InitValEdit()
// ------------------------------
{
  MESSAGE("InitValEdit");
  LEName->setText(_Name);
  LEName->setReadOnly(true);

  QString _aCaseName = aYACS->GetCaseName();
  LECaseName->setText(_aCaseName);
  LECaseName->setReadOnly(true);
  PBCaseName->setVisible(0);

  QString aScriptFile = aYACS->GetScriptFile();
  LEScriptFile->setText(aScriptFile);

  QString aDirName = aYACS->GetDirName();
  LEDirName->setText(aDirName);

  QString aMeshFile = aYACS->GetMeshFile();
  LEMeshFile->setText(aMeshFile);

  int Type=aYACS->GetType();
  if(Type==1) { RBConstant->setChecked(true); }
  else        { RBVariable->setChecked(true); };
  RBConstant->setEnabled(false);
  RBVariable->setEnabled(false);
//
}

// ---------------------------------------------------
bool MonEditYACS:: CreateOrUpdate()
//----------------------------------------------------
//  Modification du schema
{
  MESSAGE("CreateOrUpdate");

  // Les donnees
  QString aScriptFile=LEScriptFile->text().trimmed();
  if ( aScriptFile != _aScriptFile )
  {
    _aScriptFile = aScriptFile ;
    aYACS->SetScriptFile(CORBA::string_dup(_aScriptFile.toStdString().c_str())) ;
  }
  QString aDirName=LEDirName->text().trimmed();
  if ( aDirName != _aDirName )
  {
    _aDirName = aDirName ;
    aYACS->SetDirName(CORBA::string_dup(_aDirName.toStdString().c_str())) ;
  }
  QString aMeshFile=LEMeshFile->text().trimmed();
  if ( aMeshFile != _aMeshFile )
  {
    _aMeshFile = aMeshFile ;
    aYACS->SetMeshFile(CORBA::string_dup(_aMeshFile.toStdString().c_str())) ;
  }

  return true ;
}
