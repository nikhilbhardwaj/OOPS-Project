#ifndef SYSTEM_H
#define SYSTEM_H

#include<set>
#include<string>
#include<vector>

class System
{
  private:
    std::set<std::string> installed_packages;
    std::vector<std::string> log;
  public:
    System();
    ~System();
    void operator+(std::string);
    void operator-(std::string);
    void current_state();
    void purge_system();
};
#endif //SYSTEM_H
