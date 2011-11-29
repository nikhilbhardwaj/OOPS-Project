#include "packagemanager.h"
#include "concretepackage.h"
#include "metapackage.h"
#include<iostream>
#include<algorithm>

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
      if( cpkg->getDependencies().size() > 0)
      {
        for(set<string>::iterator sit = pkg->getDependencies().begin(); sit != pkg->getDependencies().end();++sit)
       {
          cout<<*sit<<endl;
          system->operator+(*sit);
        }
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

void PackageManager::remove_orphans()
{
}

void PackageManager::search_for_package(string pname)
{
}

int main()
{
  Repository repo(DEFAULT_REPO);
  System sys;
  PackageManager pm(repo,sys);
  cout<<ConcretePackage("gcc-4.4").getDependencies().size();
  pm.install_package("gcc");
  return 0;
}
