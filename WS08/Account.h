/////////////////////////////////////////////////////////
// WorkSho#8  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 20
/////////////////////////////////////////////////////////
#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H
#include "iAccount.h"

namespace sdds {
class Account : public iAccount {
    double m_balance{};

   protected:
    double balance() const;

   public:
    Account(double);
    bool credit(double);
    bool debit(double);
};
}  // namespace sdds

#endif