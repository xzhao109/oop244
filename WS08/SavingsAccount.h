/////////////////////////////////////////////////////////
// WorkSho#8  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 20
/////////////////////////////////////////////////////////
#ifndef SDDS_SAVINGSACCOUNT_H
#define SDDS_SAVINGSACCOUNT_H
#include <iostream>

#include "Account.h"
#include "iAccount.h"

namespace sdds {
class SavingsAccount : public Account {
    double m_interestRate{};

   public:
    SavingsAccount(double, double);
    void monthEnd();
    void display(std::ostream&) const;
};
}  // namespace sdds

#endif