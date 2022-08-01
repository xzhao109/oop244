/////////////////////////////////////////////////////////
// WorkSho#9  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 29
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "FullName.h"

#include <iostream>

#include "Utils.h"
using namespace std;

namespace sdds {
FullName::FullName(const char* name, const char* lastname) : Name{name} {
    if (lastname)
        m_value = ut.alcpy(lastname);
    else
        m_value = ut.alcpy("");
}
FullName::FullName(const FullName& fullname) : Name{fullname} {
    m_value = ut.alcpy(fullname.m_value);
}
FullName& FullName::operator=(const FullName& fullname) {
    Name::operator=(fullname);
    delete[] m_value;
    m_value = ut.alcpy(fullname.m_value);
    return *this;
}
FullName::~FullName() {
    delete[] m_value;
}
FullName::operator const char*() const {
    return (const char*)m_value;
}
FullName::operator bool() const {
    return m_value && Name::getName();
}
std::ostream& FullName::display(std::ostream& ostr) const {
    Name::display(ostr);
    ostr << " " << m_value;
    return ostr;
}
std::istream& FullName::read(std::istream& istr) {
    Name::read(istr);
    delete[] m_value;
    m_value = ut.dynreadFullName(istr);
    return istr;
}
std::ostream& operator<<(std::ostream& ostr, const FullName& fullname) {
    return fullname.display(ostr);
}
std::istream& operator>>(std::istream& istr, FullName& fullname) {
    return fullname.read(istr);
}
}  // namespace sdds