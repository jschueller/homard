#ifndef _HOMARD_Zone_I_HXX_
#define _HOMARD_Zone_I_HXX_

#include <SALOMEconfig.h>
#include CORBA_SERVER_HEADER(HOMARD_Gen)
#include CORBA_SERVER_HEADER(HOMARD_Zone)

#include <string>

class HOMARD_Zone;

class HOMARD_Zone_i: public virtual POA_HOMARD::HOMARD_Zone,
                     public virtual PortableServer::ServantBase
{ 
public:
  HOMARD_Zone_i( CORBA::ORB_ptr orb, HOMARD::HOMARD_Gen_var gen_i );
  HOMARD_Zone_i();
  
  virtual ~HOMARD_Zone_i();

  void                   SetName( const char* NomZone );
  char*                  GetName();
  char*                  GetDumpPython();
  
  void                   SetZoneType( CORBA::Long ZoneType );
  
  CORBA::Long            GetZoneType();
  
  HOMARD::double_array*  GetBox();
  void                   SetBox( double Xmini, double Xmaxi, 
				 double Ymini, double Ymaxi, 
				 double Zmini, double Zmaxi );
  
  HOMARD::double_array*  GetSphere();
  void                   SetSphere( double Xcentre, double Ycentre, double ZCentre,
				    double rayon );
  
  HOMARD::double_array*  GetLimit();
  void                   SetLimit( double Xincr, double Yincr, double Zincr);
  
  void                   AddHypo( const char *NomHypo );
  void                   SupprHypo( const char *NomHypo );
  HOMARD::listeHypo*     GetHypo();
  
  std::string            Dump() const;
  bool                   Restore( const std::string& stream );

private:
  ::HOMARD_Zone*         myHomardZone;
  
  CORBA::ORB_ptr         _orb;
  HOMARD::HOMARD_Gen_var _gen_i;
};

#endif
