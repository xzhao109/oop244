/////////////////////////////////////////////////////////
// WorkSho#8  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 20
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"

#include "iAccount.h"
using namespace std;

namespace sdds {
Account::Account(double balance) {
    if (balance < 0 || !balance) {
        m_balance = 0.0;
    } else {
        m_balance = balance;
    }
}
bool Account::credit(double deposit) {
    if (deposit > 0) {
        m_balance += deposit;
    }
    return m_balance;
}
bool Account::debit(double withdraw) {
    if (withdraw > 0) {
        m_balance -= withdraw;
    }
    return m_balance;
}
double Account::balance() const {
    return m_balance;
}
}  // namespace sdds