//  HOMARD HOMARD : implementaion of HOMARD idl descriptions
//
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
//  File   : HOMARD_Iteration.hxx
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

#ifndef _HOMARD_ITER_HXX_
#define _HOMARD_ITER_HXX_

#include <string>
#include <list>

class  HOMARD_Iteration
{
public:
  HOMARD_Iteration();
  ~HOMARD_Iteration();

// Generalites
  void                          SetName( const char* Name );
  std::string                   GetName() const;

  std::string                   GetDumpPython() const;

// Caracteristiques
  void                          SetDirName( const char* NomDir );
  std::string                   GetDirName() const;

  void                          SetNumber( int NumIter );
  int                           GetNumber() const;

  void                          SetEtat( bool etat );
  bool                          GetEtat() const;

  void                          SetMeshName( const char* NomMesh );
  std::string                   GetMeshName() const;

  void                          SetMeshFile( const char* MeshFile );
  std::string                   GetMeshFile() const;

  void                          SetFieldFile( const char* FieldFile );
  std::string                   GetFieldFile() const;
  void                          SetTimeStepRank( int TimeStep, int Rank );
  void                          SetTimeStepRankLast();
  int                           GetTimeStep() const;
  int                           GetRank() const;

  void                          SetLogFile( const char* LogFile );
  std::string                   GetLogFile() const;

  void                          SetFileInfo( const char* FileInfo );
  std::string                   GetFileInfo() const;

// Liens avec les autres iterations
  void                          LinkNextIteration( const char* NomIteration );
  void                          UnLinkNextIteration( const char* NomIteration );
  void                          UnLinkNextIterations();
  const std::list<std::string>& GetIterations() const;

  void                          SetIterParentName( const char* iterParent );
  std::string                   GetIterParentName() const;

// Liens avec les autres structures
  void                          SetCaseName( const char* NomCas );
  std::string                   GetCaseName() const;

  void                          SetHypoName( const char* NomHypo );
  std::string                   GetHypoName() const;

private:
  std::string                   _Name;
  bool                          _Etat;
  int                           _NumIter;
  std::string                   _NomMesh;
  std::string                   _MeshFile;
  std::string                   _FieldFile;
  int                           _TimeStep;
  int                           _Rank;
  std::string                   _LogFile;
  std::string                   _IterParent;
  std::string                   _NomHypo;
  std::string                   _NomCas;
  std::string                   _NomDir;
  std::list<std::string>        _mesIterFilles;
  std::string                   _FileInfo;
};

#endif
