#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<exception>
#include "commands.h"
using namespace std;

// Definition of the allowed commands
map<string,int> commands;


int main(int argc, char **argv)
{
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
        cout<<"Install";
        break;
      case UNINSTALL:
        cout<<"Remove logic comes here";
        break;
      case FIND:
        cout<<"Searching logic comes here";
        break;
      case PURGE:
        cout<<"Confirm and purge";
        break;
      case CURRENT_STATUS:
        cout<<"Inform current status";
        break;
      case VERSION:
        cout<<"Display versioning info";
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
