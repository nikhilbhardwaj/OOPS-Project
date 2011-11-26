#ifndef METAPACKAGE_H
#define METAPACKAGE_H

#include "package.h"

class MetaPackage : public Package
{
  //disabled default constructor
  MetaPackage();
  public:
  MetaPackage(std::string);
  virtual std::set<std::string> getDependencies();
  virtual std::string getName();
};

#endif //METAPACKAGE_H
