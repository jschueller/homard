using namespace std;

#include "MonEditBoundaryDi.h"
#include "MonEditListGroup.h"

#include <QMessageBox>

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include "HomardQtCommun.h"
#include <utilities.h>


// -------------------------------------------------------------------------------------------------------------------------------------
MonEditBoundaryDi::MonEditBoundaryDi( MonCreateCase* parent, bool modal,
                                      HOMARD::HOMARD_Gen_var myHomardGen,
                                      QString caseName, QString BoundaryName):
// -------------------------------------------------------------------------------------------------------------------------------------
/* Constructs a MonEditBoundaryDi
    herite de MonCreateBoundaryDi
*/
    MonCreateBoundaryDi(parent, modal, myHomardGen, caseName, BoundaryName)
{
    MESSAGE("Debut de Boundary pour " << BoundaryName.toStdString().c_str());
    setWindowTitle("Edit BoundaryDi");
    try
    {
     _aBoundary=_myHomardGen->GetBoundary(CORBA::string_dup(_aBoundaryName.toStdString().c_str()));
     if (caseName==QString("")) { _aCaseName=_aBoundary->GetCaseCreation();}
     InitValEdit();
    }
    catch( SALOME::SALOME_Exception& S_ex )
    {
        QMessageBox::information( 0, "Error",
                  QString(CORBA::string_dup(S_ex.details.text)),
                  QMessageBox::Ok + QMessageBox::Default );
        return;
    }

    HOMARD::ListGroupType_var maListe = _aBoundary->GetGroups();
    for ( int i = 0; i < maListe->length(); i++ )
       _listeGroupesBoundary << QString(maListe[i]);

}
// ------------------------------
MonEditBoundaryDi::~MonEditBoundaryDi()
// ------------------------------
{
}

// ------------------------------
void MonEditBoundaryDi::InitValEdit()
// ------------------------------
{
      LEBoundaryName->setText(_aBoundaryName);
      LEBoundaryName->setReadOnly(true);

      QString aMeshFile = _aBoundary->GetMeshFile();
      LEFileName->setText(aMeshFile);
      LEFileName->setReadOnly(1);
      PushFichier->setVisible(0);
      adjustSize();
}
// ------------------------------
bool MonEditBoundaryDi::PushOnApply()
// ------------------------------
{
     return true;
}
// ------------------------------------------------------------------------
void MonEditBoundaryDi::SetFiltrage()
// // ------------------------------------------------------------------------
{
   if (!CBGroupe->isChecked()) return;
   if (_aCaseName.toStdString().c_str() == QString()) 
   {
        QMessageBox::information( 0, "Error",
                              "Case MeshFile unknowned.",
                              QMessageBox::Ok + QMessageBox::Default );
        return;
   }
   HOMARD::HOMARD_Cas_var monCas= _myHomardGen->GetCas(_aCaseName.toStdString().c_str());
   HOMARD::ListGroupType_var _listeGroupesCas = monCas->GetGroups();

   MonEditListGroup *aDlg = new MonEditListGroup(NULL,this,  TRUE, HOMARD::HOMARD_Gen::_duplicate(_myHomardGen),
                              _aCaseName, _listeGroupesBoundary) ;
   aDlg->show();
}

