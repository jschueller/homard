#ifndef _HOMARD_ITERATION_I_HXX_
#define _HOMARD_ITERATION_I_HXX_

#include <SALOMEconfig.h>
#include CORBA_SERVER_HEADER(HOMARD_Gen)
#include CORBA_SERVER_HEADER(HOMARD_Iteration)

#include <string>

class HOMARD_Iteration;

class HOMARD_Iteration_i: public virtual POA_HOMARD::HOMARD_Iteration,
			  public virtual PortableServer::ServantBase
{ 
public:
  HOMARD_Iteration_i( CORBA::ORB_ptr orb, HOMARD::HOMARD_Gen_var gen_i );
  HOMARD_Iteration_i();
  
  virtual ~HOMARD_Iteration_i();

  void                   SetName( const char* NomIteration );
  char*                  GetName();
  char*                  GetDumpPython();

  void                   SetEtat( CORBA::Boolean etat );
  CORBA::Boolean         GetEtat();

  void                   SetNumber( CORBA::Long NumIter );
  CORBA::Long            GetNumber();

  void                   SetMeshName( const char* NomMesh );
  char*                  GetMeshName();

  void                   SetMeshFile( const char* MeshFile );
  char*                  GetMeshFile();

  void                   SetFieldFile( const char* FieldFile );
  char*                  GetFieldFile();
  void                   SetTimeStepRank( CORBA::Long TimeStep, CORBA::Long Rank );
  CORBA::Long            GetTimeStep();
  CORBA::Long            GetRank();

  void                   SetMessFile( const char* MessFile );
  char*                  GetMessFile();

  void                   SetIterParent( const char* NomIterParent );
  char*                  GetIterParent();

  void                   AddIteration( const char* NomIteration );
  HOMARD::listeIterFilles* GetIterations();

  void                   SetCaseName( const char* NomCas );
  char*                  GetCaseName();

  void                   SetDirName( const char* NomDir );
  char*                  GetDirName();

  void                   SetHypoName( const char* NomHypo );
  char*                  GetHypoName();

  CORBA::Boolean         Compute();

  std::string            Dump() const;
  bool                   Restore( const std::string& stream );

private:
  ::HOMARD_Iteration*    myHomardIteration;

  CORBA::ORB_ptr         _orb;
  HOMARD::HOMARD_Gen_var _gen_i;
};

#endif
