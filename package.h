#ifndef PACKAGE_H
#define PACKAGE_H

#include<string>
#include<list>

typedef unsigned long int ull;
const std::string PACKAGES_DIR = "repo/packages/";

class Package
{
  ull package_id;
  std::string name,description,url;
  std::list<std::string> dependencies;
  // The default constructor is made private, this disables any package to be created without the proper arguments. Further this won't be implemented so any accidental call will cause a linker error.
  Package();
  public:
  Package(std::string);
  virtual bool install() = 0;
#endif
