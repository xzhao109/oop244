/////////////////////////////////////////////////////////
// WorkSho#8  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 20
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "SavingsAccount.h"

#include <iomanip>
#include <iostream>

#include "Account.h"
using namespace std;

namespace sdds {
SavingsAccount::SavingsAccount(double balance, double interestRate)
    : Account{balance} {
    if (interestRate > 0) {
        m_interestRate = interestRate;
    } else {
        m_interestRate = 0.0;
    }
}
void SavingsAccount::monthEnd() {
    Account::credit(Account::balance() * m_interestRate);
}
void SavingsAccount::display(std::ostream&) const {
    cout << "Account type: Savings"
         << fixed << setprecision(2)
         << "\nBalance: $" << Account::balance()
         << fixed << setprecision(2)
         << "\nInterest Rate (%): " << m_interestRate * 100 << '\n';
}
}  // namespace sdds