//
// Created by Сергей on 24/06/2026.
//

#pragma once
#include <vector>
#include "Transaction.h"
class Wallet
{
private:
    std::vector<Transaction> transactions;
public:
    void addTransaction(const Transaction& transaction);
    double getBalance();
    void showHistory();
};