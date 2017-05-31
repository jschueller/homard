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

  if ( !FT_Utils::fileExists( theInputMedFile ))
    throw std::invalid_argument( "Input MED file does not exist: " + theInputMedFile );

  if ( !FT_Utils::canWrite( theOutputMedFile ))
    throw std::invalid_argument( "Can't create the output MED file: " + theOutputMedFile );

  for ( size_t i = 0; i < theNodeFiles.size(); ++i )
    if ( !FT_Utils::fileExists( theNodeFiles[i] ))
      throw std::invalid_argument( "Input node file does not exist: " + theNodeFiles[i] );

  if ( !FT_Utils::fileExists( theXaoFileName ))
    throw std::invalid_argument( "Input XAO file does not exist: " + theXaoFileName );


  // read a mesh

  MEDCoupling::MCAuto< MEDCoupling::MEDFileUMesh >
    mfMesh( MEDCoupling::MEDFileUMesh::New( theInputMedFile ));
  if ( mfMesh.isNull() )
    throw std::invalid_argument( "Failed to read the input MED file: " + theInputMedFile );

  MEDCoupling::DataArrayDouble * nodeCoords = mfMesh->getCoords();
  if ( !nodeCoords || nodeCoords->empty() )
    throw std::invalid_argument( "No nodes in the input mesh" );


  // read a geometry

  XAO::Xao xao;
  if ( !xao.importXAO( theXaoFileName ) || !xao.getGeometry() )
    throw std::invalid_argument( "Failed to read the XAO input file: " + theXaoFileName );

  XAO::BrepGeometry* xaoGeom = dynamic_cast<XAO::BrepGeometry*>( xao.getGeometry() );
  if ( !xaoGeom || xaoGeom->getTopoDS_Shape().IsNull() )
    throw std::invalid_argument( "Failed to get a BREP shape from the XAO input file" );


  // read groups of nodes and associate them with boundary shapes using names (no projection so far)

  FT_NodeGroups nodeGroups;
  nodeGroups.read( theNodeFiles, &xao, nodeCoords );


  // project nodes to the boundary shapes and change their coordinates

  OSD_Parallel::For( 0, nodeGroups.nbOfGroups(), nodeGroups, !theIsParallel );

  // save the modified mesh

  const int erase = 2;
  mfMesh->write( theOutputMedFile, /*mode=*/erase );

  if ( !nodeGroups.isOK() )
    throw std::runtime_error("Unable to project some nodes");
}
