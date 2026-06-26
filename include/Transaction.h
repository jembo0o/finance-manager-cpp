//
// Created by Сергей on 24/06/2026.
//
#pragma once
#include <string>

class Transaction
{
private:
    double amount;
    std::string category;
    std::string description;
    bool income;
public:
    Transaction(double amount, std::string category, std::string description, bool income);
    double getAmount() const;
    std::string getCategory() const;
    std::string getDescription() const;
    bool getIncome() const;

};

