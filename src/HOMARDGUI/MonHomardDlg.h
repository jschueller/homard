#ifndef MONHOMARDDLG_H
#define MONHOMARDDLG_H

#include "utilities.h"
#include "HomardDlg.h"
#include <QWidget>
#include <SALOMEconfig.h>
#include "SALOME_Selection.h"

#include <SalomeApp_Module.h>

#include CORBA_CLIENT_HEADER(SALOMEDS_Attributes)
#include CORBA_CLIENT_HEADER(HOMARD_Gen)


class HomardConfigFile;
class MonHomardDlg : public QWidget,public Ui_HomardDlg
{ 
    Q_OBJECT

public:
    MonHomardDlg( QWidget* parent, bool modal, HOMARD::HOMARD_Gen_ptr myHomardGen );
    ~MonHomardDlg();

    virtual void initConnect();

public slots:
    virtual void SetNomFichier();
    virtual void PushNomFichier();
    virtual void SetMaillage();
    virtual void SetNbEntites();
    virtual void Lancement();
    virtual void SetInter();
    virtual void SetBilans();
    virtual void SetConnexite();
    virtual void SetHisto();
    virtual void SetQualite();
    virtual void SetVolumes();

protected :
    bool  bHisto, bBilan;
    bool bNomFichier, bNomMaillage;

    HOMARD::HOMARD_Gen_ptr _myHomardGen;

    HomardConfigFile* _monCas;

    QString _aFile;
    QString _aMesh;

private:
      static int RootInfo;
};

#endif // MONHOMARDDLG_H
