// File      : FrontTrack_NodeGroups.hxx
// Created   : Tue Apr 25 19:02:49 2017
// Author    : Edward AGAPOV (eap)

#ifndef __FrontTrack_NodeGroups_HXX__
#define __FrontTrack_NodeGroups_HXX__

#include "FrontTrack_NodesOnGeom.hxx"
#include "FrontTrack_Projector.hxx"

#include <vector>
#include <string>

namespace MEDCoupling {
  class DataArrayDouble;
}
namespace XAO {
  class Xao;
}

/*!
 * \brief Container of node groups.
 */
class FT_NodeGroups
{
public:

  // Load node groups from files
  void read( const std::vector< std::string >& nodeFiles,
             const XAO::Xao*                   xaoGeom,
             MEDCoupling::DataArrayDouble*     nodeCoords );

  // return number of groups of nodes to move
  int nbOfGroups() const { return _nodesOnGeom.size(); }

  // Move nodes of a group in parallel mode
  void operator() ( const int groupIndex ) const
  {
    const_cast< FT_NodeGroups* >( this )->projectAndMove( groupIndex );
  }

  // Project and move nodes of a given group of nodes
  void projectAndMove( const int groupIndex );

  // return true if all nodes were successfully relocated
  bool isOK() const;

  // print some statistics on node groups
  void dumpStat() const;

private:

  std::vector< FT_NodesOnGeom > _nodesOnGeom;
  std::vector< FT_Projector >   _projectors[2]; // curves and surfaces separately

};

#endif
