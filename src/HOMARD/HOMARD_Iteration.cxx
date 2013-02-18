//  HOMARD HOMARD : implementation of HOMARD idl descriptions
//
// Copyright (C) 2011-2012  CEA/DEN, EDF R&D
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
//  File   : HOMARD_Iteration.cxx
//  Author : Paul RASCLE, EDF
//  Module : HOMARD
//
// Remarques :
// L'ordre de description des fonctions est le meme dans tous les fichiers
// HOMARD_aaaa.idl, HOMARD_aaaa.hxx, HOMARD_aaaa.cxx, HOMARD_aaaa_i.hxx, HOMARD_aaaa_i.cxx :
// 1. Les generalites : Name, Delete, DumpPython, Dump, Restore
// 2. Les caracteristiques
// 3. Le lien avec les autres structures
//
// Quand les 2 fonctions Setxxx et Getxxx sont presentes, Setxxx est decrit en premier

#include "HOMARD_Iteration.hxx"
#include "utilities.h"

//=============================================================================
/*!
 *  default constructor:
 */
//=============================================================================
HOMARD_Iteration::HOMARD_Iteration():
  _Name( "" ), _Etat( false ),
 _NumIter( -1 ),
  _NomMesh( "" ), _MeshFile( "" ),
  _FieldFile( "" ), _TimeStep( -1 ), _Rank( -1 ),
  _MessFile( "" ),
  _IterParent( "" ),
  _NomHypo( "" ), _NomCas( "" ), _NomDir( "" )
{
  MESSAGE("HOMARD_Iter");
}

//=============================================================================
/*!
 *
 */
//=============================================================================
HOMARD_Iteration::~HOMARD_Iteration()
{
  MESSAGE("~HOMARD_Iteration");
}
//=============================================================================
//=============================================================================
// Generalites
//=============================================================================
//=============================================================================
void HOMARD_Iteration::SetName( const char* Name )
{
  _Name = std::string( Name );
}
//=============================================================================
std::string HOMARD_Iteration::GetName() const
{
  return _Name;
}
//=============================================================================
std::string HOMARD_Iteration::GetDumpPython() const
{
  if (_IterParent == "") return std::string(" ") ;   // Pas de creation explicite de iteration 0";

  MESSAGE (". Ecriture de l iteration " << _Name );
  std::ostringstream aScript;
  aScript << "\n# Creation of the iteration " << _Name << "\n";
  if( _NumIter == 1 )
  {
       aScript << "\t" << _Name << " = " << _NomCas << ".NextIteration(\"" << _Name << "\")\n";
  }
   else
  {
       aScript << "\t" << _Name << " = " << _IterParent << ".NextIteration(\"" << _Name << "\")\n";
  }
// Le nom du maillage produit
//   MESSAGE (".. maillage produit " << _NomMesh );
  aScript << "\t" << _Name << ".SetMeshName(\"" << _NomMesh << "\")\n" ;
// Le fichier du maillage produit
  aScript << "\t" << _Name << ".SetMeshFile(\"" << _MeshFile << "\")\n";
// Le fichier des champs, avec l'instant eventuel
  if ( _FieldFile != "" ) {
    aScript << "\t" << _Name << ".SetFieldFile(\"" << _FieldFile << "\")\n";
    if ( _TimeStep == -2 ) {
      aScript << "\t" << _Name << ".SetTimeStepRankLast()\n";
    }
    else
    {
      if ( ( _TimeStep != -1 ) and ( _Rank != -1 ) ) {
        aScript << "\t" << _Name << ".SetTimeStepRank( " << _TimeStep << ", " << _Rank << " )\n";
      }
    }
  }

//   MESSAGE (".. Hypothese " << _NomHypo );
  aScript << "\t" << _Name << ".AssociateHypo(\"" << _NomHypo << "\")\n";

  if (_Etat == true)
  {
     aScript << "\tcodret = " <<_Name << ".Compute(1)\n";
  }
  else
  {
     aScript << "\t#codret = " <<_Name << ".Compute(1)\n";
  }
//   MESSAGE (". Fin de l ecriture de l iteration " << _Name );

  return aScript.str();
}
//=============================================================================
//=============================================================================
// Caracteristiques
//=============================================================================
//=============================================================================
void HOMARD_Iteration::SetDirName( const char* NomDir )
{
  _NomDir = std::string( NomDir );
}
//=============================================================================
std::string HOMARD_Iteration::GetDirName() const
{
   return _NomDir;
}
//=============================================================================
void HOMARD_Iteration::SetNumber( int NumIter )
{
  _NumIter = NumIter;
}
//=============================================================================
int HOMARD_Iteration::GetNumber() const
{
  return _NumIter;
}
//=============================================================================
void HOMARD_Iteration::SetEtat( bool etat )
{
  _Etat = etat;
}
//=============================================================================
bool HOMARD_Iteration::GetEtat() const
{
  return _Etat;
}
//=============================================================================
void HOMARD_Iteration::SetMeshName( const char* NomMesh )
{
  _NomMesh = std::string( NomMesh );
}
//=============================================================================
std::string HOMARD_Iteration::GetMeshName() const
{
  return _NomMesh;
}
//=============================================================================
void HOMARD_Iteration::SetMeshFile( const char* MeshFile )
{
  _MeshFile = std::string( MeshFile );
}
//=============================================================================
std::string HOMARD_Iteration::GetMeshFile() const
{
  return _MeshFile;
}
//=============================================================================
void HOMARD_Iteration::SetFieldFile( const char* FieldFile )
{
  _FieldFile = std::string( FieldFile );
}
//=============================================================================
std::string HOMARD_Iteration::GetFieldFile() const
{
  return _FieldFile;
}
//=============================================================================
void HOMARD_Iteration::SetTimeStepRank( int TimeStep, int Rank )
{
  _TimeStep = TimeStep;
  _Rank = Rank;
}
//=============================================================================
void HOMARD_Iteration::SetTimeStepRankLast()
{
  _TimeStep = -2;
}
//=============================================================================
int HOMARD_Iteration::GetTimeStep() const
{
  return _TimeStep;
}
//=============================================================================
int HOMARD_Iteration::GetRank() const
{
  return _Rank;
}
//=============================================================================
void HOMARD_Iteration::SetMessFile( const char* MessFile )
{
  _MessFile = std::string( MessFile );
}
//=============================================================================
std::string HOMARD_Iteration::GetMessFile() const
{
  return _MessFile;
}
//=============================================================================
//=============================================================================
// Liens avec les autres iterations
//=============================================================================
//=============================================================================
void HOMARD_Iteration::LinkNextIteration( const char* NomIteration )
{
  _mesIterFilles.push_back( std::string( NomIteration ) );
}
//=============================================================================
void HOMARD_Iteration::UnLinkNextIteration( const char* NomIteration )
{
  std::list<std::string>::iterator it = find( _mesIterFilles.begin(), _mesIterFilles.end(), NomIteration ) ;
  if ( it != _mesIterFilles.end() )
  {
    MESSAGE ("Dans UnLinkNextIteration pour " << NomIteration) ;
    _mesIterFilles.erase( it ) ;
  }
}
//=============================================================================
void HOMARD_Iteration::UnLinkNextIterations()
{
  _mesIterFilles.clear();
}
//=============================================================================
const std::list<std::string>& HOMARD_Iteration::GetIterations() const
{
  return _mesIterFilles;
}
//=============================================================================
void HOMARD_Iteration::SetIterParentName( const char* IterParent )
{
  _IterParent = IterParent;
}
//=============================================================================
std::string HOMARD_Iteration::GetIterParentName() const
{
  return _IterParent;
}
//=============================================================================
//=============================================================================
// Liens avec les autres structures
//=============================================================================
//=============================================================================
void HOMARD_Iteration::SetCaseName( const char* NomCas )
{
  _NomCas = std::string( NomCas );
}
//=============================================================================
std::string HOMARD_Iteration::GetCaseName() const
{
  return _NomCas;
}
//=============================================================================
void HOMARD_Iteration::SetHypoName( const char* NomHypo )
{
  _NomHypo = std::string( NomHypo );
}
//=============================================================================
std::string HOMARD_Iteration::GetHypoName() const
{
  return _NomHypo;
}
