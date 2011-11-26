#include "metapackage.h"
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<sstream>

using namespace std;

//constructs a package from the dump
MetaPackage::MetaPackage(string pname)
{
  const string FILENAME = PACKAGES_DIR + pname;
  //the arguments to ifstream is a cstring and hence the conversion must be made
  ifstream freader;
  freader.open(FILENAME.c_str(),ios::in);
  if(freader)
  {
    for(string line;getline(freader,line);/* Nothing here */)
    {

      if(line.find("PackageId:") != std::string::npos)
      {
        package_id = atoi(line.substr(10).c_str());
      }
      else if(line.find("Name:") != std::string::npos)
      {
        name = line.substr(5);
      }
    }
    pack_version = "0.0";
    dependencies.clear();
    }
  else
  {
    cout<<"Package not found in the Repository Aborting...\n";
    exit(0);
  }

  freader.close();
}
//to get the name of the package
string MetaPackage::getName()
{
  return name;
}

//to get the list of dependencies
set<string> MetaPackage::getDependencies()
{
  return dependencies;
}
