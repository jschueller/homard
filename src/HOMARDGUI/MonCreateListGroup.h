#ifndef MON_CREATELISTGROUP_H
#define MON_CREATELISTGROUP_H


#include <SALOMEconfig.h>
#include <SalomeApp_Module.h>

#include CORBA_CLIENT_HEADER(SALOMEDS_Attributes)
#include CORBA_CLIENT_HEADER(HOMARD_Gen)

#include <CreateListGroup.h>
#include <QDialog>

class MonCreateHypothesis;
class MonCreateBoundaryDi;
class MonCreateListGroup : public QDialog, public Ui_CreateListGroup
{
    Q_OBJECT

public:
    MonCreateListGroup( MonCreateHypothesis* parentHyp, MonCreateBoundaryDi* parentBound, bool modal, HOMARD::HOMARD_Gen_var myHomardGen, QString aCaseName,  QStringList listeGroupesHypo);
    MonCreateListGroup( MonCreateHypothesis* parentHyp, MonCreateBoundaryDi* parentBound, HOMARD::HOMARD_Gen_var myHomardGen, QString aCaseName, QStringList listeGroupesHypo);
    virtual ~MonCreateListGroup();

protected :

    HOMARD::HOMARD_Gen_var _myHomardGen;

    MonCreateHypothesis * _parentHyp;
    MonCreateBoundaryDi * _parentBound;
    QString _aCaseName;
    QStringList _listeGroupesHypo;

    virtual void InitConnect();
    virtual void InitGroupes();

public slots:
    virtual void PushOnOK();
    virtual bool PushOnApply();
    virtual void PushOnHelp();

};

#endif // MON_CREATELISTGROUP_H
