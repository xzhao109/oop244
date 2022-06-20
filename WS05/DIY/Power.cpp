/////////////////////////////////////////////////////////
// WorkSho#5  :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 20
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Power.h"

#include <cstring>
#include <iostream>
using namespace std;

namespace sdds {
Power::Power() {
    this->setEmpty();
}
Power::Power(const char* name, int rarity) {
    this->createPower(name, rarity);
}
void Power::setEmpty() {
    m_name[0] = '\0';
    m_rarity = 0;
}
void Power::createPower(const char* name, int rarity) {
    if (name && name[0] != '\0' && rarity > 0) {
        strncpy(this->m_name, name, MAX_NAME_LENGTH);
        this->m_rarity = rarity;
    } else {
        this->setEmpty();
    }
}
const char* Power::checkName() const {
    return m_name;
}
int Power::checkRarity() const {
    return m_rarity;
}
bool Power::isEmpty() const {
    return (m_name[0] == '\0' || m_rarity == 0);
}
void displayDetails(Power* powers, int size) {
    cout << "List of available powers: " << endl;
    for (int i = 0; i < size; i++) {
        if (!powers[i].isEmpty()) {
            cout << "  Name: " << powers[i].checkName() << ", "
                 << "Rarity: " << powers[i].checkRarity() << endl;
        }
    }
}
}  // namespace sdds