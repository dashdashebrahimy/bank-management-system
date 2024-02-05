#ifndef ACCOUNT
#define ACCOUNT
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#define ll long long
using namespace std;
class account
{
private:
    std::string accnum, word, balance;

public:
    std::string find_accnum(std::string username)
    {
        std::ifstream myfile;
        myfile.open("Customerinformation.txt");

        if (myfile.is_open())
        {
            while (myfile >> word)
            {
                if (word == username)
                {
                    for (int i = 0; i < 6; ++i)
                        myfile >> word;

                    accnum = word;
                    break;
                }
            }
        }
        else
        {
            std::cout << "The file could not be opened!";
        }

        myfile.close();
        return accnum;
    }

    std::string getbalance(std::string ccn)
    {
        std::ifstream myfile;
        myfile.open("accountNumbers.txt");

        if (myfile.is_open())
        {
            while (myfile >> word)
            {
                if (word == ccn)
                {
                    myfile >> word;
                    myfile >> word;
                    myfile >> word;
                    myfile >> word;
                    myfile >> word;
                    myfile >> word;
                    balance = word;
                    break;
                }
            }
        }
        else
        {
            std::cout << "The file could not be opened!";
        }

        myfile.close();
        return balance;
    }

    void withdraw_money(std::string accnum, std::string balance)
    {
        std::cout << "\n\n\t\t\t\tEnter the amount you want to withdraw: ";
        ll New_withdraw;
        std::cin >> New_withdraw;
        if (stoi(balance) >= New_withdraw)
        {
            ll balanceint = std::stoi(balance) - New_withdraw;
            std::cout << "Mission accomplished" << std::endl;
            balance = std::to_string(balanceint);
            ll num = std::stoi(accnum.substr(10, 4)) - 1;
            std::string originalFilePath = "accountNumbers.txt";
            ll lineNumber = num * 7 + 6;
            std::string newLineContent = "Balance : " + balance;
            std::ifstream originalFile("accountNumbers.txt");
            std::ofstream tempFile("temp.txt");

            if (originalFile.is_open() && tempFile.is_open())
            {
                std::string line;
                ll currentLineNumber = 0;

                while (currentLineNumber < lineNumber - 1 && std::getline(originalFile, line))
                {
                    tempFile << line << std::endl;
                    currentLineNumber++;
                }
                tempFile << newLineContent << std::endl;

                std::getline(originalFile, line);

                while (std::getline(originalFile, line))
                {
                    tempFile << line << std::endl;
                }
                std::remove("accountNumbers.txt");
                std::rename("temp.txt", "accountNumbers.txt");
            }
            else
            {
                std::cout << "Error opening files." << std::endl;
            }
            originalFile.close();
            tempFile.close();
        }
        else
        {
            cout << "The account balance is insufficient" << endl;
        }

        string x;
        cout << "\n\t\t\t"
             << "Press a key to go back : ";
        cin >> x;
        system("cls");
    }

    void deposit_money(std::string accnum, std::string balance)
    {
        std::cout << "\n\n\t\t\t\tEnter the amount you want to deposit: ";
        ll New_deposit;
        std::cin >> New_deposit;
        ll balanceint = std::stoi(balance) + New_deposit;
        std::cout << "Mission accomplished" << std::endl;
        balance = std::to_string(balanceint);
        ll num = std::stoi(accnum.substr(10, 4)) - 1;
        std::string originalFilePath = "accountNumbers.txt";
        ll lineNumber = num * 7 + 6;
        std::string newLineContent = "Balance : " + balance;
        std::ifstream originalFile("accountNumbers.txt");
        std::ofstream tempFile("temp.txt");

        if (originalFile.is_open() && tempFile.is_open())
        {
            std::string line;
            ll currentLineNumber = 0;

            while (currentLineNumber < lineNumber - 1 && std::getline(originalFile, line))
            {
                tempFile << line << std::endl;
                currentLineNumber++;
            }
            tempFile << newLineContent << std::endl;

            std::getline(originalFile, line);

            while (std::getline(originalFile, line))
            {
                tempFile << line << std::endl;
            }
            originalFile.close();
            tempFile.close();
            std::remove("accountNumbers.txt");
            std::rename("temp.txt", "accountNumbers.txt");
        }
        else
        {
            std::cout << "Error opening files." << std::endl;
        }
        string x;
        cout << "\n\t\t\t"
             << "Press a key to go back : ";
        cin >> x;
        system("cls");
    }
    std::string getAccNum() const
    {
        return accnum;
    }
    std::string getBalance() const
    {
        return balance;
    }
};
class Transaction : private account{
private:
    time_t timestamp;
    string amount;
    std::string type;

public:
    Transaction(const string& amount, const string &type);
    void recordTransaction();
    void display() const;
    void saveToFile(ofstream &outputFile);
    static void viewTransactionHistory(const vector<Transaction> &transactions);
};
Transaction::Transaction(const string& amount, const string &type) : timestamp(time(0)), amount(amount), type(type) {}
void Transaction::recordTransaction() {
    if (type == "deposit") {
        deposit_money(getAccNum(), getBalance());  
    } else if (type == "withdraw") {
        withdraw_money(getAccNum(), getBalance()); 
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
#endif
