/////////////////////////////////////////////////////////
// WorkSho#9  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 29
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Utils.h"

#include <iostream>
#include <string>
using namespace std;

namespace sdds {
Utils ut;
int Utils::strlen(const char* str) const {
    int len;
    for (len = 0; str[len]; len++)
        ;
    return len;
}
char* Utils::strcpy(char* des, const char* src) const {
    int i;
    for (i = 0; src[i]; i++) des[i] = src[i];
    des[i] = char(0);
    return des;
}
char* Utils::alcpy(const char* name) {
    char* tmp;
    tmp = new char[strlen(name) + 1];
    strcpy(tmp, name);
    return tmp;
}
char* Utils::dynreadName(std::istream& istr) {
    char* tmp{};
    string sts;
    getline(istr, sts, ' ');
    if (istr) tmp = alcpy(sts.c_str());
    return tmp;
}
char* Utils::dynreadFullName(std::istream& istr) {
    char* tmp{};
    string sts;
    getline(istr, sts, '\n');
    if (istr) tmp = alcpy(sts.c_str());
    return tmp;
}
}  // namespace sdds