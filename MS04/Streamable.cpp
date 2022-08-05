/////////////////////////////////////////////////////////
// Milestone  :  4
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Aug 5
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Streamable.h"
#include <iostream>
using namespace std;

namespace sdds {
std::ostream& operator<<(std::ostream& os, const Streamable& sm) {
    return sm.write(os);
}
std::istream& operator>>(std::istream& is, Streamable& sm) {
    return sm.read(is);
}
}  // namespace sdds