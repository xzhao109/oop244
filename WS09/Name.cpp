/////////////////////////////////////////////////////////
// WorkSho#9  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 29
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Name.h"

#include <iostream>

#include "Utils.h"
using namespace std;

namespace sdds {
Name::Name(const char* name) {
    if (name) {
        m_value = ut.alcpy(name);
    } else {
        m_value = ut.alcpy("");
    }
}
Name::Name(const Name& name) {
    operator=(name);
}
Name& Name::operator=(const Name& name) {
    if (this != &name) {
        delete[] m_value;
        m_value = ut.alcpy(name.m_value);
    }
    return *this;
}
Name::~Name() {
    delete[] m_value;
}
const char* Name::getName() const {
    return m_value;
}
Name::operator const char*() const {
    return (const char*)m_value;
}
Name::operator bool() const {
    return m_value;
}
std::ostream& Name::display(std::ostream& ostr) const {
    return ostr << m_value;
}
std::istream& Name::read(std::istream& istr) {
    delete[] m_value;
    m_value = ut.dynreadName(istr);
    return istr;
}
std::ostream& operator<<(std::ostream& ostr, const Name& name) {
    return name.display(ostr);
}
std::istream& operator>>(std::istream& istr, Name& name) {
    return name.read(istr);
}
}  // namespace sdds