#include "MonHomardDlg.h"
#include "HomardConfigFile.hxx"
#include "HomardQtCommun.h"

#include<QMessageBox>

#include <SalomeApp_Module.h>
#include <SalomeApp_Application.h>
#include <SalomeApp_Study.h>

#include "HOMARDGUI_Utils.h"

#include <string>
#include "utilities.h"

#define MIN_LISTBOX_WIDTH      150
#define MIN_LISTBOX_HEIGHT     100

int MonHomardDlg::RootInfo = 100;

//--------------------------------------------------------------------------------------------------------------------
MonHomardDlg::MonHomardDlg( QWidget * parent,  bool modal, HOMARD::HOMARD_Gen_ptr myHomardGen):
      QWidget(0),
      Ui_HomardDlg(),
      bHisto(true),bBilan(true), bNomFichier(false), bNomMaillage(false),
      _aFile(QString::null), _aMesh (QString::null)
//--------------------------------------------------------------------------------------------------------------------
{
      setupUi(this);
      setModal(true);
      _myHomardGen=HOMARD::HOMARD_Gen::_duplicate(myHomardGen);

      _monCas      = new HomardConfigFile();
      _monCas->initVal(string("Interpe3"),string("non"));
      _monCas->initVal(string("Qualite5"),string("oui"));
      _monCas->initVal(string("Nb_Enti7"),string("oui"));
      _monCas->initVal(string("Connex11"),string("oui"));
      _monCas->initVal(string("Taille13"),string("oui"));
      _monCas->setBilan(true);
      
      initConnect();

}

//-----------------------------
MonHomardDlg::~MonHomardDlg()
//-----------------------------
{
    // no need to delete child widgets, Qt does it all for us
}

//-----------------------------
void MonHomardDlg::initConnect()
//-----------------------------
{
    connect( lancement, SIGNAL( pressed() ), this, SLOT( Lancement() ) );
    connect( terminer, SIGNAL( pressed() ), this, SLOT( close() ) );
    connect( ListeMeshName, SIGNAL( activated(int) ), this, SLOT( SetMaillage() ) );
    connect( NomFichier, SIGNAL( returnPressed() ), this, SLOT( SetNomFichier() ) );
    connect( PushFichier, SIGNAL( clicked() ), this, SLOT( PushNomFichier() ) );
    connect( Connexite, SIGNAL( stateChanged(int) ), this, SLOT( SetConnexite() ) );
    connect( Inter, SIGNAL( stateChanged(int) ), this, SLOT( SetInter() ) );
    connect( NbEntites, SIGNAL( stateChanged(int) ), this, SLOT( SetNbEntites() ) );
    connect( Histo, SIGNAL( stateChanged(int) ), this, SLOT( SetHisto() ) );
    connect( Qualite, SIGNAL( stateChanged(int) ), this, SLOT( SetQualite() ) );
    connect( Volumes, SIGNAL( stateChanged(int) ), this, SLOT( SetVolumes() ) );
    connect( Bilan, SIGNAL( stateChanged(int) ), this, SLOT( SetBilans() ) );
}

//-----------------------------
void MonHomardDlg::Lancement()
//-----------------------------
{
  if( ( bNomFichier==false) || (bNomMaillage ==false))
  {
        QMessageBox::information( 0, "Mauvaise Selection",
        QString(" Selectionner un Fichier et un Maillage SVP "),
        QMessageBox::Ok + QMessageBox::Default );
	return;
  }

  bool ok;
  ok=_monCas->initVal(string("ModeHOMA"),string("2"));
  ok=_monCas->initVal(string("ListeStd"),string(_aMesh.toStdString())+string(".info"));
  ok=_monCas->initVal(string("CCAssoci"),string("MED"));
  ok=_monCas->initVal(string("CCSolN__"),string(_aFile.toStdString()));
  ok=_monCas->initVal(string("CCMaiN__"),string(_aFile.toStdString()));
  ok=_monCas->initVal(string("CCNoMN__"),string(_aMesh.toStdString()));
  ok=_monCas->initVal(string("PPBasFic"),string(_aMesh.toStdString()));
  ok=_monCas->initVal(string("EcriFiHO"),string("non"));

  ok = _monCas->createFile();
  if ( ok == false)
  {
        QMessageBox::information( 0, "Mauvaise Selection",
        QString("Probleme � la cr�ation du fichier Homard "),
        QMessageBox::Ok + QMessageBox::Default );
        return;
  }

  string fileDir=string(_monCas->getMyDir().c_str());
  char * dirchar; char * execchar;
  string  dir; string  executable;
  string result=string(_aMesh.toStdString())+string(".info");

  if ( !(dirchar = getenv("HOMARD_REP_EXE")) )
     { dir=string("/local/logiciels/Homard"); }
  else
     { dir=string(dirchar); }

  if ( !(execchar = getenv("HOMARD_EXE")) )
     { executable =string("HOMARD"); }
  else
     { executable =string(execchar); }

  string commande = dir+"/"+executable;
  string info = ";more *.info";
  string ou=string("cd ") + string(fileDir);
  string tout=ou +string("; xterm -sb -hold  -e \" ") + commande + info + string ("\"");
  system(tout.c_str());
  int MonCasRoot = MonHomardDlg::RootInfo;
  int TagInfo = 0;
  MonHomardDlg::RootInfo = MonHomardDlg::RootInfo+1;
  HOMARD_UTILS::AddNewRoot(MonCasRoot,QString(_aMesh));

  if (bBilan == true)  
  {
     QStringList Lesfichiers=HOMARD_UTILS::ChercheDansDir(fileDir.c_str(),QString("info"),-1);
     QString FileComment=QString("HomardOuputInfo");
     for ( QStringList::Iterator it = Lesfichiers.begin(); it != Lesfichiers.end(); ++it )
     {
	HOMARD_UTILS::RangeSousTag(MonCasRoot,(*it),TagInfo,FileComment,fileDir.c_str());
	TagInfo ++;
     }
  }
  if (bHisto == true)  
  {
     QStringList Lesfichiers=HOMARD_UTILS::ChercheDansDir(fileDir.c_str(),QString("qual"),-1);
     QString FileComment=QString("HomardOuputQual");
     for ( QStringList::Iterator it = Lesfichiers.begin(); it != Lesfichiers.end(); ++it )
     {
	HOMARD_UTILS::RangeSousTag(MonCasRoot,(*it),TagInfo,FileComment,fileDir.c_str());
	TagInfo ++;
     }
  }
  HOMARD_UTILS::updateObjBrowser();
  close();

}

//-----------------------------
void MonHomardDlg::SetBilans()
//-----------------------------
{
    if (Bilan->isChecked())
    {	
      _monCas->setBilan(true);
      bBilan=true;
    }
    else
    {
      _monCas->setBilan(false);
      bBilan=false;
    }   
}

//-----------------------------
void MonHomardDlg::SetConnexite()
//-----------------------------
{
    bool ok;
    if (Connexite->isChecked())
    {	
      ok=_monCas->initVal(string("Connex11"),string("oui"));
    }
    else
    {
      ok=_monCas->initVal(string("Connex11"),string("non"));
    }   
    if ( ok ==false)
    {
        QMessageBox::information( 0, "Mauvaise Selection",
        QString("Mauvaise valeur pour ce mot clef"),
        QMessageBox::Ok + QMessageBox::Default );
    }
}

//-----------------------------
void MonHomardDlg::SetInter()
//-----------------------------
{
    bool ok;
    if (Inter->isChecked())
    {	
      ok=_monCas->initVal(string("Interpe3"),string("oui"));
    }
    else
    {
      ok=_monCas->initVal(string("Interpe3"),string("non"));
    }   
    if ( ok ==false)
    {
        QMessageBox::information( 0, "Mauvaise Selection",
        QString("Mauvaise valeur pour ce mot clef"),
        QMessageBox::Ok + QMessageBox::Default );
    }
}

//-----------------------------
void MonHomardDlg::SetNbEntites()
//-----------------------------
{
    bool ok;
    if (NbEntites->isChecked())
    {	
      ok=_monCas->initVal(string("Nb_Enti7"),string("oui"));
    }
    else
    {
      ok=_monCas->initVal(string("Nb_Enti7"),string("non"));
    }   
    if ( ok ==false)
    {
        QMessageBox::information( 0, "Mauvaise Selection",
        QString("Mauvaise valeur pour ce mot clef"),
        QMessageBox::Ok + QMessageBox::Default );
    }
}

//-----------------------------
void MonHomardDlg::SetHisto()
//-----------------------------
{
    if (Histo->isChecked())
    {	
      bHisto=true;
    }
    else
    {
      bHisto=false;
    }   
}

//-----------------------------
void MonHomardDlg::SetQualite()
//-----------------------------
{
    bool ok;
    if (Qualite->isChecked())
    {	
      ok=_monCas->initVal(string("Qualite5"),string("oui"));
    }
    else
    {
      ok=_monCas->initVal(string("Qualite5"),string("non"));
    }   
    if ( ok ==false)
    {
        QMessageBox::information( 0, "Mauvaise Selection",
        QString("Mauvaise valeur pour ce mot clef"),
        QMessageBox::Ok + QMessageBox::Default );
    }
}

//-----------------------------
void MonHomardDlg::SetVolumes()
//-----------------------------
{
    bool ok;
    if (Volumes->isChecked())
    {	
      ok=_monCas->initVal(string("Taille13"),string("oui"));
    }
    else
    {
      ok=_monCas->initVal(string("Taille13"),string("non"));
    }   
    if ( ok ==false)
    {
        QMessageBox::information( 0, "Mauvaise Selection",
        QString("Mauvaise valeur pour ce mot clef"),
        QMessageBox::Ok + QMessageBox::Default );
    }

}

//---------------------------------
void MonHomardDlg::PushNomFichier()
//---------------------------------
{
   MESSAGE("Debut de PushNomFichier");
   bNomFichier=false;
   _aFile=HOMARD_QT_COMMUN::PushNomFichier();
   if ( _aFile != QString::null)
   {
       NomFichier->setText(_aFile);
       bNomFichier=true;
       this->SetNomFichier();
   }
}

//-----------------------------------
void MonHomardDlg::SetNomFichier()
//-----------------------------------
/* Ce slot est appele quand on entre le nom du fichier */
{
   MESSAGE("Debut de SetNomFichier");
   _aFile=NomFichier->text();
   bNomFichier=true;
   if ( HOMARD_QT_COMMUN::SetListeMaillages(_aFile,ListeMeshName))
   {
      if (ListeMeshName->count() == 1) this->SetMaillage();
   }
   else
   {
      bNomFichier=false;
      _aFile=QString::null;
     NomFichier->setText(_aFile);
   }
}


//-----------------------------------
void MonHomardDlg::SetMaillage()
//-----------------------------------
{
	MESSAGE("Debut de SetMaillage");
	bNomMaillage = true;
	_aMesh=ListeMeshName->currentText();
}

