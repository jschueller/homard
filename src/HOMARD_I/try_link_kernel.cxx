#include "HOMARD_Gen_i.hxx"
#include "HOMARD_Cas_i.hxx"
#include "HOMARD_Hypothesis_i.hxx"
#include "HOMARD_Iteration_i.hxx"
#include "HOMARD_Boundary_i.hxx"
#include "HOMARD_Zone_i.hxx"
#include "HOMARD_YACS_i.hxx"
#include "HomardDriver.hxx"
#include "HOMARD_DriverTools.hxx"
#include "HomardMedCommun.h"
#include "YACSDriver.hxx"
#include "HOMARD.hxx"

#include "FrontTrack.hxx"

#include "HOMARD_version.h"

#include "utilities.h"
#include "Basics_Utils.hxx"
#include "Basics_DirUtils.hxx"
#include "Utils_SINGLETON.hxx"
#include "Utils_CorbaException.hxx"
#include "SALOMEDS_Tool.hxx"
#include "SALOME_LifeCycleCORBA.hxx"
#include "SALOMEconfig.h"
#include <SMESH_Gen_i.hxx>

#include <cmath>
#include <stdlib.h>
#include <sys/stat.h>
#ifndef WIN32
#include <dirent.h>
#endif
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include <vector>
#include <stdio.h>

#ifdef WIN32
#include <direct.h>
#endif

int main()
{
  std::cout << "try_link_kernel cout"<<std::endl;
  std::cerr << "try_link_kernel cerr"<<std::endl;
  INFOS("using INFOS ok");
  std::cerr << "try_link_kernel infos ok"<<std::endl;
  MESSAGE("using MESSAGE ok" );
  std::cerr << "try_link_kernel msg ok"<<std::endl;
  return 0;
}
