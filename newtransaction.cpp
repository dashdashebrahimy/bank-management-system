#include<iostream>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

class Transaction :private account{
private:
    time_t timestamp;
    int amount;
    std::string type;

public:
    Transaction(int amount, const string &type);
    void recordTransaction();
    void display() const;
    void saveToFile(ofstream &outputFile);
    static void viewTransactionHistory(const vector<Transaction> &transactions);
};

Transaction::Transaction(int amount, const string &type) : timestamp(time(0)), amount(amount), type(type) {}

// Inside the recordTransaction function in Transaction class
void Transaction::recordTransaction() {
    if (type == "deposit") {
        depositMoney(getAccNum(), getBalance());  // Corrected the function call
    } else if (type == "withdraw") {
        withdrawMoney(getAccNum(), getBalance());  // Corrected the function call
    }

    cout << "Transaction recorded." << endl;

    // Save the transaction to a file
    ofstream outputFile("transactions.txt", ios::app); // Open file in append mode
    if (outputFile.is_open()) {
        saveToFile(outputFile);
        outputFile.close();
    } else {
        cerr << "Unable to open the file for writing." << endl;
    }
}

// Add the saveToFile function in Transaction class
void Transaction::saveToFile(ofstream &outputFile) {
    outputFile << "Timestamp: " << ctime(&timestamp);
    outputFile << "Amount: " << amount << "\n";
    outputFile << "Type: " << type << "\n";
    outputFile << "-----------------\n";
}

void Transaction::display() const {
    cout << "Timestamp: " << ctime(&timestamp);
    cout << "Amount: " << amount << "\n";
    cout << "Type: " << type << "\n";
    cout << "-----------------\n";
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
