#ifndef MON_EDITITERATION_H
#define MON_EDITITERATION_H

#include <SALOMEconfig.h>
#include <SalomeApp_Module.h>

#include CORBA_CLIENT_HEADER(SALOMEDS_Attributes)
#include CORBA_CLIENT_HEADER(HOMARD_Gen)

#include <MonCreateIteration.h>

class MonEditIteration : public MonCreateIteration
{
    Q_OBJECT
public:
    MonEditIteration( QWidget* parent, bool modal,
                      HOMARD::HOMARD_Gen_var myHomardGen,
                      QString IterParentName, QString IterName );
    virtual ~MonEditIteration();

protected :
    QString _FieldFile ;
    QString _IterationName ;
    int _aTypeAdap ;
    int _rank ;
    int _step ;

    virtual void InitValEdit();
    virtual void InitValEdit0();
    virtual bool PushOnApply();

public slots:

};

#endif
