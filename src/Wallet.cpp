#include <iostream>
#include "Wallet.h"
#include <vector>
#include <iomanip>
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
    cout << fixed << setprecision(2);

    cout << "\n╔════╦══════════╦══════════════╦══════════════╦════════════════════╗\n";
    cout << "║ ID ║ Type     ║ Category     ║ Amount       ║ Description        ║\n";
    cout << "╠════╬══════════╬══════════════╬══════════════╬════════════════════╣\n";

    int id = 1;

    for (const auto& transaction : transactions)
    {
        string type;

        if (transaction.getIncome())
        {
            type = "Income";
        }
        else
        {
            type = "Expense";
        }

        cout << "║ "
             << setw(2) << id << " ║ "
             << left << setw(8) << type << " ║ "
             << left << setw(12) << transaction.getCategory() << " ║ "
             << right << setw(12) << transaction.getAmount() << " ║ "
             << left << setw(18) << transaction.getDescription() << " ║\n";

        id++;
    }

    cout << "╚════╩══════════╩══════════════╩══════════════╩════════════════════╝\n";
}