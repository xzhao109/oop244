/////////////////////////////////////////////////////////
// WorkSho#8  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 20
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "ChequingAccount.h"

#include <iomanip>
#include <iostream>

#include "Account.h"
using namespace std;

namespace sdds {
ChequingAccount::ChequingAccount(double balance, double transactionFee, double monthlyFee)
    : Account{balance} {
    if (transactionFee > 0) {
        m_transactionFee = transactionFee;
    } else {
        m_transactionFee = 0.0;
    }
    if (monthlyFee > 0) {
        m_monthlyFee = monthlyFee;
    } else {
        m_monthlyFee = 0.0;
    }
}
bool ChequingAccount::credit(double deposit) {
    return Account::credit(deposit - m_transactionFee);
}
bool ChequingAccount::debit(double withdraw) {
    return Account::debit(withdraw + m_transactionFee);
}
void ChequingAccount::monthEnd() {
    Account::debit(m_monthlyFee);
}
void ChequingAccount::display(std::ostream&) const {
    cout << "Account type: Chequing"
         << fixed << setprecision(2)
         << "\nBalance: $" << Account::balance()
         << fixed << setprecision(2)
         << "\nPer Transaction Fee: " << m_transactionFee
         << fixed << setprecision(2)
         << "\nMonthly Fee: " << m_monthlyFee << '\n';
}
}  // namespace sdds