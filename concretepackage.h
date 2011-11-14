#ifndef CONCRETEPACKAGE_H
#define CONCRETEPACKAGE_H

#include "package.h"

class ConcretePackage : public Package
{
  public:
  bool install();
  bool remove();
};

#endif //CONCRETEPACKAGE_H

