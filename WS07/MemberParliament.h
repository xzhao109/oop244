/////////////////////////////////////////////////////////
// WorkSho#7  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 15
/////////////////////////////////////////////////////////
#ifndef SDDS_MEMBERPARLIAMENT_H
#define SDDS_MEMBERPARLIAMENT_H
#include <iostream>

namespace sdds {
const int MAX_ID_LENGTH = 32;
const int MAX_DISTRICT_LENGTH = 64;

class MemberParliament {
    char m_id[MAX_ID_LENGTH + 1]{};
    char m_district[MAX_DISTRICT_LENGTH + 1]{};
    int m_age{};

   public:
    MemberParliament(const char* id, const int age);
    void NewDistrict(const char* district);
    std::ostream& write(std::ostream& os = std::cout) const;
    std::istream& read(std::istream& is = std::cin);
};

std::ostream& operator<<(std::ostream& os, const MemberParliament& mp);
std::istream& operator>>(std::istream& is, MemberParliament& mp);
}  // namespace sdds

#endif