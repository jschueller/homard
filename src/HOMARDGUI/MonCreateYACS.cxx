// Copyright (C) 2011-2012  CEA/DEN, EDF R&D
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

#include "MonCreateYACS.h"

#include <QFileDialog>
#include <QMessageBox>

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include "HomardQtCommun.h"
#include <utilities.h>


// ----------------------------------------------------------------------
/* Constructs a MonCreateYACS
 * Sets attributes to default values
 */
// ----------------------------------------------------------------------
MonCreateYACS::MonCreateYACS (QWidget* parent, bool modal, HOMARD::HOMARD_Gen_var myHomardGen0, QString CaseName )
    :
    Ui_CreateYACS(),
    _aCaseName(CaseName),
    _aScriptFile(""),
    _aDirName(""),
    _aMeshFile("")
{
  MESSAGE("Debut du constructeur de MonCreateYACS");
  myHomardGen=HOMARD::HOMARD_Gen::_duplicate(myHomardGen0);
  setupUi(this);
  setModal(modal);

  InitConnect();

  SetNewName() ;

  if (_aCaseName != QString(""))
    { SetCaseName(); }
  else
    {setModal(false); /* permet selection du cas dans l arbre d etude */}

  adjustSize();
  MESSAGE("Fin du constructeur de MonCreateYACS");
}

// ----------------------------------------------------------------------
MonCreateYACS::MonCreateYACS(QWidget* parent,
                             HOMARD::HOMARD_Gen_var myHomardGen0,
                             QString caseName):
// ----------------------------------------------------------------------
// Constructeur appele par MonEditYACS
//
    myHomardGen(myHomardGen0),
    _Name (""),
    Chgt (false)
    {
  //  MESSAGE("Debut de  MonCreateYACS")
      setupUi(this) ;

      setModal(true) ;
      InitConnect() ;
    }

// ------------------------------------------------------------------------
MonCreateYACS::~MonCreateYACS()
// ------------------------------------------------------------------------
{
    // no need to delete child widgets, Qt does it all for us
}
// ------------------------------------------------------------------------
void MonCreateYACS::InitConnect()
// ------------------------------------------------------------------------
{
    connect( PBCaseName,     SIGNAL(pressed()), this, SLOT(SetCaseName()));
    connect( PushDir,        SIGNAL(pressed()), this, SLOT(SetDirName()));
    connect( PushFile,       SIGNAL(pressed()), this, SLOT(SetScriptFile()));
    connect( PushFile_2,     SIGNAL(pressed()), this, SLOT(SetMeshFile()));

    connect( RBStatic,       SIGNAL(clicked()), this, SLOT(SetType(1)));
    connect( RBTransient,    SIGNAL(clicked()), this, SLOT(SetType(2)));

    connect( buttonOk,       SIGNAL(pressed()), this, SLOT(PushOnOK()));
    connect( buttonApply,    SIGNAL(pressed()), this, SLOT(PushOnApply()));
    connect( buttonCancel,   SIGNAL(pressed()), this, SLOT(close()));
    connect( buttonHelp,     SIGNAL(pressed()), this, SLOT(PushOnHelp()));
}
// -------------------------------
bool MonCreateYACS::PushOnApply()
// --------------------------------
{
  MESSAGE("PushOnApply");

  if ( _aCaseName == QString (""))
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_CASE_NAME") );
    return false;
  }
// Le fichier du script
  QString aFileName=LEScriptFile->text().trimmed();
  if (aFileName ==QString(""))
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_SCRIPT_FILE") );
    return false;
  }

// Le repertoire de calcul
  QString aDirName=LEDirName->text().trimmed();
  if (aDirName == QString(""))
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_CASE_DIRECTORY_4") );
    return false;
  }
  if ((aDirName != _aDirName) and (myHomardGen->VerifieDir( aDirName.toStdString().c_str()) == false))
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_CASE_DIRECTORY_2") );
    return false;
  }
  if (chdir(aDirName.toStdString().c_str()) != 0)
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_CASE_DIRECTORY_3") );
    return false;
  }

// Le fichier du tout premier maillage
  aFileName=LEMeshFile->text().trimmed();
  if (aFileName ==QString(""))
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_CASE_MESH") );
    return false;
  }
  QString aMeshName = HOMARD_QT_COMMUN::LireNomMaillage(aFileName);
  if (aMeshName == "" )
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_MED_FILE_2") );
    return false;
  }

  HOMARD_UTILS::updateObjBrowser();
  MESSAGE ("_aCaseName.toStdString " << _aCaseName.toStdString() );

// Creation de l'objet CORBA
  try
  {
    _Name=LEName->text().trimmed();
    aYACS=myHomardGen->CreateYACSSchema(CORBA::string_dup(_Name.toStdString().c_str()), _aCaseName.toStdString().c_str(), _aScriptFile.toStdString().c_str(), _aDirName.toStdString().c_str(), _aMeshFile.toStdString().c_str());
//     _parent->AddYACS(_Name);
  }
  catch( SALOME::SALOME_Exception& S_ex )
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr(CORBA::string_dup(S_ex.details.text)) );
    return false;
  }

return true;
}
// ---------------------------
void MonCreateYACS::PushOnOK()
// ---------------------------
{
  bool bOK = PushOnApply();
  if ( bOK )  this->close();
}
//------------------------------
void MonCreateYACS::PushOnHelp()
//-------------------------------
{
  HOMARD_UTILS::PushOnHelp(QString("gui_create_case.html"), QString(""));
}
// -------------------------------------------------
void MonCreateYACS::SetNewName()
// --------------------------------------------------
{

  HOMARD::listeYACSs_var MyObjects = myHomardGen->GetAllYACSsName();
  int num = 0; QString aName="";
  while (aName == QString("") )
  {
    aName.setNum(num+1) ;
    aName.insert(0, QString("YACS_")) ;
    for ( int i=0; i<MyObjects->length(); i++)
    {
      if ( aName ==  QString(MyObjects[i]))
      {
          num=num+1;
          aName="";
          break;
      }
   }
  }
  LEName->setText(aName);
}
// ------------------------------------------------------------------------
void MonCreateYACS::SetCaseName()
// ------------------------------------------------------------------------
{
  MESSAGE ("SetCaseName avec _aCaseName = " << _aCaseName.toStdString() );
  if (_aCaseName == QString(""))
  {
    _aCaseName=HOMARD_QT_COMMUN::SelectionArbreEtude(QString("CasHomard"), 1);
    if (_aCaseName == QString("")) { raise();return;};
  }
/*  MESSAGE ("appel de GetCase avec _aCaseName = " << _aCaseName.toStdString() );*/
  aCase = myHomardGen->GetCase(_aCaseName.toStdString().c_str());
  LECaseName->setText(_aCaseName);
}
// ------------------------------------------------------------------------
void MonCreateYACS::SetDirName()
// ------------------------------------------------------------------------
{
  QString aDirName=QFileDialog::getExistingDirectory ();
  if (!(aDirName.isEmpty()))LEDirName->setText(aDirName);
}
// ------------------------------------------------------------------------
void MonCreateYACS::SetScriptFile()
// ------------------------------------------------------------------------
{
  QString fileName0 = LEScriptFile->text().trimmed();
  QString fileName = HOMARD_QT_COMMUN::PushNomFichier(false);
  if (fileName.isEmpty()) fileName = fileName0 ;
  LEScriptFile->setText(fileName);
}
// ------------------------------------------------------------------------
void MonCreateYACS::SetMeshFile()
// ------------------------------------------------------------------------
{
  QString fileName0 = LEMeshFile->text().trimmed();
  QString fileName = HOMARD_QT_COMMUN::PushNomFichier(false);
  if (fileName.isEmpty()) fileName = fileName0 ;
  LEMeshFile->setText(fileName);
}
// ------------------------------------------------------------------------
void MonCreateYACS::SetType(int Type)
// ------------------------------------------------------------------------
{
  _Type=Type;
}
