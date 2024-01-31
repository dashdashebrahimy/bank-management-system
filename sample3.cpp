//#include<conio.h>
//#include<stdio.h>
#include<iostream>
#include<cstring>
#include<fstream>
#include<vector>
#include<ctime>
using namespace std;

class Account{
	char name[100],add[100],y;
	int balance, amount;
	public:
		
		void deposite_money();
    	void withdraw_money ();
    	void display_account();
    	int getBalance() const; // Getter for balance
    	void setBalance(int newBalance); // Setter for balance
};

void Account::deposite_money()
{
    int a ;
    cout<<"Enter how much money you want to deposit::";
    cin>>a;
    balance+=a;
    cout<<"Your total deposit amount\n";
}
void Account::withdraw_money()
{
    cout<<"withdeaw ::";
    cout<<"Enter your amount for withdrawing ";
    cin>>amount;
    balance=balance-amount;
    cout<<"Now your total amount is left ::"<<balance;
}
void Account::display_account()
{
    cout<<"Enter the name ::"<<name<<endl;
    cout<<"Enterened your addees ::"<<add<<endl;
    cout<<"Type of account that you open ::"<<y<<endl;
    cout<<"Amount you deposite ::"<<balance<<endl;

}
int Account::getBalance() const {
    return balance;
}

void Account::setBalance(int newBalance) {
    balance = newBalance;
}

class User:public Account{
	
	char name[100],add[100],y;
//    int balance, amount;
    
    public:
//    	void open_account ();
    	
    void open_account();
    using Account::getBalance; // Bring the getBalance function into User class scope
    using Account::setBalance; // Bring the setBalance function into User class scope
};
void User::open_account()
{
    system("cls");
    cout<<"Enter your full name ::";
    cin.ignore();
    cin.getline(name,100);
    cout<<"Enter your addess ::";
    cin.ignore();
    cin.getline(add,100);
    cout<<"what type of account you want to open saving (s) or current (c)";
    cin>>y;
//    cout<<"Enter amount for deposite ::";
//    cin>>balance;
//    cout<<"Your account is created ";
	int initialBalance;
    cout << "Enter initial deposit amount: ";
    cin >> initialBalance;
    setBalance(initialBalance); // Use the setter function from the Account class
    
    cout << "Your account is created." << endl;
}

//class Transaction : public Account {
//private:
//    time_t timestamp;
//    int amount;
//    string type;
//
//public:
//    Transaction(int amount, const string &type);
//    void recordTransaction();
//    void display() const;
//    void saveToFile(ofstream &outputFile);
//    static void viewTransactionHistory(const vector<Transaction> &transactions);
//};
//
//Transaction::Transaction(int amount, const string &type) : timestamp(time(0)), amount(amount), type(type) {}
//
//void Transaction::recordTransaction() {
//    if (type == "Deposit") {
//        deposite_money(amount);
//    } else if (type == "Withdrawal") {
//        withdraw_money(amount);
//    }
//
//    cout << "Transaction recorded." << endl;
//}
//
//void Transaction::display() const {
//    cout << "Timestamp: " << ctime(&timestamp);
//    cout << "Amount: " << amount << "\n";
//    cout << "Type: " << type << "\n";
//    cout << "-----------------\n";
//}
//
//void Transaction::saveToFile(ofstream &outputFile) {
//    outputFile << timestamp << "\n";
//    outputFile << amount << "\n";
//    outputFile << type << "\n";
//}
//
//void Transaction::viewTransactionHistory(const vector<Transaction> &transactions) {
//    if (transactions.empty()) {
//        cout << "No transactions recorded." << endl;
//        return;
//    }
//
//    cout << "Transaction History:\n";
//    for (const auto &transaction : transactions) {
//        transaction.display();
//    }
//}
int main() {
    int ch, x;
    User user;

    do {
        cout << "01) Open account\n";
        cout << "02) Deposit money\n";
        cout << "03) Withdraw money\n";
        cout << "04) Display account\n";
        cout << "05) Exit\n";
        cout << "Please select an option: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Open account\n";
                user.open_account();
                break;
            case 2:
                cout << "Deposit money\n";
                user.deposite_money();
                break;
            case 3:
                cout << "Withdraw money\n";
                user.withdraw_money();
                break;
            case 4:
                cout << "Display account\n";
                user.display_account();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }

        cout << "\nDo you want to select the next step? (y/n): ";
        cin >> x;
    } while (x == 'y' || x == 'Y');

    return 0;
}