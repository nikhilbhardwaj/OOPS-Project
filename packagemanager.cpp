#include "packagemanager.h"
#include "concretepackage.h"
#include "metapackage.h"
#include<iostream>

using namespace std;

PackageManager::PackageManager(Repository& r, System& s)
{
  repository = &r;
  system = &s;
}

void PackageManager::install_package(string pname)
{
  if(repository->exists_package(pname))
  {
    Package *pkg;
    ConcretePackage *cpkg;
    MetaPackage *mpkg;
    if(repository->is_virtual(pname))
    {
      //code for dealing with meta packages
      mpkg = new MetaPackage(pname);
      pkg = mpkg;
      system->operator+(pname);
    }
    else
    {
      //code for dealing with concrete packages
      cpkg = new ConcretePackage(pname);
      pkg = cpkg;
      system->operator+(pname);
      set<string> deps = pkg->getDependencies();
      for(set<string>::iterator sit = deps.begin(); sit != deps.end();++sit)
       {
         //causes a wierd segmentation fault
         //string tmp_pack = *sit;
          //install_package(tmp_pack);
          system->operator+(*sit);
        }

    }
  }
  else
  {
    cout<<"Invalid Package Name"<<endl;
  }
}

void PackageManager::remove_package(string pname)
{
    if(repository->exists_package(pname))
  {
    system->operator-(pname);
  }
  else
  {
    cout<<"Invalid Package Name"<<endl;
  }

}

//this is left as a feature for the future
void PackageManager::remove_orphans()
{
}

void PackageManager::search_for_package(string pname)
{
  //we'll compare each of the strings with the repository
  ifstream fin("repo/packages_list.txt");
  string line;
  bool found_package = false;
  while(getline(fin,line))
  {
    size_t found = line.find(pname);
    if( found != string::npos)
    {
      cout<<line.substr(line.find(' '))<<endl;
      found_package |= true;
    }
  }
  fin.close();
  if( !found_package )
  {
    cout<<"No packages with that name found"<<endl;
  }
}
