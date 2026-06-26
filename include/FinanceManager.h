#pragma once
#include <string>
#include "Wallet.h"
class FinanceManager
{
private:
    Wallet wallet;

    void showMenu();
    void addIncome();
    void addExpense();
    std::string currency = "";
    std::string askCurrency();
    void chooseCurrency();
    void changeCurrency();
public:
    void run();

};