
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

struct Expense {
    string date;
    double amount;
    string category;
    string description;
};

vector<Expense> expenses;
const string FILE_NAME = "expenses.txt";

void saveData() {
    ofstream out(FILE_NAME);
    for (const auto& e : expenses) {
        out << e.date << "|" << e.amount << "|" << e.category << "|" << e.description << "\n";
    }
}

void loadData() {
    expenses.clear();
    ifstream in(FILE_NAME);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        Expense e;
        string amount;
        getline(ss, e.date, '|');
        getline(ss, amount, '|');
        getline(ss, e.category, '|');
        getline(ss, e.description);
        e.amount = stod(amount);
        expenses.push_back(e);
    }
}

void addExpense() {
    Expense e;
    cout << "Date (YYYY-MM-DD): ";
    cin >> e.date;
    cout << "Amount: ";
    cin >> e.amount;
    cin.ignore();
    cout << "Category: ";
    getline(cin, e.category);
    cout << "Description: ";
    getline(cin, e.description);
    expenses.push_back(e);
    saveData();
    cout << "Expense added.\n";
}

void viewExpenses() {
    if (expenses.empty()) {
        cout << "No expenses found.\n";
        return;
    }
    cout << "\nNo  Date         Amount     Category        Description\n";
    cout << "-------------------------------------------------------------\n";
    for (size_t i = 0;i < expenses.size();i++) {
        cout << left << setw(3) << i + 1
            << setw(13) << expenses[i].date
            << "$" << setw(10) << fixed << setprecision(2) << expenses[i].amount
            << setw(16) << expenses[i].category
            << expenses[i].description << "\n";
    }
}

void searchExpense() {
    cin.ignore();
    string key;
    cout << "Search: ";
    getline(cin, key);
    bool found = false;
    for (auto& e : expenses) {
        if (e.category.find(key) != string::npos || e.description.find(key) != string::npos) {
            cout << e.date << "  " << e.category << "  $" << e.amount << "  " << e.description << "\n";
            found = true;
        }
    }
    if (!found) cout << "No matching expense.\n";
}

void totalExpenses() {
    double total = 0;
    for (auto& e : expenses) total += e.amount;
    cout << "Total: $" << fixed << setprecision(2) << total << "\n";
}

void deleteExpense() {
    viewExpenses();
    if (expenses.empty()) return;
    int n;
    cout << "Delete number: ";
    cin >> n;
    if (n >= 1 && n <= expenses.size()) {
        expenses.erase(expenses.begin() + n - 1);
        saveData();
        cout << "Deleted.\n";
    }
    else {
        cout << "Invalid number.\n";
    }
}

int main() {
    loadData();
    int choice;
    do {
        cout << "\n===== EXPENSE TRACKER =====\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Search Expense\n";
        cout << "4. Calculate Total\n";
        cout << "5. Delete Expense\n";
        cout << "6. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:addExpense();break;
        case 2:viewExpenses();break;
        case 3:searchExpense();break;
        case 4:totalExpenses();break;
        case 5:deleteExpense();break;
        case 6:saveData();cout << "Goodbye!\n";break;
        default:cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
