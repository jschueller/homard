#include "HOMARD_Zone_i.hxx"
#include "HOMARD_Gen_i.hxx"
#include "HOMARD_Zone.hxx"
#include "HOMARD_DriverTools.hxx"

#include "utilities.h"

//=============================================================================
/*!
 *  standard constructor
 */
//=============================================================================
HOMARD_Zone_i::HOMARD_Zone_i()
{
  MESSAGE( "Default constructor, not for use" );
  ASSERT( 0 );
}

//=============================================================================
/*!
 *  standard constructor
 */
//=============================================================================
HOMARD_Zone_i::HOMARD_Zone_i( CORBA::ORB_ptr orb,
			      HOMARD::HOMARD_Gen_var engine )
{
  MESSAGE( "HOMARD_Zone_i" );
  _gen_i = engine;
  _orb = orb;
  myHomardZone = new ::HOMARD_Zone();
  ASSERT( myHomardZone );
}
//=============================================================================
/*!
 *  standard destructor
 */
//=============================================================================

HOMARD_Zone_i::~HOMARD_Zone_i()
{
}

//=============================================================================
/*!
 */
//=============================================================================
void HOMARD_Zone_i::SetName( const char* NomZone )
{
  ASSERT( myHomardZone );
  myHomardZone->SetName( NomZone );
}

//=============================================================================
char* HOMARD_Zone_i::GetName()
{
  ASSERT( myHomardZone );
  return CORBA::string_dup( myHomardZone->GetName().c_str() );
}

//=============================================================================
char* HOMARD_Zone_i::GetDumpPython()
{
  ASSERT( myHomardZone );
  return CORBA::string_dup( myHomardZone->GetDumpPython().c_str() );
}


//=============================================================================
void HOMARD_Zone_i::SetZoneType( CORBA::Long ZoneType )
{
  ASSERT( myHomardZone );
  myHomardZone->SetZoneType( ZoneType );
}

//=============================================================================
CORBA::Long HOMARD_Zone_i::GetZoneType()
{
  ASSERT( myHomardZone );
  return  CORBA::Long( myHomardZone->GetZoneType() );
}

//=============================================================================
void HOMARD_Zone_i::SetBox( double X0, double X1, double X2, double X3, double X4, double X5 )
{
  ASSERT( myHomardZone );
  myHomardZone->SetBox( X0, X1, X2, X3, X4, X5 );
}

//=============================================================================
HOMARD::double_array* HOMARD_Zone_i::GetBox()
{
  ASSERT( myHomardZone );
  HOMARD::double_array_var aResult = new HOMARD::double_array();
  std::vector<double> mesCoor = myHomardZone->GetBox();
  aResult->length( mesCoor .size() );
  std::vector<double>::const_iterator it;
  int i = 0;
  for ( it = mesCoor.begin(); it != mesCoor.end(); it++ )
    aResult[i++] = (*it);
  return aResult._retn();
}

//=============================================================================
void HOMARD_Zone_i::SetSphere( double Xcentre, double Ycentre, double ZCentre, double rayon )
{
  ASSERT( myHomardZone );
  myHomardZone->SetSphere( Xcentre, Ycentre, ZCentre, rayon );
}

//=============================================================================
HOMARD::double_array* HOMARD_Zone_i::GetSphere()
{
  ASSERT( myHomardZone );
  HOMARD::double_array_var aResult = new HOMARD::double_array();
  std::vector<double> mesCoor = myHomardZone->GetSphere();
  aResult->length( mesCoor .size() );
  std::vector<double>::const_iterator it;
  int i = 0;
  for ( it = mesCoor.begin(); it != mesCoor.end(); it++ )
    aResult[i++] = (*it);
  return aResult._retn();
}

//=============================================================================
void HOMARD_Zone_i::SetLimit( double Xincr, double Yincr, double Zincr )
{
  MESSAGE ("SetLimit, Xincr : " << Xincr << ", Yincr : " << Yincr << ", Zincr : " << Zincr) ;
  ASSERT( myHomardZone );
  myHomardZone->SetLimit( Xincr, Yincr, Zincr );
}

//=============================================================================
HOMARD::double_array* HOMARD_Zone_i::GetLimit()
{
  ASSERT( myHomardZone );
  HOMARD::double_array_var aResult = new HOMARD::double_array();
  std::vector<double> mesCoor = myHomardZone->GetLimit();
  aResult->length( mesCoor .size() );
  std::vector<double>::const_iterator it;
  int i = 0;
  for ( it = mesCoor.begin(); it != mesCoor.end(); it++ )
    aResult[i++] = (*it);
  return aResult._retn();
}

//=============================================================================
void HOMARD_Zone_i::AddHypo( const char* NomHypo )
{
  ASSERT( myHomardZone );
  myHomardZone->AddHypo( NomHypo );
}

//=============================================================================
void HOMARD_Zone_i::SupprHypo( const char* NomHypo )
{
  ASSERT( myHomardZone );
  myHomardZone->SupprHypo( NomHypo );
}
//=============================================================================
HOMARD::listeHypo* HOMARD_Zone_i::GetHypo()
{
  ASSERT( myHomardZone );
  const std::list<std::string>& maListe = myHomardZone->GetHypo();
  HOMARD::listeHypo_var aResult = new HOMARD::listeHypo;
  aResult->length( maListe.size() );
  std:: list<std::string>::const_iterator it;
  int i = 0;
  for ( it = maListe.begin(); it != maListe.end(); it++ )
    aResult[i++] = CORBA::string_dup( (*it).c_str() );
  return aResult._retn();
}

//=============================================================================
std::string HOMARD_Zone_i::Dump() const
{
  return HOMARD::Dump( *myHomardZone );
}

//=============================================================================
bool HOMARD_Zone_i::Restore( const std::string& stream )
{
  return HOMARD::Restore( *myHomardZone, stream );
}
