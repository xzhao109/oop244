#include "Utils.h"

#include <iostream>
#include <string>
using namespace std;

namespace sdds {
Utils ut;
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