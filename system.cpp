#include "system.h"
#include<iostream>
#include<fstream>

using namespace std;

System::System()
{
  installed_packages.clear();
  ifstream fin("system.packages");
  string line;
  while(getline(fin,line))
  {
    installed_packages.insert(line);
  }
  fin.close();
}

void System::operator+(string pname)
{
  installed_packages.insert(pname);
  log.push_back("Added " + pname);
}

void System::operator-(string pname)
{
  if( installed_packages.erase(pname) )
    log.push_back("Removed " + pname);
}

void System::current_state()
{
  cout<<"Current System State:"<<endl;
  cout<<"Total Packages Currently Installed : "<<installed_packages.size()<<endl;
  if( !log.empty() )
  {
    cout<<"The recent transactions performed are listed below :"<<endl;
    for(int i=0; i<log.size() && i<5; ++i)
    {
      cout<<log[i]<<endl;
    }
  }

}

void System::purge_system()
{
  cout<<"Proceed with caution, this operation isn't reversible. All your packages will be uninstalled and your system will be restored to factory state."<<endl;
  cout<<"Press y to confirm....\t";
  char choice;
  cin>>choice;
  if( choice == 'y' )
  {
    installed_packages.clear();
    log.clear();
    cout<<"System successfully purged"<<endl;
  }
}

System::~System()
{
  ofstream fout("system.packages");
  for(set<string>::iterator sit = installed_packages.begin(); sit != installed_packages.end(); ++sit)
  {
    fout<<*sit<<endl;
  }
  fout.close();
}


