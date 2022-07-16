/////////////////////////////////////////////////////////
// WorkSho#7  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 15
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "MemberParliament.h"

#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

namespace sdds {
MemberParliament::MemberParliament(const char* id, const int age) {
    strcpy(m_district, "Unassigned");
    strcpy(m_id, id);
    m_age = age;
}
void MemberParliament::NewDistrict(const char* district) {
    cout << "|"
         << setw(8) << right << m_id << "| |"
         << setw(20) << right << m_district << " ---> "
         << setw(23) << left << district << "|" << endl;
    strcpy(m_district, district);
}
std::ostream& MemberParliament::write(std::ostream& os) const {
    os << "| " << m_id << " | " << m_age << " | " << m_district;
    return os;
}
std::istream& MemberParliament::read(std::istream& is) {
    cout << "Age: ";
    is >> m_age;
    cout << "Id: ";
    is >> m_id;
    cout << "District: ";
    is >> m_district;
    return is;
}
// helper functions
std::ostream& operator<<(std::ostream& os, const MemberParliament& mp) {
    return mp.write(os);
}
std::istream& operator>>(std::istream& is, MemberParliament& mp) {
    return mp.read(is);
}
}  // namespace sdds