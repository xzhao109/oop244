/////////////////////////////////////////////////////////
// WorkSho#9  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 29
/////////////////////////////////////////////////////////
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include <iostream>

namespace sdds {
class Utils {
   public:
    int strlen(const char* str) const;
    char* strcpy(char* des, const char* src) const;
    char* alcpy(const char* name);
    char* dynreadName(std::istream& istr);
    char* dynreadFullName(std::istream& istr);
};
extern Utils ut;
}  // namespace sdds

#endif