#ifndef MON_EDITBOUNDARYDI_H
#define MON_EDITBOUNDARYDI_H

#include <SALOMEconfig.h>
#include <SalomeApp_Module.h>

#include CORBA_CLIENT_HEADER(SALOMEDS_Attributes)
#include CORBA_CLIENT_HEADER(HOMARD_Gen)

#include <MonCreateBoundaryDi.h>

class MonEditBoundaryDi : public MonCreateBoundaryDi
{
    Q_OBJECT
public:
    MonEditBoundaryDi( MonCreateCase* parent, bool modal,
                       HOMARD::HOMARD_Gen_var myHomardGen,
                       QString caseName, QString BoundaryName );
    virtual ~MonEditBoundaryDi();

protected :
    virtual void InitValEdit();
    virtual bool PushOnApply();
    virtual void SetFiltrage();

public slots:

};

#endif
