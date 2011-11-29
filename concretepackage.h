#ifndef CONCRETEPACKAGE_H
#define CONCRETEPACKAGE_H

#include "package.h"
#include<set>

class ConcretePackage : public Package
{
  //disabled default constructor
  ConcretePackage();
  public:
    ConcretePackage(std::string);
    virtual std::set<std::string> getDependencies();
    virtual std::string getName();
};

#endif //CONCRETEPACKAGE_H

