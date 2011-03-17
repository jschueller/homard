#ifndef MON_EDITHYPOTHESIS_H
#define MON_EDITHYPOTHESIS_H

#include <SALOMEconfig.h>
#include <SalomeApp_Module.h>

#include CORBA_CLIENT_HEADER(SALOMEDS_Attributes)
#include CORBA_CLIENT_HEADER(HOMARD_Gen)

#include <MonCreateHypothesis.h>

class MonEditHypothesis : public MonCreateHypothesis
{
    Q_OBJECT
public:
    MonEditHypothesis( MonCreateIteration* parent, bool modal,
                       HOMARD::HOMARD_Gen_var myHomardGen,
                       QString caseName, QString HypothesisName, QString aFieldFile );
    virtual ~MonEditHypothesis();

protected :
    virtual void InitValEdit();
    virtual void InitAdaptUniforme();
    virtual void InitAdaptZone();
    virtual void InitAdaptChamps();
    virtual void InitGroupes();
    virtual void InitFieldInterp();
    virtual void SetFiltrage();
    virtual bool PushOnApply();

public slots:

};

#endif
