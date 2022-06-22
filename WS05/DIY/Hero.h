/////////////////////////////////////////////////////////
// WorkSho#5  :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 20
/////////////////////////////////////////////////////////
#ifndef SDDS_HERO_H
#define SDDS_HERO_H
#include <iostream>

#include "Power.h"

namespace sdds {
class Hero {
    char m_name[MAX_NAME_LENGTH + 1]{};
    Power* m_powerlist{};
    int m_num_powers{};
    int m_lv_powers{};

   public:
    Hero();
    Hero(const char* name, const Power* powerlist, const int num_powers);
    ~Hero();
    void setEmpty();
    void deallocate();

    Hero& set(const char* name, const Power* powerlist, const int num_powers);
    Hero& set_powerlevel(const Power* powerlist, const int num_powers);  // also update
    Hero& set_powerlist(const Power* powerlist);

    Hero& add_powerlist(Power* powerlist);
    Hero& operator+=(Power& powerlist);
    Hero& operator-=(const int value);

    std::ostream& display(std::ostream& os = std::cout) const;
    int get_powerlevel() const;
};

// helper function
bool operator<(const Hero& lhero, const Hero& rhero);
bool operator>(const Hero& lhero, const Hero& rhero);
void operator>>(Power& powerlist, Hero& hero);
void operator<<(Hero& hero, Power& powerlist);
std::ostream& operator<<(std::ostream& os, const Hero& hero);

}  // namespace sdds

#endif