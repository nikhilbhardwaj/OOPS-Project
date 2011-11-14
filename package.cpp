#include "package.h"
#include<iostream>
#include<fstream>

using namespace std;

//constructs a package from the dump
Package::Package(string pname)
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
        cout<<line.substr(10)<<endl;

      }
      else if(line.find("Name:") != std::string::npos)
      {
        cout<<line.substr(5)<<endl;
      }
      else if(line.find("Version:") != std::string::npos)
      {
        cout<<line.substr(8)<<endl;
      }
      else if(line.length() != 0)
      {
        cout<<line.substr(5)<<endl;
      }

    }
  }
  else
  {
    cout<<"File not found Aborting...\n";
    exit(0);
  }

  freader.close();
}

