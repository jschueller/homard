using namespace std;

#include "MonEditCase.h"

#include <QMessageBox>

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include "HomardQtCommun.h"
#include <utilities.h>


// -------------------------------------------------------------
MonEditCase::MonEditCase ( QWidget* parent, bool modal,
                           HOMARD::HOMARD_Gen_var myHomardGen,
                           QString CaseName ):
// -------------------------------------------------------------
/* Constructs a MonEditCase
    herite de MonCreateCase
*/
   MonCreateCase(parent, modal, myHomardGen)
{
    MESSAGE("Debut de MonEditCase" << CaseName.toStdString().c_str());
    setWindowTitle("Edit case");
    _aCaseName = CaseName;
    aCase = _myHomardGen->GetCas(_aCaseName.toStdString().c_str());
    InitValEdit();
}
// ------------------------------
MonEditCase::~MonEditCase()
// ------------------------------
{
}


// ------------------------------
void MonEditCase::InitValEdit()
// ------------------------------
{
    MESSAGE("Debut de InitValEdit");
      LECaseName->setText(_aCaseName);
      LECaseName->setReadOnly(true);

      QString aDirName = aCase->GetDirName();
      LEDirName->setText(aDirName);
      LEDirName->setReadOnly(true);
      PushDir->setVisible(0);

      QString _aitername=aCase->GetIter0Name();
      HOMARD::HOMARD_Iteration_var aIter = _myHomardGen->GetIteration(_aitername.toStdString().c_str());
      QString aFileName = aIter->GetMeshFile();
      LEFileName->setText(aFileName);
      LEFileName->setReadOnly(true);
      PushFichier->setVisible(0);

      int ConfType=aCase->GetConfType();
      if(ConfType==1)
      {
         GBTypeNoConf->setVisible(0);
         RBConforme->setChecked(true);
      }
      else
      {
        RBNonConforme->setChecked(true);
        GBTypeNoConf->setVisible(1);
        RB1NpM->setEnabled(false);
        RB1NpA->setEnabled(false);
        RBQuelconque->setEnabled(false);
      };

      if (_ConfType==2) { RB1NpM->setChecked(true);};
      if (_ConfType==3) { RB1NpA->setChecked(true);};
      if (_ConfType==4) { RBQuelconque->setChecked(true);};

      RBNonConforme->setEnabled(false);
      RBConforme->setEnabled(false);

//    Affichage du mode de suivi de frontiere
      CBBoundaryA->setVisible(0);
      GBBoundaryA->setVisible(0);
      CBBoundaryD->setVisible(0);
      GBBoundaryD->setVisible(0);

      HOMARD::ListBoundaryGroupType_var mesBoundarys = aCase->GetBoundaryGroup();
      if (mesBoundarys->length()>0)
      {
        bool BounDi = false ;
        bool BounAn = false ;
        for (int i=0; i<mesBoundarys->length(); i++)
        {
          HOMARD::HOMARD_Boundary_var myBoundary = _myHomardGen->GetBoundary((mesBoundarys)[i]);
          int type_obj = myBoundary->GetBoundaryType() ;

          if ( type_obj==0 ) 
          { CBBoundaryDi->addItem(QString((mesBoundarys)[i++]));
            BounDi = true ;
          }
          else
          {
            i++ ;
            BounAn = true ;
          };
        }
        MESSAGE("BounDi "<<BounDi<<", BounAn "<<BounAn);
        if ( BounAn )
        { GBBoundaryA->setVisible(1);
          GBBoundaryA->setDisabled(true);}
        if ( BounDi )
        { GBBoundaryD->setVisible(1);
          CBBoundaryDi->setDisabled(true);
          PBBoundaryDiNew->setVisible(0);}
      }
}

// -------------------------------------
bool MonEditCase::PushOnApply()
// -------------------------------------
{
  return true ;

};
