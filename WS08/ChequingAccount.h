/////////////////////////////////////////////////////////
// WorkSho#8  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 20
/////////////////////////////////////////////////////////
#ifndef SDDS_CHEQUINGACCOUNT_H
#define SDDS_CHEQUINGACCOUNT_H
#include <iostream>

#include "Account.h"
#include "iAccount.h"

namespace sdds {
class ChequingAccount : public Account {
    double m_transactionFee{};
    double m_monthlyFee{};

   public:
    ChequingAccount(double, double, double);
    bool credit(double);
    bool debit(double);
    void monthEnd();
    void display(std::ostream&) const;
};
}  // namespace sdds

#endif