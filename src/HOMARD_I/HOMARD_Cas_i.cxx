// Copyright (C) 2011-2013  CEA/DEN, EDF R&D
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
//
// Remarques :
// L'ordre de description des fonctions est le meme dans tous les fichiers
// HOMARD_aaaa.idl, HOMARD_aaaa.hxx, HOMARD_aaaa.cxx, HOMARD_aaaa_i.hxx, HOMARD_aaaa_i.cxx :
// 1. Les generalites : Name, Delete, DumpPython, Dump, Restore
// 2. Les caracteristiques
// 3. Le lien avec les autres structures
//
// Quand les 2 fonctions Setxxx et Getxxx sont presentes, Setxxx est decrit en premier
//

#include "HOMARD_Cas_i.hxx"
#include "HOMARD_Gen_i.hxx"
#include "HOMARD_Cas.hxx"
#include "HOMARD_DriverTools.hxx"

#include "utilities.h"
#include <vector>

//=============================================================================
/*!
 *  standard constructor
 */
//=============================================================================
HOMARD_Cas_i::HOMARD_Cas_i()
{
  MESSAGE( "Default constructor, not for use" );
  ASSERT( 0 );
}

//=============================================================================
/*!
 *  standard constructor
 */
//=============================================================================
HOMARD_Cas_i::HOMARD_Cas_i( CORBA::ORB_ptr orb,
                            HOMARD::HOMARD_Gen_var engine )
{
  MESSAGE( "HOMARD_Cas_i" );
  _gen_i = engine;
  _orb = orb;
  myHomardCas = new ::HOMARD_Cas();
  ASSERT( myHomardCas );
}

//=============================================================================
/*!
 *  standard destructor
 */
//=============================================================================
HOMARD_Cas_i::~HOMARD_Cas_i()
{
}
//=============================================================================
//=============================================================================
// Generalites
//=============================================================================
//=============================================================================
void HOMARD_Cas_i::SetName( const char* Name )
{
  ASSERT( myHomardCas );
  myHomardCas->SetName( Name );
}
//=============================================================================
char* HOMARD_Cas_i::GetName()
{
  ASSERT( myHomardCas );
  return CORBA::string_dup( myHomardCas->GetName().c_str() );
}
//=============================================================================
CORBA::Long  HOMARD_Cas_i::Delete()
{
  ASSERT( myHomardCas );
  char* CaseName = GetName() ;
  MESSAGE ( "Delete : destruction du cas " << CaseName );
  return _gen_i->DeleteCase(CaseName) ;
}
//=============================================================================
char* HOMARD_Cas_i::GetDumpPython()
{
  ASSERT( myHomardCas );
  return CORBA::string_dup( myHomardCas->GetDumpPython().c_str() );
}
//=============================================================================
std::string HOMARD_Cas_i::Dump() const
{
  return HOMARD::Dump( *myHomardCas );
}
//=============================================================================
bool HOMARD_Cas_i::Restore( const std::string& stream )
{
  return HOMARD::Restore( *myHomardCas, stream );
}
//=============================================================================
//=============================================================================
// Caracteristiques
//=============================================================================
//=============================================================================
void HOMARD_Cas_i::SetDirName( const char* NomDir )
{
  ASSERT( myHomardCas );
  int codret ;
  // A. Changement/creation du repertoire
  char* oldrep = GetDirName() ;
  codret = myHomardCas->SetDirName( NomDir );
  if ( codret != 0 )
  {
    SALOME::ExceptionStruct es;
    es.type = SALOME::BAD_PARAM;
    std::string text ;
    if ( codret == 1 ) { text = "The directory for the case cannot be modified because some iterations are already defined." ; }
    else               { text = "The directory for the case cannot be reached." ; }
    es.text = CORBA::string_dup(text.c_str());
    throw SALOME::SALOME_Exception(es);
  }
  // B. En cas de reprise, deplacement du point de depart
  if ( GetState() != 0 )
  {
    MESSAGE ( "etat : " << GetState() ) ;
    char* Iter0Name = GetIter0Name() ;
    HOMARD::HOMARD_Iteration_ptr Iter = _gen_i->GetIteration(Iter0Name) ;
    char* DirNameIter = Iter->GetDirNameLoc() ;
    std::string commande = "mv " + std::string(oldrep) + "/" + std::string(DirNameIter) + " " + std::string(NomDir) ;
    codret = system(commande.c_str()) ;
    if ( codret != 0 )
    {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      std::string text = "The starting point for the case cannot be moved into the new directory." ;
      es.text = CORBA::string_dup(text.c_str());
      throw SALOME::SALOME_Exception(es);
    }
  }
  return ;
}
//=============================================================================
char* HOMARD_Cas_i::GetDirName()
{
  ASSERT( myHomardCas );
  return CORBA::string_dup( myHomardCas->GetDirName().c_str() );
}
//=============================================================================
CORBA::Long HOMARD_Cas_i::GetState()
{
  ASSERT( myHomardCas );
// Nom de l'iteration initiale
  char* Iter0Name = GetIter0Name() ;
  HOMARD::HOMARD_Iteration_ptr Iter = _gen_i->GetIteration(Iter0Name) ;
  int state = Iter->GetNumber() ;
  return state ;
}
//=============================================================================
CORBA::Long HOMARD_Cas_i::GetNumberofIter()
{
  ASSERT( myHomardCas );
  return myHomardCas->GetNumberofIter();
}
//=============================================================================
void HOMARD_Cas_i::SetConfType( CORBA::Long ConfType )
{
  ASSERT( myHomardCas );
  myHomardCas->SetConfType( ConfType );
}
//=============================================================================
CORBA::Long HOMARD_Cas_i::GetConfType()
{
  ASSERT( myHomardCas );
  return myHomardCas->GetConfType();
}
//=============================================================================
void HOMARD_Cas_i::SetBoundingBox( const HOMARD::extrema& LesExtrema )
{
  ASSERT( myHomardCas );
  std::vector<double> VExtrema;
  ASSERT( LesExtrema.length() == 10 );
  VExtrema.resize( LesExtrema.length() );
  for ( int i = 0; i < LesExtrema.length(); i++ )
  {
    VExtrema[i] = LesExtrema[i];
  }
  myHomardCas->SetBoundingBox( VExtrema );
}
//=============================================================================
HOMARD::extrema* HOMARD_Cas_i::GetBoundingBox()
{
  ASSERT(myHomardCas );
  HOMARD::extrema_var aResult = new HOMARD::extrema();
  std::vector<double> LesExtremes = myHomardCas->GetBoundingBox();
  ASSERT( LesExtremes.size() == 10 );
  aResult->length( 10 );
  for ( int i = 0; i < LesExtremes.size(); i++ )
  {
    aResult[i] = LesExtremes[i];
  }
  return aResult._retn();
}
//=============================================================================
void HOMARD_Cas_i::AddGroup( const char* Group)
{
  ASSERT( myHomardCas );
  myHomardCas->AddGroup( Group );
}
//=============================================================================
void HOMARD_Cas_i::SetGroups( const HOMARD::ListGroupType& ListGroup )
{
  ASSERT( myHomardCas );
  std::list<std::string> ListString ;
  for ( int i = 0; i < ListGroup.length(); i++ )
  {
    ListString.push_back(std::string(ListGroup[i]));
  }
  myHomardCas->SetGroups( ListString );
}
//=============================================================================
HOMARD::ListGroupType* HOMARD_Cas_i::GetGroups()
{
  ASSERT(myHomardCas );
  const std::list<std::string>& ListString = myHomardCas->GetGroups();
  HOMARD::ListGroupType_var aResult = new HOMARD::ListGroupType();
  aResult->length( ListString.size() );
  std::list<std::string>::const_iterator it;
  int i = 0;
  for ( it = ListString.begin(); it != ListString.end(); it++ )
  {
    aResult[i++] = CORBA::string_dup( (*it).c_str() );
  }
  return aResult._retn();
}
//=============================================================================
void HOMARD_Cas_i::AddBoundaryGroup( const char* BoundaryName, const char* Group)
{
  MESSAGE ("AddBoundaryGroup : BoundaryName = "<< BoundaryName << ", Group = " << Group );
  ASSERT( myHomardCas );
  // La frontiere est-elle deja enregistree pour ce cas ?
  const std::list<std::string>& ListBoundaryGroup = myHomardCas->GetBoundaryGroup();
  std::list<std::string>::const_iterator it;
  int existe = 0;
  for ( it = ListBoundaryGroup.begin(); it != ListBoundaryGroup.end(); it++ )
  {
    if ( *it == BoundaryName )
    { existe = 1 ; }
    it++ ;
  }
  // Enregistrement de la frontiere dans la reference du cas
  myHomardCas->AddBoundaryGroup( BoundaryName, Group );
  // Pour une nouvelle frontiere, publication dans l'arbre d'etudes sous le cas
  if ( existe == 0 )
  {
    char* CaseName = GetName() ;
    MESSAGE ( "AddBoundaryGroup : insertion de la frontiere dans l'arbre de " << CaseName );
    _gen_i->PublishBoundaryUnderCase(CaseName, BoundaryName) ;
  }
}
//=============================================================================
HOMARD::ListBoundaryGroupType* HOMARD_Cas_i::GetBoundaryGroup()
{
  MESSAGE ("GetBoundaryGroup");
  ASSERT(myHomardCas );
  const std::list<std::string>& ListBoundaryGroup = myHomardCas->GetBoundaryGroup();
  HOMARD::ListBoundaryGroupType_var aResult = new HOMARD::ListBoundaryGroupType();
  aResult->length( ListBoundaryGroup.size() );
  std::list<std::string>::const_iterator it;
  int i = 0;
  for ( it = ListBoundaryGroup.begin(); it != ListBoundaryGroup.end(); it++ )
  {
    aResult[i++] = CORBA::string_dup( (*it).c_str() );
  }
  return aResult._retn();
}
//=============================================================================
void HOMARD_Cas_i::SetPyram( CORBA::Long Pyram )
{
  MESSAGE ("SetPyram, Pyram = " << Pyram );
  ASSERT( myHomardCas );
  myHomardCas->SetPyram( Pyram );
}
//=============================================================================
CORBA::Long HOMARD_Cas_i::GetPyram()
{
  MESSAGE ("GetPyram");
  ASSERT( myHomardCas );
  return myHomardCas->GetPyram();
}
//=============================================================================
void HOMARD_Cas_i::MeshInfo(CORBA::Long Qual, CORBA::Long Diam, CORBA::Long Conn, CORBA::Long Tail, CORBA::Long Inte)
{
  MESSAGE ( "MeshInfo : information sur le maillage initial du cas" );
  ASSERT( myHomardCas );
//
// Nom de l'iteration
  char* IterName = GetIter0Name() ;
  CORBA::Long etatMenage = -1 ;
  CORBA::Long modeHOMARD = 7 ;
  CORBA::Long Option1 = 1 ;
  CORBA::Long Option2 = 1 ;
  if ( Qual != 0 ) { modeHOMARD = modeHOMARD*5 ; }
  if ( Diam != 0 ) { modeHOMARD = modeHOMARD*19 ; }
  if ( Conn != 0 ) { modeHOMARD = modeHOMARD*11 ; }
  if ( Tail != 0 ) { modeHOMARD = modeHOMARD*13 ; }
  if ( Inte != 0 ) { modeHOMARD = modeHOMARD*3 ; }
  CORBA::Long codret = _gen_i->Compute(IterName, etatMenage, modeHOMARD, Option1, Option2) ;
  MESSAGE ( "MeshInfo : codret = " << codret );
  return ;
}
//=============================================================================
//=============================================================================
// Liens avec les autres structures
//=============================================================================
//=============================================================================
char* HOMARD_Cas_i::GetIter0Name()
{
  ASSERT( myHomardCas );
  return CORBA::string_dup( myHomardCas->GetIter0Name().c_str() );
}
//=============================================================================
HOMARD::HOMARD_Iteration_ptr HOMARD_Cas_i::GetIter0()
{
// Nom de l'iteration initiale
  char* Iter0Name = GetIter0Name() ;
  MESSAGE ( "GetIter0 : Iter0Name      = " << Iter0Name );
  return _gen_i->GetIteration(Iter0Name) ;
}
//=============================================================================
HOMARD::HOMARD_Iteration_ptr HOMARD_Cas_i::NextIteration( const char* IterName )
{
// Nom de l'iteration parent
  char* NomIterParent = GetIter0Name() ;
  MESSAGE ( "NextIteration : IterName      = " << IterName );
  MESSAGE ( "NextIteration : NomIterParent = " << NomIterParent );
  return _gen_i->CreateIteration(IterName, NomIterParent) ;
}
//=============================================================================
HOMARD::HOMARD_Iteration_ptr HOMARD_Cas_i::LastIteration( )
{
  HOMARD::HOMARD_Iteration_ptr Iter ;
  HOMARD::listeIterFilles_var ListeIterFilles ;
  char* IterName ;
// Iteration initiale du cas
  IterName = GetIter0Name() ;
// On va explorer la descendance de cette iteration initiale
// jusqu'a trouver celle qui n'a pas de filles
  int nbiterfilles = 1 ;
  while ( nbiterfilles == 1 )
  {
// L'iteration associee
//     MESSAGE ( ".. IterName = " << IterName );
    Iter = _gen_i->GetIteration(IterName) ;
// Les filles de cette iteration
    ListeIterFilles = Iter->GetIterations() ;
    nbiterfilles = ListeIterFilles->length() ;
//     MESSAGE ( ".. nbiterfilles = " << nbiterfilles );
// S'il y a au moins 2 filles, arret : on ne sait pas faire
    ASSERT( nbiterfilles <= 1 ) ;
// S'il y a une fille unique, on recupere le nom de la fille et on recommence
    if ( nbiterfilles == 1 )
    { IterName = ListeIterFilles[0] ; }
  }
//
  return Iter ;
}
//=============================================================================
void HOMARD_Cas_i::AddIteration( const char* NomIteration )
{
  ASSERT( myHomardCas );
  myHomardCas->AddIteration( NomIteration );
}
