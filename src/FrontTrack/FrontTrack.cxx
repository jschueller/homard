// File      : FrontTrack.cxx
// Created   : Tue Apr 25 17:20:28 2017
// Author    : Edward AGAPOV (eap)

#include "FrontTrack.hxx"
#include "FrontTrack_NodeGroups.hxx"
#include "FrontTrack_Utils.hxx"

#include <MCAuto.hxx>
#include <MEDCouplingMemArray.hxx>
#include <MEDFileMesh.hxx>

#include <XAO_Xao.hxx>
#include <XAO_BrepGeometry.hxx>

#include <stdexcept>

#include <OSD_Parallel.hxx>

/*!
 * \brief Relocate nodes to lie on geometry
 *  \param [in] theInputMedFile - a MED file holding a mesh including nodes that will be
 *         moved onto the geometry
 *  \param [in] theOutputMedFile - a MED file to create, that will hold a modified mesh
 *  \param [in] theNodeFiles - an array of names of files describing groups of nodes that
 *         will be moved onto the geometry
 *  \param [in] theXaoFileName - a path to a file in XAO format holding the geometry and
 *         the geometrical groups.
 *  \param [in] theIsParallel - if \c true, all processors are used to treat boundary shapes
 *          in parallel.
 */
void FrontTrack::track( const std::string&                 theInputMedFile,
                        const std::string&                 theOutputMedFile,
                        const std::vector< std::string > & theNodeFiles,
                        const std::string&                 theXaoFileName,
                        bool                               theIsParallel )
{
  // check arguments

  if ( theNodeFiles.empty() )
    return;

#ifdef _DEBUG_
  std::cout << "Input MED file:" << theInputMedFile << std::endl;
#endif
  if ( !FT_Utils::fileExists( theInputMedFile ))
    throw std::invalid_argument( "Input MED file does not exist: " + theInputMedFile );

#ifdef _DEBUG_
  std::cout << "Output MED file:" << theOutputMedFile << std::endl;
#endif
  if ( !FT_Utils::canWrite( theOutputMedFile ))
    throw std::invalid_argument( "Can't create the output MED file: " + theOutputMedFile );

  for ( size_t i = 0; i < theNodeFiles.size(); ++i )
  {
#ifdef _DEBUG_
    std::cout << "Input node file:" << theNodeFiles[i] << std::endl;
#endif
    if ( !FT_Utils::fileExists( theNodeFiles[i] ))
      throw std::invalid_argument( "Input node file does not exist: " + theNodeFiles[i] );
  }

#ifdef _DEBUG_
  std::cout << "XAO file:" << theXaoFileName << std::endl;
#endif
  if ( !FT_Utils::fileExists( theXaoFileName ))
    throw std::invalid_argument( "Input XAO file does not exist: " + theXaoFileName );


  // read a mesh

#ifdef _DEBUG_
  std::cout << "Lecture du maillage" << std::endl;
#endif
  MEDCoupling::MCAuto< MEDCoupling::MEDFileUMesh >
    mfMesh( MEDCoupling::MEDFileUMesh::New( theInputMedFile ));
  if ( mfMesh.isNull() )
    throw std::invalid_argument( "Failed to read the input MED file: " + theInputMedFile );

  MEDCoupling::DataArrayDouble * nodeCoords = mfMesh->getCoords();
  if ( !nodeCoords || nodeCoords->empty() )
    throw std::invalid_argument( "No nodes in the input mesh" );


  // read a geometry

#ifdef _DEBUG_
  std::cout << "Lecture de la geometrie" << std::endl;
#endif
  XAO::Xao xao;
  if ( !xao.importXAO( theXaoFileName ) || !xao.getGeometry() )
    throw std::invalid_argument( "Failed to read the XAO input file: " + theXaoFileName );

#ifdef _DEBUG_
  std::cout << "Conversion en BREP" << std::endl;
#endif
  XAO::BrepGeometry* xaoGeom = dynamic_cast<XAO::BrepGeometry*>( xao.getGeometry() );
  if ( !xaoGeom || xaoGeom->getTopoDS_Shape().IsNull() )
    throw std::invalid_argument( "Failed to get a BREP shape from the XAO input file" );


  // read groups of nodes and associate them with boundary shapes using names (no projection so far)

#ifdef _DEBUG_
  std::cout << "Lecture des groupes" << std::endl;
#endif
  FT_NodeGroups nodeGroups;
  nodeGroups.read( theNodeFiles, &xao, nodeCoords );
#ifdef _DEBUG_
  std::cout << "Nombre de groupes : " << nodeGroups.nbOfGroups() << std::endl;
#endif

  // project nodes to the boundary shapes and change their coordinates

#ifdef _DEBUG_
  std::cout << "Projection des noeuds, theIsParallel=" << theIsParallel << std::endl;
#endif
  OSD_Parallel::For( 0, nodeGroups.nbOfGroups(), nodeGroups, !theIsParallel );

  // save the modified mesh

#ifdef _DEBUG_
  std::cout << "Ecriture du maillage" << std::endl;
#endif
  const int erase = 2;
  mfMesh->write( theOutputMedFile, /*mode=*/erase );

  if ( !nodeGroups.isOK() )
    throw std::runtime_error("Unable to project some nodes");
}