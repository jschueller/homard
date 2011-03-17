#ifndef _HOMARD_CAS_I_HXX_
#define _HOMARD_CAS_I_HXX_

#include <SALOMEconfig.h>
#include CORBA_SERVER_HEADER(HOMARD_Gen)
#include CORBA_SERVER_HEADER(HOMARD_Cas)

#include <string>

class HOMARD_Cas;

class HOMARD_Cas_i: public virtual POA_HOMARD::HOMARD_Cas,
		    public virtual PortableServer::ServantBase
{
public:
  HOMARD_Cas_i( CORBA::ORB_ptr orb, HOMARD::HOMARD_Gen_var gen_i );
  HOMARD_Cas_i();

  virtual ~HOMARD_Cas_i();

  void                   SetDirName( const char* NomDir );
  char*                  GetDirName();

  void                   SetName( const char* NomCas );
  char*                  GetName();

  void                   SetConfType( CORBA::Long ConfType );
  CORBA::Long            GetConfType();

  void                   AddIteration( const char* NomIteration );
  char*                  GetIter0Name();

  HOMARD::extrema*       GetBoundingBox();
  void                   SetBoundingBox( const HOMARD::extrema& LesExtremes );

  HOMARD::ListGroupType* GetGroups();
  void                   AddGroup( const char* Group);
  void                   SetGroups(const HOMARD::ListGroupType& ListGroup);

  HOMARD::ListBoundaryGroupType*  GetBoundaryGroup();
  void                   AddBoundaryGroup( const char* Boundary, const char* Group);

  std::string            Dump() const;
  bool                   Restore( const std::string& stream );

  char *		 GetDumpPython();
  CORBA::Long            GetNumber();

private:
  ::HOMARD_Cas*          myHomardCas;

  CORBA::ORB_ptr         _orb;
  HOMARD::HOMARD_Gen_var _gen_i;
};

#endif
