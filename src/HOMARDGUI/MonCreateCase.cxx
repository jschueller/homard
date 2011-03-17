using namespace std;

#include "MonCreateCase.h"
#include "MonCreateBoundaryDi.h"
#include "MonEditBoundaryDi.h"

#include <QFileDialog>
#include <QMessageBox>

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include "HomardQtCommun.h"
#include <utilities.h>


// -----------------------------------------------------------------------------------------
MonCreateCase::MonCreateCase(QWidget* parent, bool modal, HOMARD::HOMARD_Gen_var myHomardGen)
// -----------------------------------------------------------------------------------------
/* Constructs a MonCreateCase
 * Inherits from CasHomard
 * Sets attributes to default values
 */
    :
    Ui_CreateCase(), 
    _aCaseName(""),_aDirName(""), _ConfType(1)
    {
      _myHomardGen=HOMARD::HOMARD_Gen::_duplicate(myHomardGen);
      setupUi(this);
      setModal(modal);
      InitConnect();

      SetNewCaseName() ;
      GBBoundaryA->setVisible(0);
      GBBoundaryD->setVisible(0);
      GBTypeNoConf->setVisible(0);
      adjustSize();
      GetBoundarys();

    }

// ------------------------------------------------------------------------
MonCreateCase::~MonCreateCase()
// ------------------------------------------------------------------------
{
    // no need to delete child widgets, Qt does it all for us
}
// ------------------------------------------------------------------------
void MonCreateCase::InitConnect()
// ------------------------------------------------------------------------
{
    connect( PushDir,        SIGNAL(pressed()), this, SLOT(SetDirName()));
    connect( PushFichier,    SIGNAL(pressed()), this, SLOT(SetFileName()));

    connect( RBConforme,     SIGNAL(clicked()), this, SLOT(SetConforme()));
    connect( RBNonConforme,  SIGNAL(clicked()), this, SLOT(SetNonConforme()));
    connect( RB1NpM,         SIGNAL(clicked()), this, SLOT(Set1NpM()));
    connect( RB1NpA,         SIGNAL(clicked()), this, SLOT(Set1NpA()));
    connect( RBQuelconque,   SIGNAL(clicked()), this, SLOT(SetQuelconque()));

    connect( CBBoundaryD,      SIGNAL(stateChanged(int)), this, SLOT(SetBoundaryD()));
    connect( PBBoundaryDiNew,  SIGNAL(pressed()), this, SLOT(PushBoundaryDiNew()));
    connect( PBBoundaryDiEdit, SIGNAL(pressed()), this, SLOT(PushBoundaryDiEdit()) );
    connect( CBBoundaryA,      SIGNAL(stateChanged(int)), this, SLOT(SetBoundaryA()));

    connect( buttonOk,       SIGNAL(pressed()), this, SLOT(PushOnOK()));
    connect( buttonApply,    SIGNAL(pressed()), this, SLOT(PushOnApply()));
    connect( buttonCancel,   SIGNAL(pressed()), this, SLOT(close()));
    connect( buttonHelp,     SIGNAL(pressed()), this, SLOT(PushOnHelp()));
    connect( LECaseName,     SIGNAL(textChanged(QString)), this, SLOT(CaseNameChanged()));
}
// ------------------------------------------------------------------------
void MonCreateCase::GetBoundarys()
// ------------------------------------------------------------------------
{
     HOMARD::HOMARD_Boundary_var myBoundary ;
     HOMARD::listeBoundarys_var  mesBoundarys = _myHomardGen->GetAllBoundarys();
     for (int i=0; i<mesBoundarys->length(); i++)
     {
         myBoundary = _myHomardGen->GetBoundary(mesBoundarys[i]);
         int type_obj = myBoundary->GetBoundaryType() ;
         if ( type_obj==0 ) { CBBoundaryDi->addItem(QString(mesBoundarys[i])); }
     }
}

// -------------------------------
bool MonCreateCase::PushOnApply()
// --------------------------------
{
  MESSAGE("PushOnApply");
  QString aCaseName=LECaseName->text().trimmed();
  if ( aCaseName == "" )
  {
    QMessageBox::information( 0, "Error",
            QString("The case must be named"),
            QMessageBox::Ok + QMessageBox::Default );
    return false;
  }

  QString aDirName=LEDirName->text().trimmed();
  if (aDirName == QString(""))
  {
    QMessageBox::information( 0, "Error",
              QString("A directory for the case must be selected."),
              QMessageBox::Ok + QMessageBox::Default );
    return false;
  }
  if ((aDirName != _aDirName) and (_myHomardGen->VerifieDir( aDirName.toStdString().c_str()) == false))
  {
    QMessageBox::information( 0, "Error",
              QString("This directory is already used"),
              QMessageBox::Ok + QMessageBox::Default );
    return false;
  }
  if (chdir(aDirName.toStdString().c_str()) != 0)
  {
    QMessageBox::information( 0, "Error",
              QString("A valid directory for the case must be selected."),
              QMessageBox::Ok + QMessageBox::Default );
    return false;
  }

  QString aFileName=LEFileName->text().trimmed();
  if (aFileName ==QString(""))
  {
    QMessageBox::information( 0, "Error",
              QString("The initial mesh must be selected."),
              QMessageBox::Ok + QMessageBox::Default );
    return false;
  }

  QString aMeshName = HOMARD_QT_COMMUN::LireNomMaillage(aFileName);
  if (aMeshName == "" )
  {
    QMessageBox::information( 0, "Error",
              QString("no mesh in mesh file"),
              QMessageBox::Ok + QMessageBox::Default );
    return false;
  }

  if (aCaseName != _aCaseName )
  {
    _aCaseName = aCaseName;
    try
    {
    aCase = _myHomardGen->CreateCase( \
            CORBA::string_dup(_aCaseName.toStdString().c_str()),  \
            CORBA::string_dup(aMeshName.toStdString().c_str()),  \
            CORBA::string_dup(aFileName.toStdString().c_str()) );
    }
    catch( SALOME::SALOME_Exception& S_ex ) 
    {
     QMessageBox::information( 0, "Error",
            QString(CORBA::string_dup(S_ex.details.text)),
            QMessageBox::Ok + QMessageBox::Default );
      try
      {
          aCase = _myHomardGen->GetCas(_aCaseName.toStdString().c_str());
          string iter0 = aCase->GetIter0Name();
          HOMARD::HOMARD_Iteration_var aIter =  _myHomardGen->GetIteration(iter0.c_str());
          QString aFileName = aIter->GetMeshFile();
          LEFileName->setText(aFileName);
          LEFileName->setReadOnly(true);
          PushFichier->hide();
      }
      catch( SALOME::SALOME_Exception& S_ex )  {};
      return false;
    }
    LEFileName->setReadOnly(true);
    PushFichier->hide();
  }

  aCase->SetDirName(aDirName.toStdString().c_str());
  _aDirName=aDirName;
  aCase->SetConfType(_ConfType);

  if (CBBoundaryD->isChecked())
  {
    QString monBoundaryDiName=CBBoundaryDi->currentText();
    if (monBoundaryDiName != "" )
    {
      aCase->AddBoundaryGroup(monBoundaryDiName.toStdString().c_str(), " ");
    }
  }

  HOMARD_UTILS::updateObjBrowser();
  return true;
}
// ---------------------------
void MonCreateCase::PushOnOK()
// ---------------------------
{
     bool bOK = PushOnApply();
     if ( bOK )  this->close();
}
//------------------------------
void MonCreateCase::PushOnHelp()
//-------------------------------
{
  HOMARD_UTILS::PushOnHelp(QString("gui_create_case.html"));
}
// ---------------------------------
void MonCreateCase::SetNewCaseName()
// ------------------------------
{
  HOMARD::listeCases_var  MyCases = _myHomardGen->GetAllCases();
  int num = 0; QString aCaseName="";
  while (aCaseName=="" )
  {
    aCaseName.setNum(num+1) ;
    aCaseName.insert(0, QString("Case_")) ;
    for ( int i=0; i<MyCases->length(); i++)
    {
      if ( aCaseName ==  QString((MyCases)[i]))
      {
          num=num+1;
          aCaseName="";
          break;
      }
   }
  }
  LECaseName->clear() ;
  LECaseName->insert(aCaseName);
}

// ------------------------------------------------------------------------
void MonCreateCase::SetDirName()
// ------------------------------------------------------------------------
{
  QString aDirName=QFileDialog::getExistingDirectory ();
  if (!(aDirName.isEmpty()))LEDirName->setText(aDirName);
}
// ------------------------------------------------------------------------
void MonCreateCase::SetFileName()
// ------------------------------------------------------------------------
{
  QString fileName = HOMARD_QT_COMMUN::PushNomFichier();
  if (!(fileName.isEmpty())) LEFileName->setText(fileName);
}
// ------------------------------------------------------------------------
void MonCreateCase::SetConforme()
// ------------------------------------------------------------------------
{
  GBTypeNoConf->setVisible(0);
  adjustSize();
  _ConfType=1;
}
// ------------------------------------------------------------------------
void MonCreateCase::SetNonConforme()
// ------------------------------------------------------------------------
{
  GBTypeNoConf->setVisible(1);
  RB1NpM->setChecked(true);
  adjustSize();
  _ConfType=2;
}
// ------------------------------------------------------------------------
void MonCreateCase::Set1NpM()
// ------------------------------------------------------------------------
{
  _ConfType=2;
}
// ------------------------------------------------------------------------
void MonCreateCase::Set1NpA()
// ------------------------------------------------------------------------
{
  _ConfType=3;
}
// ------------------------------------------------------------------------
void MonCreateCase::SetQuelconque()
// ------------------------------------------------------------------------
{
  _ConfType=4;
}
// ------------------------------------------------------------------------
void MonCreateCase::SetBoundaryD()
// ------------------------------------------------------------------------
{
  if (CBBoundaryD->isChecked())
  { GBBoundaryD->setVisible(1); }
  else
  { GBBoundaryD->setVisible(0); }
  adjustSize();
}
// ------------------------------------------------------------------------
void MonCreateCase::addBoundaryDi(QString newBoundary)
// ------------------------------------------------------------------------
{
  CBBoundaryDi->insertItem(0,newBoundary);
  CBBoundaryDi->setCurrentIndex(0);
}
// ------------------------------------------------------------------------
void MonCreateCase::PushBoundaryDiNew()
// ------------------------------------------------------------------------
{
   MonCreateBoundaryDi *BoundaryDlg = new MonCreateBoundaryDi(this, true, 
                HOMARD::HOMARD_Gen::_duplicate(_myHomardGen), _aCaseName, "") ;
   BoundaryDlg->show();
}
// ------------------------------------------------------------------------
void MonCreateCase::PushBoundaryDiEdit()
// ------------------------------------------------------------------------
{
  if (CBBoundaryDi->currentText() == QString(""))  return;
  MonEditBoundaryDi *BoundaryDlg = new MonEditBoundaryDi(this, true, 
       HOMARD::HOMARD_Gen::_duplicate(_myHomardGen), _aCaseName, CBBoundaryDi->currentText() ) ;
  BoundaryDlg->show();
}
// ------------------------------------------------------------------------
void MonCreateCase::SetBoundaryA()
// ------------------------------------------------------------------------
{
  if    (CBBoundaryA->isChecked()) { GBBoundaryA->setVisible(1); }
  else { GBBoundaryA->setVisible(0); }
  adjustSize();
}
// ------------------------------------------------------------------------
void MonCreateCase::CaseNameChanged()
// ------------------------------------------------------------------------
{
    if (_aCaseName != LECaseName->text().trimmed())
    {
       LEFileName->setReadOnly(false);
       PushFichier->show();
    }
}
