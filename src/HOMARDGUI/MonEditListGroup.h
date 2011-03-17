#ifndef MON_EDITLISTGROUP_H
#define MON_EDITLISTGROUP_H


#include <SALOMEconfig.h>
#include <SalomeApp_Module.h>

#include CORBA_CLIENT_HEADER(SALOMEDS_Attributes)
#include CORBA_CLIENT_HEADER(HOMARD_Gen)

#include <MonCreateListGroup.h>

class MonCreateHypothesis;
class MonCreateBoundaryDi;
class MonEditListGroup : public MonCreateListGroup
{
    Q_OBJECT

public:
    MonEditListGroup( MonCreateHypothesis* parentHyp, MonCreateBoundaryDi* parentBound, bool modal, HOMARD::HOMARD_Gen_var myHomardGen, QString aCaseName,  QStringList listeGroupesHypo);
    virtual ~MonEditListGroup();

protected :

    virtual void InitGroupes();

};

#endif // MON_EDITLISTGROUP_H
