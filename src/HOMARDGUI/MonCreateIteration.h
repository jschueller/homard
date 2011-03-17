#ifndef MON_CREATEITERATION_H
#define MON_CREATEITERATION_H


#include <SALOMEconfig.h>
#include <SalomeApp_Module.h>

#include CORBA_CLIENT_HEADER(SALOMEDS_Attributes)
#include CORBA_CLIENT_HEADER(HOMARD_Gen)
#include CORBA_CLIENT_HEADER(HOMARD_Cas)

#include <CreateIteration.h>
#include <QDialog>
#include <QWidget>

class MonCreateIteration : public QDialog, public Ui_CreateIteration
{ 
    Q_OBJECT

public:
    MonCreateIteration( QWidget* parent, bool modal, HOMARD::HOMARD_Gen_var myHomardGen, QString IterParentName );
    ~MonCreateIteration();

    void addHypothese(QString newHypothese);


protected :
    MonCreateIteration( QWidget* parent, HOMARD::HOMARD_Gen_var myHomardGen, QString IterParentName );

    QString _IterationName;
    QString _IterParentName;
    QString _CaseName;


    HOMARD::HOMARD_Iteration_var aIter ;
    HOMARD::HOMARD_Iteration_var aIterParent ;
    HOMARD::HOMARD_Cas_var aCas ;
    HOMARD::HOMARD_Gen_var _myHomardGen;


    virtual void InitConnect();
    virtual void GetHypotheses();
    virtual void SetNewIterationName();

public slots:
    virtual void SetIterParentName();
    virtual void PushHypoEdit();
    virtual void PushHypoNew();
    virtual void PushOnOK();
    virtual bool PushOnApply();
    virtual void PushOnHelp();
    virtual void SetFieldFile();
    virtual void SetTSNo();
    virtual void SetTSLast();
    virtual void SetTSChosen();

};

#endif // MON_CREATEITERATION_H
