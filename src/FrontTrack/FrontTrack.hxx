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
   *  \param [in] inputMedFile - a MED file holding a mesh including nodes that will be
   *         moved onto the geometry
   *  \param [in] outputMedFile - a MED file to create, that will hold a modified mesh
   *  \param [in] nodeFiles - an array of names of files describing groups of nodes that
   *         will be moved onto the geometry
   *  \param [in] xaoFileName - a path to a file in XAO format  holding the geometry and
   *         the geometrical groups.
   *  \param [in] isParallel - if \c true, all processors are used to treat boundary shapes
   *          in parallel.
   */
  void track( const std::string&                 inputMedFile,
              const std::string&                 outputMedFile,
              const std::vector< std::string > & nodeFiles,
              const std::string&                 xaoFileName,
              bool                               isParallel=true);

};

#endif
