#ifndef MON_CREATEBOUNDARYDI_H
#define MON_CREATEBOUNDARYDI_H


#include <SALOMEconfig.h>
#include <SalomeApp_Module.h>

#include CORBA_CLIENT_HEADER(SALOMEDS_Attributes)
#include CORBA_CLIENT_HEADER(HOMARD_Gen)
#include CORBA_CLIENT_HEADER(HOMARD_Boundary)

#include <CreateBoundaryDi.h>
#include <QDialog>

class MonCreateCase;
class MonCreateBoundaryDi : public QDialog, public Ui_CreateBoundaryDi
{
    Q_OBJECT

public:
    MonCreateBoundaryDi( MonCreateCase* parent, bool modal,
                         HOMARD::HOMARD_Gen_var myHomardGen,
                         QString caseName, QString BoundaryName );
    ~MonCreateBoundaryDi();
    virtual void setGroups (QStringList listGroup);

protected :

    MonCreateCase *_parent;

    QString _aBoundaryName;
    QString _aCaseName;


    HOMARD::HOMARD_Boundary_var _aBoundary;
    HOMARD::HOMARD_Gen_var _myHomardGen;

    QStringList  _listeGroupesBoundary;

    virtual void AssocieLesGroupes();
    virtual void InitConnect();
    virtual void SetNewBoundaryName();

public slots:

    virtual void SetMeshFile();
    virtual void SetFiltrage();
    virtual void PushOnOK();
    virtual bool PushOnApply();
    virtual void PushOnHelp();
};

#endif // MON_CREATEBOUNDARYDI_H
