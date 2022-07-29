#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include <iostream>
namespace sdds {

class Utils {
   public:
    char* alcpy(const char* name);
    char* dynreadName(std::istream& istr);
    char* dynreadFullName(std::istream& istr);
};
extern Utils ut;
}  // namespace sdds

#endif