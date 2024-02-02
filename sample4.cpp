#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

class Account {
protected:
    char name[100], add[100], y;
    int balance;

public:
    void deposit_money(int amount);
    void withdraw_money(int amount);
    void display_account();
    int getBalance() const;
    void setBalance(int newBalance);
};

void Account::deposit_money(int amount) {
    balance += amount;
    cout << "Your total deposit amount: " << balance << endl;
}

void Account::withdraw_money(int amount) {
    if (balance >= amount) {
        balance -= amount;
        cout << "Now your total amount is left: " << balance << endl;
    } else {
        cout << "Insufficient funds for withdrawal." << endl;
    }
}

void Account::display_account() {
    cout << "Name: " << name << endl;
    cout << "Entered your address: " << add << endl;
    cout << "Type of account that you opened: " << y << endl;
    cout << "Amount you deposited: " << balance << endl;
}

int Account::getBalance() const {
    return balance;
}

void Account::setBalance(int newBalance) {
    balance = newBalance;
}

class Transaction : public Account {
private:
    time_t timestamp;
    int amount;
    string type;

public:
    Transaction(int amount, const string &type);
    void recordTransaction();
    void display() const;
    void saveToFile(ofstream &outputFile);
    static void viewTransactionHistory(const vector<Transaction> &transactions);
};

Transaction::Transaction(int amount, const string &type) : timestamp(time(0)), amount(amount), type(type) {}

void Transaction::recordTransaction() {
    if (type == "Deposit") {
        deposit_money(amount);
    } else if (type == "Withdrawal") {
        withdraw_money(amount);
    }

    cout << "Transaction recorded." << endl;
}

void Transaction::display() const {
    cout << "Timestamp: " << ctime(&timestamp);
    cout << "Amount: " << amount << "\n";
    cout << "Type: " << type << "\n";
    cout << "-----------------\n";
}

void Transaction::saveToFile(ofstream &outputFile) {
    outputFile << timestamp << "\n";
    outputFile << amount << "\n";
    outputFile << type << "\n";
}

void Transaction::viewTransactionHistory(const vector<Transaction> &transactions) {
    if (transactions.empty()) {
        cout << "No transactions recorded." << endl;
        return;
    }

    cout << "Transaction History:\n";
    for (const auto &transaction : transactions) {
        transaction.display();
    }
}

class User : public Account {
public:
    void open_account();
};

void User::open_account() {
    cout << "Enter your full name: ";
    cin.ignore();
    cin.getline(name, 100);
    cout << "Enter your address: ";
    cin.getline(add, 100);
    cout << "What type of account you want to open (s for saving, c for current): ";
    cin >> y;

    int initialBalance;
    cout << "Enter initial deposit amount: ";
    cin >> initialBalance;
    setBalance(initialBalance);

    cout << "Your account is created." << endl;
}

int main() {
    vector<Transaction> transactions;
    User user;

    int ch;
    do {
        cout << "01) Deposit money\n";
        cout << "02) Withdraw money\n";
        cout << "03) Display account\n";
        cout << "04) View transaction history\n";
        cout << "05) Open account\n";
        cout << "06) Exit\n";
        cout << "Please select an option: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                int depositAmount;
                cout << "Enter the amount to deposit: ";
                cin >> depositAmount;

                Transaction depositTransaction(depositAmount, "Deposit");
                depositTransaction.recordTransaction();
                transactions.push_back(depositTransaction);
                break;
            }
            case 2: {
                int withdrawalAmount;
                cout << "Enter the amount to withdraw: ";
                cin >> withdrawalAmount;

                Transaction withdrawalTransaction(withdrawalAmount, "Withdrawal");
                withdrawalTransaction.recordTransaction();
                transactions.push_back(withdrawalTransaction);
                break;
            }
            case 3:
                user.display_account();
                break;
            case 4:
                Transaction::viewTransactionHistory(transactions);
                break;
            case 5:
                user.open_account();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }

    } while (ch != 6);

    return 0;
}
