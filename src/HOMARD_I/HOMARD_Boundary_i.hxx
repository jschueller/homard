#ifndef _HOMARD_Boundary_I_HXX_
#define _HOMARD_Boundary_I_HXX_

#include <SALOMEconfig.h>
#include CORBA_SERVER_HEADER(HOMARD_Gen)
#include CORBA_SERVER_HEADER(HOMARD_Boundary)

#include <string>

class HOMARD_Boundary;

class HOMARD_Boundary_i: public virtual POA_HOMARD::HOMARD_Boundary,
                         public virtual PortableServer::ServantBase
{ 
public:
  HOMARD_Boundary_i( CORBA::ORB_ptr orb, HOMARD::HOMARD_Gen_var gen_i );
  HOMARD_Boundary_i();
  
  virtual ~HOMARD_Boundary_i();

  void                   SetName( const char* NomBoundary );
  char*                  GetName();
  char*                  GetDumpPython();
  
  void                   SetBoundaryType( CORBA::Long BoundaryType );
  
  CORBA::Long            GetBoundaryType();

  void                   SetMeshFile( const char* MeshFile );
  char*                  GetMeshFile();

  void                   SetMeshName( const char* MeshName );
  char*                  GetMeshName();
  
  HOMARD::double_array*  GetCylinder();
  void                   SetCylinder( double Xcentre, double Ycentre, double ZCentre,
                                      double Xaxe, double Yaxe, double Zaxe,
                                      double rayon );
  
  HOMARD::double_array*  GetSphere();
  void                   SetSphere( double Xcentre, double Ycentre, double ZCentre,
                                    double rayon );
  
  HOMARD::double_array*  GetLimit();
  void                   SetLimit( double Xincr, double Yincr, double Zincr);
  
  
  std::string            Dump() const;
  bool                   Restore( const std::string& stream );

  void                   SetCaseCreation( const char* NomCaseCreation );
  char*                  GetCaseCreation();

  void                    AddGroup( const char* Group);
  void                    SetGroups(const HOMARD::ListGroupType& ListGroup);
  HOMARD::ListGroupType*  GetGroups();


private:
  ::HOMARD_Boundary*     myHomardBoundary;
  
  CORBA::ORB_ptr         _orb;
  HOMARD::HOMARD_Gen_var _gen_i;
};

#endif
