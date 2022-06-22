/////////////////////////////////////////////////////////
// WorkSho#5  :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 20
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Hero.h"

#include <cstring>
#include <iostream>
using namespace std;

namespace sdds {
Hero::Hero() {
    setEmpty();
}
Hero::Hero(const char* name, const Power* powerlist, const int num_powers) {
    set(name, powerlist, num_powers);
    set_powerlevel(powerlist, num_powers);
}
Hero::~Hero() {
    deallocate();
}
void Hero::setEmpty() {
    m_name[0] = '\0';
    m_powerlist->setEmpty();
    m_num_powers = 0;
    m_lv_powers = 0;
}
void Hero::deallocate() {
    delete[] m_powerlist;
    m_powerlist = nullptr;
}

Hero& Hero::set(const char* name, const Power* powerlist, const int num_powers) {
    deallocate();
    if (name && name[0] && num_powers > 0) {
        strcpy(m_name, name);
        m_num_powers = num_powers;
        set_powerlist(powerlist);
    } else {
        setEmpty();
    }
    return *this;
}
Hero& Hero::set_powerlevel(const Power* powerlist, const int num_powers) {
    int sum_rarity{};
    for (int i = 0; i < num_powers; i++) {
        sum_rarity += powerlist[i].checkRarity();
    }
    m_lv_powers = sum_rarity * num_powers;
    return *this;
}
Hero& Hero::set_powerlist(const Power* powerlist) {
    deallocate();
    m_powerlist = new Power[m_num_powers + 1];
    for (int i = 0; i < m_num_powers; i++) {
        m_powerlist[i] = powerlist[i];
    }
    return *this;
}

Hero& Hero::add_powerlist(Power* powerlist) {
    m_powerlist[m_num_powers] = *powerlist;
    ++m_num_powers;
    set_powerlevel(m_powerlist, m_num_powers);  // update
    return *this;
}
Hero& Hero::operator+=(Power& powerlist) {
    add_powerlist(&powerlist);
    return *this;
}
Hero& Hero::operator-=(const int value) {
    m_lv_powers -= value;
    return *this;
}

std::ostream& Hero::display(std::ostream& os) const {
    cout.setf(std::ios::left);
    os << "Name: " << m_name << endl;
    displayDetails(m_powerlist, m_num_powers);
    os << "Power Level: " << m_lv_powers;
    return os;
}
int Hero::get_powerlevel() const {
    return m_lv_powers;
}

// helper function
bool operator<(const Hero& lhero, const Hero& rhero) {
    return lhero.get_powerlevel() - rhero.get_powerlevel() < 0;
}
bool operator>(const Hero& lhero, const Hero& rhero) {
    return lhero.get_powerlevel() - rhero.get_powerlevel() > 0;
}
void operator>>(Power& powerlist, Hero& hero) {
    hero += powerlist;
}
void operator<<(Hero& hero, Power& powerlist) {
    hero += powerlist;
}
std::ostream& operator<<(std::ostream& os, const Hero& hero) {
    return hero.display(os);
}

}  // namespace sdds
