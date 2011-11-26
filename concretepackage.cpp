#include "concretepackage.h"
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<sstream>

using namespace std;

//function to split the dependencies into the set
set<string> split(const string &s, char delim) {
    set<string> elems;
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim)) {
        elems.insert(item);
    }
    return elems;
}


//constructs a package from the dump
ConcretePackage::ConcretePackage(string pname)
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
      else if(line.find("Version:") != std::string::npos)
      {
        pack_version = line.substr(8);
      }
      else if(line.length() != 0)
      {
        dependencies = split(line.substr(5),',');
       //Debugging info
       /*   cout<<"Dependencies are\n";
        for(set<string>::iterator sit= dependencies.begin();sit != dependencies.end();++sit)
        {
          cout<<*sit<<endl;
        }
        */
      }

    }
  }
  else
  {
    cout<<"Package not found in the Repository Aborting...\n";
    exit(0);
  }

  freader.close();
}

//to get the name of the package
string ConcretePackage::getName()
{
  return name;
}

//to get the list of dependencies
set<string> ConcretePackage::getDependencies()
{
  return dependencies;
}
