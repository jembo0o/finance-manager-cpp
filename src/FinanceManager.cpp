#include <iomanip>
#include "FinanceManager.h"
#include <iostream>

using namespace std;

std::string FinanceManager::askCurrency()
{
    int choice;

    cout << "Choose currency:" << endl;
    cout << "1. UAH" << endl;
    cout << "2. RON" << endl;
    cout << "3. EUR" << endl;
    cout << "4. USD" << endl;
    cout << "> ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        return "UAH";
    case 2:
        return "RON";
    case 3:
        return "EUR";
    case 4:
        return "USD";
    default:
        cout << "Invalid choice! Default currency: RON" << endl;
        return "RON";
    }
}

void FinanceManager::chooseCurrency()
{
    if (!currency.empty())
    {
        cout << "Currency is already selected: " << currency << endl;
        return;
    }

    currency = askCurrency();

    cout << "Currency selected: " << currency << endl;
}
void FinanceManager::changeCurrency()
{
    if (currency.empty())
    {
        chooseCurrency();
        return;
    }

    char answer;

    cout << "Current currency: " << currency << endl;
    cout << "Do you really want to change it? (y/n): ";
    cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        currency = askCurrency();
        cout << "Currency changed to: " << currency << endl;
    }
    else
    {
        cout << "Currency was not changed." << endl;
    }
}

void FinanceManager::showMenu()
{
    cout << fixed << setprecision(2);

    cout << endl;
    cout << "╔══════════════════════════════════════════════╗" << endl;
    cout << "║              FINANCE MANAGER                 ║" << endl;
    cout << "╠══════════════════════════════════════════════╣" << endl;
    cout << "║ Balance: " << wallet.getBalance() << " " << currency << endl;
    cout << "╠══════════════════════════════════════════════╣" << endl;
    cout << "║ 1 │ Add income                               ║" << endl;
    cout << "║ 2 │ Add expense                              ║" << endl;
    cout << "║ 3 │ Show history                             ║" << endl;
    cout << "║ 4 │ Change currency                          ║" << endl;
    cout << "║ 0 │ Exit                                     ║" << endl;
    cout << "╚══════════════════════════════════════════════╝" << endl;
    cout << "Choose option > ";
}
void FinanceManager::addIncome()
{
    double amount;
    int categoryChoice;
    string category;
    string description;

    cout << "\n╔════════════════════════════╗\n";
    cout << "║        ADD INCOME          ║\n";
    cout << "╚════════════════════════════╝\n";

   while (true)
   {
       cout << "\nAmount: ";
       cin >> amount;
       if (amount > 0)
       {
           break;
       }
       cout << "Invalid amount! Please enter a value greater than 0\n";
   }
    cin.ignore();
    while (true)
    {
        cout << "\nChoose category:\n";
        cout << "1. Salary\n";
        cout << "2. Freelance\n";
        cout << "3. Gift\n";
        cout << "4. Investment\n";
        cout << "5. Other\n";
        cout << "> ";
        cin >> categoryChoice;
        if (categoryChoice >= 1 && categoryChoice <= 5){ break; }
        cout << "\nInvalid option! Please try again.\n";
    }
    cin.ignore();
    switch (categoryChoice)
    {
    case 1:
        category = "Salary";
        break;
    case 2:
        category = "Freelance";
        break;
    case 3:
        category = "Gift";
        break;
    case 4:
        category = "Investment";
        break;
    case 5:
        category = "Other";
        break;
    }

    cout << "\nDescription ";
    getline(cin, description);

    Transaction income(amount, category, description, true);
    wallet.addTransaction(income);
    cout << "Income added successfully!\n";
}
void FinanceManager::addExpense()
{
    double amount;
    string category;
    string description;

    cout << "\n╔════════════════════════════╗\n";
    cout << "║        ADD EXPENSE         ║\n";
    cout << "╚════════════════════════════╝\n";

    cout << "Amount: ";
    cin >> amount;
    cin.ignore();

    cout << "Category: ";
    getline(cin, category);

    cout << "Description ";
    getline(cin, description);

    Transaction expense(amount, category, description, false);
    wallet.addTransaction(expense);
    cout << "Expense added successfully\n" << endl;

}











void FinanceManager::run()
{
    chooseCurrency();
    int choice;
    do
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            addIncome();
            break;
        case 2:
            addExpense();
            break;
        case 3:
            wallet.showHistory();
            break;
        case 4:
            changeCurrency();
            break;
        case 0:
            cout << "Goodbye !" << endl;
            break;
            default:
            cout << "Invalid option!" << endl;
            break;

        }
    }while (choice != 0);
}


