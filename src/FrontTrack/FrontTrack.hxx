// File      : FrontTrack.hxx
// Created   : Tue Apr 25 17:08:52 2017
// Author    : Edward AGAPOV (eap)


#ifndef __FrontTrack_HXX__
#define __FrontTrack_HXX__

#include <vector>
#include <string>

class FrontTrack
{
public:

  /*!
   * \brief Relocate nodes to lie on geometry
   *  \param [in] theInputMedFile - a MED file holding a mesh including nodes that will be
   *         moved onto the geometry
   *  \param [in] theOutputMedFile - a MED file to create, that will hold a modified mesh
   *  \param [in] theInputNodeFiles - an array of names of files describing groups of nodes that
   *         will be moved onto the geometry
   *  \param [in] theXaoFileName - a path to a file in XAO format  holding the geometry and
   *         the geometrical groups.
   *  \param [in] theIsParallel - if \c true, all processors are used to treat boundary shapes
   *          in parallel.
   */
  void track( const std::string&                 theInputMedFile,
              const std::string&                 theOutputMedFile,
              const std::vector< std::string > & theInputNodeFiles,
              const std::string&                 theXaoFileName,
              bool                               theIsParallel=true);

};

#endif
