#ifndef METAPACKAGE_H
#define METAPACKAGE_H

#include "package.h"

class MetaPackage : public Package
{
  public:
  bool install();
  bool remove();
};

#endif //METAPACKAGE_H
