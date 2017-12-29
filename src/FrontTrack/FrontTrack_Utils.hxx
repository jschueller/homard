// File      : FrontTrack_Utils.hxx
// Created   : Tue Apr 25 17:23:33 2017
// Author    : Edward AGAPOV (eap)

#ifndef __FrontTrack_Utils_HXX__
#define __FrontTrack_Utils_HXX__

#include "FrontTrack_Projector.hxx"

#include <vector>
#include <string>
#include <map>

namespace XAO {
  class Xao;
  class Group;
}

namespace FT_Utils
{
  // Check if a file exists
  bool fileExists( const std::string& path );

  // Check if a file can be created/overwritten
  bool canWrite( const std::string& path );

  // Transform anything printable to a string
  template< typename T> std::string toStr( const T& t )
  {
    std::ostringstream s;
    s << t;
    return s.str();
  }

  //--------------------------------------------------------------------------------------------
  /*!
   * \brief Return projectors by group name
   */
  struct XaoGroups
  {
    XaoGroups( const XAO::Xao* xao );

    int getProjectors( const std::string&                   groupName,
                       const int                            dim,
                       const std::vector< FT_Projector > &  allProjectors,
                       std::vector< const FT_Projector* > & groupProjectors ) const;
  private:

    typedef std::multimap< std::string, XAO::Group* > TGroupByNameMap;
    TGroupByNameMap _xaoGroups[ 2 ]; // by dim
  };
}

#endif
