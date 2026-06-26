#include <iostream>
#include "Wallet.h"
#include <vector>
using namespace std;

void Wallet::addTransaction(const Transaction& transaction)
{
    transactions.push_back(transaction);
}

double Wallet::getBalance()
{
    double balance = 0;
    for (const auto& transaction : transactions)
    {
        if (transaction.getIncome())
        {
            balance += transaction.getAmount();
        }
        else
        {
            balance -= transaction.getAmount();
        }
    }
    return balance;
}
void Wallet::showHistory()
{
    for (const auto& transaction : transactions)
    {
        if (transaction.getIncome() == true)
        {
            cout << " Income | ";
        }
        else
        {
            cout << "Expense | ";
        }
        cout << transaction.getCategory() << " | "
             << transaction.getDescription() << " | "
             << transaction.getAmount() << " | ";

    }

}