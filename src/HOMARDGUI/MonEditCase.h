#ifndef MON_EDITCASE_H
#define MON_EDITCASE_H

#include <SALOMEconfig.h>
#include <SalomeApp_Module.h>

#include CORBA_CLIENT_HEADER(SALOMEDS_Attributes)
#include CORBA_CLIENT_HEADER(HOMARD_Gen)

#include <MonCreateCase.h>

class MonEditCase : public MonCreateCase
{
    Q_OBJECT
public:
    MonEditCase( QWidget* parent, bool modal,
                 HOMARD::HOMARD_Gen_var myHomardGen,
                 QString CaseName );
    virtual ~MonEditCase();

protected :
    virtual void InitValEdit();
    virtual bool PushOnApply();

public slots:

};

#endif
