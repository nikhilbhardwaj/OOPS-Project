#ifndef REPO_H
#define REPO_H
#include "package.h"
#include<set>
#include<string>
#include<fstream>

const std::string DEFAULT_REPO = "repo/packages_list.txt";

class Repository
{
  private:
    long total_packages;
    std::ifstream repo_link;
  public:
    Repository(const std::string);
    ~Repository();
    bool is_virtual(std::string);
    bool exists_package(std::string);
    std::set<std::string> find_package(std::string);
};

#endif //REPO_H
