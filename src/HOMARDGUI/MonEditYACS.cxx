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

using namespace std;

#include "MonEditYACS.h"

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include "HomardQtCommun.h"
#include <utilities.h>


// -------------------------------------------------------------
/* Constructs a MonEditYACS
    herite de MonCreateYACS
*/
// -------------------------------------------------------------
MonEditYACS::MonEditYACS ( QWidget* parent, bool modal,
                           HOMARD::HOMARD_Gen_var myHomardGen,
                           QString Name ):
   MonCreateYACS(parent, modal, myHomardGen, Name)
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

  QString aCaseName = aYACS->GetCaseName();
  LECaseName->setText(aCaseName);
  LECaseName->setReadOnly(true);
  PushDir->setVisible(0);

  QString aScriptFile = aYACS->GetScriptFile();
  LEScriptFile->setText(aScriptFile);
  LEScriptFile->setReadOnly(true);
  PushDir->setVisible(0);

  QString aDirName = aYACS->GetDirName();
  LEDirName->setText(aDirName);
  LEDirName->setReadOnly(true);
  PushDir->setVisible(0);

  QString aMeshFile = aYACS->GetMeshFile();
  LEMeshFile->setText(aMeshFile);
  LEMeshFile->setReadOnly(true);
  PushDir->setVisible(0);

  int Type=aYACS->GetType();
  if(Type==1) { RBStatic->setChecked(true); }
  else        { RBTransient->setChecked(true); };
  RBStatic->setEnabled(false);
  RBTransient->setEnabled(false);
//
  adjustSize();
}

// -------------------------------------
bool MonEditYACS::PushOnApply()
// -------------------------------------
{
  return true ;
};
