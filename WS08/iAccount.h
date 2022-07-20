/////////////////////////////////////////////////////////
// WorkSho#8  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 20
/////////////////////////////////////////////////////////
#ifndef SDDS_IACCOUNT_H
#define SDDS_IACCOUNT_H
#include <iostream>

namespace sdds {
class iAccount {
   public:
    virtual bool credit(double) = 0;
    virtual bool debit(double) = 0;
    virtual void monthEnd() = 0;
    virtual void display(std::ostream&) const = 0;
    virtual ~iAccount(){};
};
iAccount* CreateAccount(const char*, double);
}  // namespace sdds

#endif