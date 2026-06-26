#include <iostream>
#include "Wallet.h"
#include "Transaction.h"
using namespace std;

int main()
{
    cout << "Finance $ manager started " << endl;
    Wallet wallet;
    Transaction salary(5000, "Salary", "June salary", true);

    Transaction food(250, "Food", "McDonalds", false);

    Transaction fuel(400, "Transport", "Gasoline", false);

    wallet.addTransaction(salary);
    wallet.addTransaction(food);
    wallet.addTransaction(fuel);
    cout << "Balance: " << wallet.getBalance() << endl;

    wallet.showHistory();
    return 0;
}