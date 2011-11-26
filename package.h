#ifndef PACKAGE_H
#define PACKAGE_H

#include<string>
#include<set>

const std::string PACKAGES_DIR = "repo/packages/";

class Package
{
  public:
    int package_id;
    std::string name,description,url,pack_version;
    std::set<std::string> dependencies;
    //Methods
    virtual ~Package(){};
    virtual std::set<std::string> getDependencies()=0;
    virtual std::string getName()=0;
};
#endif
