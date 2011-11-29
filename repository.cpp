#include "repository.h"
#include<iostream>
#include<sstream>

using namespace std;

Repository::Repository(const string repo_path = DEFAULT_REPO)
{
  repo_link.open(repo_path.c_str());
  total_packages = 0;
  string line;
  while(getline(repo_link,line))
  {
    total_packages++;
  }
  cout<<"Total Packages in the Repository are : "<<total_packages<<endl;
}

Repository::~Repository()
{
  repo_link.close();
}

bool Repository::exists_package(string pname)
{
  ifstream test_existance(("repo/packages/"+pname).c_str() );
  if(test_existance.good())
  {
    return true;
  }
  test_existance.close();
  return false;
}

bool Repository::is_virtual(string pname)
{
  //let us store the contents of a file into a string
  stringstream buffer;
  //this is known to be a virtual package
  ifstream fin("repo/packages/linux.description");
  buffer << fin.rdbuf();
  fin.close();
  const string virtual_package_string = buffer.str();
  //now we can compare the package description with this and check
  //erase the buffer so that we can reuse the same
  buffer.str(string());
  fin.open(("repo/packages/"+pname+".description").c_str());
  buffer << fin.rdbuf();
  fin.close();
  string package_description = buffer.str();
  //comparing the strings and returning the result
  if( virtual_package_string.compare(package_description) == 0 )
  {
    return true;
  }
  else
  {
    return false;
  }
}
