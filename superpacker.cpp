#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<exception>
//header files specific to this project
#include "commands.h"
#include "package.h"
#include "concretepackage.h"
#include "metapackage.h"
#include "repository.h"
#include "system.h"
#include "packagemanager.h"
using namespace std;

// Definition of the allowed commands
map<string,int> commands;
//definition of local functions
void version_information();


int main(int argc, char **argv)
{
  //initialization of the system and the repo for the packagemanager
  System system;
  Repository repository(DEFAULT_REPO);
  PackageManager package_manager(repository,system);

  //setup the basic commands for the package manager
  string command;
  commands["install"] = INSTALL;
  commands["remove"] = UNINSTALL;
  commands["version"] = VERSION;
  commands["find"] = FIND;
  commands["purge"] = PURGE;
  commands["current-status"] = CURRENT_STATUS;
//exception handling for invalid invocation
  try{
    command = string(argv[1]);
    switch(commands[command])
    {
      case INSTALL:
        package_manager.install_package(string(argv[2]));
        break;
      case UNINSTALL:
        package_manager.remove_package(string(argv[2]));
        break;
      case FIND:
        package_manager.search_for_package(string(argv[2]));
        break;
      case PURGE:
        system.purge_system();
        break;
      case CURRENT_STATUS:
        system.current_state();
        break;
      case VERSION:
        version_information();
        break;
      default:
        throw string("Invalid argument passed");
        break;
    }
  }
  catch( ... )
  {
    string line;
    //Show the user the help file
    ifstream help_file("superpacker.help");
    while(getline(help_file,line))
    {
      cout<<line<<endl;
    }
    help_file.close();
  }

  return 0;
}

void version_information()
{
  ifstream version_file("version_info.text");
  string line;
  while(getline(version_file,line))
  {
    cout<<line<<endl;
  }
  version_file.close();
}
