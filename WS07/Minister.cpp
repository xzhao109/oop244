/////////////////////////////////////////////////////////
// WorkSho#7  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 15
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Minister.h"

#include <cstring>
#include <iostream>
using namespace std;

namespace sdds {
Minister::Minister(const char* id, const int age, const double year,
                   const char* name, const char* district)
    : MemberParliament{id, age} {             // call base(2 args) constructor
    MemberParliament::NewDistrict(district);  // call mp's method (reuse code)
    strcpy(m_name, name);
    m_year = year;
}
void Minister::changePM(const char* pm) {
    strcpy(m_name, pm);
}
void Minister::assumeOffice(double year) {
    m_year = year;
}
std::ostream& Minister::write(std::ostream& os) const {
    MemberParliament::write(os);
    os << " | " << m_name << "/" << m_year;
    return os;
}
std::istream& Minister::read(std::istream& is) {
    MemberParliament::read(is);
    cout << "Reports TO: ";
    is >> m_name;
    cout << "Year Assumed Office: ";
    is >> m_year;
    return is;
}
// helper functions
std::ostream& operator<<(std::ostream& os, const Minister& minister) {
    return minister.write(os);
}
std::istream& operator>>(std::istream& is, Minister& minister) {
    return minister.read(is);
}
}  // namespace sdds