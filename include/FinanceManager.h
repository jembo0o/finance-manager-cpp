#pragma once
#include <vector>
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
    double inputAmount();
    std::string inputDescription();
    std::string chooseCategory(const std::vector <std::string>& categories);

public:
    void run();

};