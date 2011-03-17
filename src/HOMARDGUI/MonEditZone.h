#ifndef MON_EDITZONE_H
#define MON_EDITZONE_H

#include <SALOMEconfig.h>
#include <SalomeApp_Module.h>

#include CORBA_CLIENT_HEADER(SALOMEDS_Attributes)
#include CORBA_CLIENT_HEADER(HOMARD_Gen)

#include <MonCreateZone.h>

class MonEditZone : public MonCreateZone
{
    Q_OBJECT
public:
    MonEditZone( MonCreateHypothesis* parent, bool modal,
                 HOMARD::HOMARD_Gen_var myHomardGen,
                 QString caseName, QString zoneName);
    virtual ~MonEditZone();

protected :
    void SetBox();
    void SetSphere();
    bool CreateOrUpdateZone();
    void InitValEdit();
    void InitValZoneLimit();
    void InitValZoneBox();
    void InitValZoneSphere();

public slots:

};

#endif // MON_EDITZONE_H
