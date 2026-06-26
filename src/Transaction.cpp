#include "Transaction.h"
using namespace std;

Transaction::Transaction(double amount, std::string category, std::string description, bool income)
{
    this->amount = amount;
    this->category = category;
    this->description = description;
    this->income = income;
}
double Transaction::getAmount() const { return amount;}
std::string Transaction::getCategory() const { return category; }
std::string Transaction::getDescription() const { return description; }
bool Transaction::getIncome() const { return income; }

