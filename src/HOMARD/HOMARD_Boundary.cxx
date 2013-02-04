//  HOMARD HOMARD : implementaion of HOMARD idl descriptions
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
//  File   : HOMARD_Boundary.cxx
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

#include "HOMARD_Boundary.hxx"
#include "utilities.h"

//=============================================================================
/*!
 *  default constructor:
 */
//=============================================================================
HOMARD_Boundary::HOMARD_Boundary():
  _Name( "" ),_Type( 1 ),
  _Xmin( 0 ), _Xmax( 0 ), _Ymin( 0 ), _Ymax( 0 ), _Zmin( 0 ), _Zmax( 0 ),
  _Xaxe( 0 ), _Yaxe( 0 ), _Zaxe( 0 ),
  _Xcentre( 0 ), _Ycentre( 0 ), _Zcentre( 0 ), _rayon( 0 ),
  _Xincr( 0 ), _Yincr( 0 ), _Zincr( 0 )
{
  MESSAGE("HOMARD_Boundary");
}

//=============================================================================
HOMARD_Boundary::~HOMARD_Boundary()
{
  MESSAGE("~HOMARD_Boundary");
}
//=============================================================================
//=============================================================================
// Generalites
//=============================================================================
//=============================================================================
void HOMARD_Boundary::SetName( const char* Name )
{
  _Name = std::string( Name );
}
//=============================================================================
std::string HOMARD_Boundary::GetName() const
{
  return _Name;
}
//=============================================================================
std::string HOMARD_Boundary::GetDumpPython() const
{
  std::ostringstream aScript;
  aScript << "\n# Creation of the ";
//
  switch (_Type)
  {
    case 0:
    {
      aScript << "discrete boundary " << _Name << "\n";
      aScript << "\t" << _Name << " = homard.CreateBoundaryDi(\"" << _Name << "\", ";
      aScript << "\"" << _MeshName << "\", ";
      aScript << "\"" << _MeshFile << "\")\n";
      break ;
    }
    case 1:
    {
      aScript << "cylinder " << _Name << "\n";
      aScript << "\t" << _Name << " = homard.CreateBoundaryCylinder(\"" << _Name << "\", ";
      aScript << _Xcentre << ", " << _Ycentre << ", " << _Zcentre << ", " << _Xaxe << ", " << _Yaxe << ", " << _Zaxe << ", " << _rayon << ")\n";
      break ;
    }
    case 2:
    {
      aScript << "sphere" << _Name << "\n";
      aScript << "\t" << _Name << " = homard.CreateBoundarySphere(\"" << _Name << "\", ";
      aScript << _Xcentre << ", " << _Ycentre << ", " << _Zcentre << ", " << _rayon << ")\n";
      break ;
    }
  }

  return aScript.str();
}
//=============================================================================
//=============================================================================
// Caracteristiques
//=============================================================================
//=============================================================================
void HOMARD_Boundary::SetType( int Type )
{
  _Type = Type;
}
//=============================================================================
int HOMARD_Boundary::GetType() const
{
  return _Type;
}
//=============================================================================
void HOMARD_Boundary::SetMeshName( const char* MeshName )
{
  _MeshName = std::string( MeshName );
}
//=============================================================================
std::string HOMARD_Boundary::GetMeshName() const
{
  return _MeshName;
}
//=============================================================================
void HOMARD_Boundary::SetMeshFile( const char* MeshFile )
{
  _MeshFile = std::string( MeshFile );
}
//=============================================================================
std::string HOMARD_Boundary::GetMeshFile() const
{
  return _MeshFile;
}
//=======================================================================================
void HOMARD_Boundary::SetCylinder( double X0, double X1, double X2,
                                   double X3, double X4, double X5, double X6 )
{
  _Xcentre = X0; _Ycentre = X1;
  _Zcentre = X2; _Xaxe = X3;
  _Yaxe = X4; _Zaxe = X5;
  _rayon = X6;
}
//======================================================================
void HOMARD_Boundary::SetSphere( double X0, double X1, double X2, double X3 )
{
  _Xcentre = X0; _Ycentre = X1; _Zcentre = X2;
  _rayon = X3;
}
//=======================================================================================
std::vector<double> HOMARD_Boundary::GetCoords() const
{
  std::vector<double> mesCoor;
//
  switch (_Type)
  {
//  Cylindre
    case 1:
    {
      mesCoor.push_back( _Xcentre );
      mesCoor.push_back( _Ycentre );
      mesCoor.push_back( _Zcentre );
      mesCoor.push_back( _Xaxe );
      mesCoor.push_back( _Yaxe );
      mesCoor.push_back( _Zaxe );
      mesCoor.push_back( _rayon );
      break ;
    }
//  Sphere
    case 2:
    {
      mesCoor.push_back( _Xcentre );
      mesCoor.push_back( _Ycentre );
      mesCoor.push_back( _Zcentre );
      mesCoor.push_back( _rayon );
      break ;
    }
    ASSERT ( _Type == -1 ) ;
  }
  return mesCoor;
}
//======================================================================
void HOMARD_Boundary::SetLimit( double X0, double X1, double X2 )
{
  _Xincr = X0; _Yincr = X1; _Zincr = X2;
}
//=======================================================================================
std::vector<double> HOMARD_Boundary::GetLimit() const
{
  std::vector<double> mesLimit;
  mesLimit.push_back( _Xincr );
  mesLimit.push_back( _Yincr );
  mesLimit.push_back( _Zincr );
  return mesLimit;
}
//=============================================================================
void HOMARD_Boundary::AddGroup( const char* Group)
{
  _ListGroupSelected.push_back(Group);
}
//=============================================================================
void HOMARD_Boundary::SetGroups( const std::list<std::string>& ListGroup )
{
  _ListGroupSelected.clear();
  std::list<std::string>::const_iterator it = ListGroup.begin();
  while(it != ListGroup.end())
    _ListGroupSelected.push_back((*it++));
}
//=============================================================================
const std::list<std::string>& HOMARD_Boundary::GetGroups() const
{
  return _ListGroupSelected;
}
//=============================================================================
//=============================================================================
// Liens avec les autres structures
//=============================================================================
//=============================================================================
void HOMARD_Boundary::SetCaseCreation( const char* NomCasCreation )
{
  _NomCasCreation = std::string( NomCasCreation );
}
//=============================================================================
std::string HOMARD_Boundary::GetCaseCreation() const
{
  return _NomCasCreation;
}
//=============================================================================
