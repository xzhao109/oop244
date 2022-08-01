/////////////////////////////////////////////////////////
// Milestone  :  3
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 29
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