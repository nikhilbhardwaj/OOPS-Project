#ifndef PACKAGE_MANAGER_H
#define PACKAGE_MANAGER_H

#include "repository.h"
#include "system.h"
#include<string>

//the packagemanager contains both the repository and the system
class PackageManager
{
  Repository* repository;
  System* system;
  PackageManager();
  public:
  PackageManager(Repository&, System&);
  void install_package(std::string);
  void remove_package(std::string);
  void remove_orphans();
  void search_for_package(std::string);
};

#endif //PACKAGE_MANAGER_H
