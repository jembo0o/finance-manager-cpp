#include <limits>
#include <iomanip>
#include "FinanceManager.h"
#include <iostream>

using namespace std;

int FinanceManager::inputNumber()
{
    int number;
    while (true)
    {
        cin >> number;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            cout << "> ";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return number;
    }
}



std::string FinanceManager::askCurrency()
{
    int choice;
    while (true)
    {
        cout << "Choose currency:" << endl;
        cout << "1. UAH" << endl;
        cout << "2. RON" << endl;
        cout << "3. EUR" << endl;
        cout << "4. USD" << endl;
        cout << "> ";
        choice = inputNumber();

        switch (choice)
        {
        case 1: return "UAH";
        case 2: return "RON";
        case 3: return "EUR";
        case 4: return "USD";
        default:
            cout << "Invalid option! Please try again.\n\n";
        }
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

double FinanceManager::inputAmount()
{
    double amount;

    while (true)
    {
        cout << "\nAmount: ";
        cin >> amount;

        // Проверяем: удалось ли cin прочитать число.
        // Например, если пользователь ввёл "abc", cin перейдёт в состояние ошибки.
        if (cin.fail())
        {
            // Сбрасываем состояние ошибки, иначе cin больше не сможет читать новые значения.
            cin.clear();

            // Удаляем весь неправильный ввод из буфера до Enter.
            // Например: пользователь ввёл "abc\n" — эта строка выбросит "abc\n".
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input! Please enter a number.\n";
            continue; // возвращаемся в начало цикла и спрашиваем сумму заново
        }

        // Число введено нормально, но оно не может быть нулём или отрицательным.
        if (amount <= 0)
        {
            cout << "Invalid amount! Please enter a value greater than 0.\n";
            continue;
        }

        // После cin >> amount в буфере остаётся Enter: '\n'.
        // Удаляем его, чтобы следующий getline() не прочитал пустую строку.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return amount;
    }
}
std::string FinanceManager::inputDescription()
{
    std::string description;
    cout << "\nDescription: ";
    getline(cin, description);

    return description;
}
std::string FinanceManager::chooseCategory(const std::vector<std::string>& categories)
{
    int categoryChoice;

    while (true)
    {
        cout << "\nChoose category:\n";

        for (int i = 0; i < categories.size(); i++)
        {
            cout << i + 1 << ". " << categories[i] << "\n";
        }
        cout << "> ";
        cin >> categoryChoice;
        // Если ввели буквы вместо числа
        if (cin.fail())
        {
            cin.clear();
            // Удаляем весь неправильный текст до Enter
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }
        // Если число есть, но его нет в списке категорий
        if (categoryChoice < 1 || categoryChoice > categories.size())
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid option! Please try again.\n";
            continue;
        }
        // После cin >> categoryChoice остаётся Enter.
        // Убираем его, чтобы getline() в inputDescription() нормально ждала текст.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return categories[categoryChoice - 1];
    }
}

void FinanceManager::addIncome()
{
    cout << "\n╔════════════════════════════╗\n";
    cout << "║        ADD INCOME          ║\n";
    cout << "╚════════════════════════════╝\n";
    double amount = inputAmount();
    vector<string> incomeCategories = {
        "Salary",
        "Freelance",
        "Gift",
        "Investment",
        "Other"
    };

    string category = chooseCategory(incomeCategories);
    string description = inputDescription();

    Transaction income(amount, category, description, true);
    wallet.addTransaction(income);
    cout << "Income added successfully!\n";
}
void FinanceManager::addExpense()
{
    cout << "\n╔════════════════════════════╗\n";
    cout << "║        ADD EXPENSE         ║\n";
    cout << "╚════════════════════════════╝\n";
    double amount = inputAmount();
    vector<string> expenseCategories = {
        "Food",
        "Transport",
        "Rent",
        "Entertainment",
        "Shopping",
        "Health",
        "Education",
        "Bills",
        "Other"
    };

    string category = chooseCategory(expenseCategories);
    string description = inputDescription();

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
        choice = inputNumber();
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
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid option! Please try again.\n";
            break;
        }
    } while (choice != 0);
}

