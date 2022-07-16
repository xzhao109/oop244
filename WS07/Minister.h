/////////////////////////////////////////////////////////
// WorkSho#7  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 15
/////////////////////////////////////////////////////////
#ifndef SDDS_MINISTER_H
#define SDDS_MINISTER_H
#include <iostream>

#include "MemberParliament.h"

namespace sdds {
const int MAX_NAME_LENGTH = 50;

class Minister : public MemberParliament {  // publicly inheriting 'mp'
    char m_name[MAX_NAME_LENGTH + 1]{};
    double m_year{};

   public:
    Minister(const char* id, const int age, const double year,
             const char* name, const char* district);
    void changePM(const char* pm);
    void assumeOffice(double year);
    std::ostream& write(std::ostream& os = std::cout) const;
    std::istream& read(std::istream& is = std::cin);
};

std::ostream& operator<<(std::ostream& os, const Minister& minister);
std::istream& operator>>(std::istream& is, Minister& minister);
}  // namespace sdds

#endif