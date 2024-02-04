#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
// #include "user.h"
// #include "account.h"
using namespace std;

class user
{
private:
    string Fname, Lname, DOBirth, mob, username, password, repassword, E_mail, ans, acnum, type;

    int age, i, number;

    vector<string> usernames;

    void USERS()
    {

        ifstream read_CustInfo;

        read_CustInfo.open("Customerinformation.txt");

        if (read_CustInfo.is_open())
        {
            string word;

            while (read_CustInfo >> word)
            {

                if (word == "username")
                {
                    read_CustInfo >> word;

                    read_CustInfo >> word;

                    usernames.push_back(word);
                }
            }
        }

        else

            cout << "the file could not be opened!";

        read_CustInfo.close();
    }
    char username_check(string s1)
    {
        int i, m = 0;

        for (i = 0; i < usernames.size(); i++)
        {
            if (usernames.at(i) == s1)

                m++;
        }

        if (m == 0)

            return 'N';

        else

            return 'Y';
    }
    char password_check(string s1, string s2)
    {
        int i, m = 0;

        if (s1.size() != s2.size())

            return 'N';

        else
        {
            for (i = 0; i < s1.size(); i++)
            {
                if (s1[i] == s2[i])

                    m++;
            }
            if (m == s1.size())

                return 'Y';

            else

                return 'N';
        }
    }

public:
    void Register()
    {
        USERS();

        cout << "\n\t\t\t"
             << "1. first name : ";
        cin >> Fname;

        cout << "\n\t\t\t"
             << "2. last name : ";
        cin >> Lname;

        cout << "\n\t\t\t"
             << "3. date of birth (****/**/**) : ";
        cin >> DOBirth;

        cout << "\n\t\t\t"
             << "4. age : ";
        cin >> age;

        cout << "\n\t\t\t"
             << "5. mobile number : ";
        cin >> mob;

        cout << "\n\t\t\t"
             << "6. E-mail : ";
        cin >> E_mail;

        cout << "\n\t\t\t"
             << "7. Account type (Current(C) or Savings(S)): ";
        cin >> type;

        bool flag1 = true;

        while (flag1 == true)
        {
            cout << "\n\t\t\t"
                 << "9. username : ";
            cin >> username;

            if (username_check(username) == 'N')

                flag1 = false;

            else

                cout << "\n\t\t\t"
                     << "***This username has already been selected. Please choose another username.***";
        }

        bool flag2 = true;

        while (flag2 == true)
        {
            cout << "\n\t\t\t"
                 << "10. password : ";
            cin >> password;

            cout << "\n\t\t\t"
                 << "11. repeat password : ";
            cin >> repassword;

            if (password_check(password, repassword) == 'Y')

                flag2 = false;

            else

                cout << "\n\t\t\t"
                     << "***Did not match! Please try again.***" << endl;
        }

        ofstream write_CustInfo;
        ofstream write_accountinfo;
        write_CustInfo.open("Customerinformation.txt", ios::app);
        write_accountinfo.open("accountNumbers.txt", ios::app);

        if (write_CustInfo.is_open() && write_accountinfo.is_open())
        {

            write_CustInfo << "\n"
                           << "username : " << username << endl;

            write_CustInfo << "\n"
                           << "password : " << password << endl;

            if (type == "S")
            {
                srand(time(0));

                int a = rand() % 9000 + 1000;

                write_CustInfo << "\n"
                               << "account number : "
                               << "4523-1111-" << setw(4) << setfill('0') << usernames.size() + 1 << "-" << a << endl;
                write_accountinfo << "\n"
                                  << "account number : "
                                  << "4523-1111-" << setw(4) << setfill('0') << usernames.size() + 1 << "-" << a << endl;
            }
            else if (type == "C")
            {

                srand(time(0));

                int a = rand() % 9000 + 1000;

                write_CustInfo << "\n"
                               << "account number : "
                               << "4523-0000-" << setw(4) << setfill('0') << usernames.size() + 1 << "-" << a << endl;
                write_accountinfo << "\n"
                                  << "account number : "
                                  << "4523-0000-" << setw(4) << setfill('0') << usernames.size() + 1 << "-" << a << endl;
            }
            write_CustInfo << "\n"
                           << "inventory : " << 0 << endl;

            write_CustInfo << "\n"
                           << "FirstName : " << Fname << endl;

            write_CustInfo << "\n"
                           << "LastName : " << Lname << endl;

            write_CustInfo << "\n"
                           << "DateOfBirth : " << DOBirth << endl;

            write_CustInfo << "\n"
                           << "age : " << age << endl;

            write_CustInfo << "\n"
                           << "MobileNumber : " << mob << endl;

            write_CustInfo << "\n"
                           << "E-mail : " << E_mail << endl;

            write_CustInfo << "\n"
                           << "AccountType : " << type << endl
                           << endl;
            write_accountinfo << "\n"
                              << "AccountType : " << type << endl;

            write_accountinfo << "\n"
                              << "Balance : "
                              << "0" << endl
                              << endl;
            cout << "\n\t\t\t"
                 << "8. Do you have other accounts? (Y or N)";
            cin >> ans;

            bool flag3 = true;

            while (flag3 == true)
            {
                if (ans == "N")
                {
                    write_CustInfo << "AssociatedAccountNumbers : "
                                   << "does not have" << endl;

                    flag3 = false;
                }

                else if (ans == "Y")
                {
                    cout << "\n\t\t\t"
                         << "Enter the number of your other accounts : ";
                    cin >> number;

                    write_CustInfo << "AssociatedAccountNumbers : ";

                    for (i = 0; i < number; i++)
                    {
                        cout << "\n\t\t\t"
                             << "Please enter your account number " << i + 1 << " : ";
                        cin >> acnum;

                        write_CustInfo << acnum;

                        if (i + 1 != number)

                            write_CustInfo << " , ";
                    }

                    flag3 = false;
                }
            }
        }
        else

            cout << "the file could not be opened!";

        write_CustInfo.close();
    }

    void identity_confirmation(string &User)
    {
        USERS();

        bool flag1 = true;

        while (flag1 == true)
        {
            cout << "\n\n\n\n\n\t\t\t\t\t\t"
                 << "1. username : ";
            cin >> username;

            if (username_check(username) == 'Y')

                flag1 = false;

            else

                cout << "\n\t\t\t\t\t"
                     << "***Username not found! Try again.***"
                     << "\n";
        }

        bool flag2 = true;

        while (flag2 == true)
        {
            cout << "\n\n\t\t\t\t\t\t"
                 << "2. password : ";
            cin >> password;

            ifstream read_CustInfo;

            read_CustInfo.open("Customerinformation.txt");

            string word, realpass;

            if (read_CustInfo.is_open())
            {
                while (read_CustInfo >> word)
                {
                    if (word == username)
                    {
                        read_CustInfo >> word;

                        read_CustInfo >> word;

                        read_CustInfo >> word;

                        realpass = word;

                        break;
                    }
                }
            }
            else

                cout << "the file could not be opened!";

            read_CustInfo.close();

            if (password == realpass)
            {
                User = username;

                flag2 = false;
            }
            else

                cout << "\n\t\t\t"
                     << "The password is incorrect! please try again." << endl;
        }
    }

    void Personal_information(string username)
    {
        int ans, a;

        ifstream myfile;

        myfile.open("Customerinformation.txt");

        if (myfile.is_open())
        {
            string line;

            while (getline(myfile, line))
            {
                if (line.find(username) != string::npos)
                {
                    cout << "\n\t\t\t\t\t" << line << endl;

                    int count = 0;

                    for (int i = 0; i < 22; i++)
                    {
                        if (getline(myfile, line))
                        {
                            cout << "\t\t\t\t\t" << line << endl;

                            count++;
                        }
                        else

                            break;
                    }

                    if (count == 22)

                        break;
                }
            }
        }
        else

            cout << "the file could not be opened!";

        myfile.close();

        bool flag3 = true;

        while (flag3 == true)
        {

            cout << "\n\t\t\t\t\t"
                 << "Press 1 to go back : ";
            cin >> ans;
            system("cls");
            if (ans == 1)
                submenu(a);
        }
    }
    void submenu(int &answer)
    {
        int a;

        cout << "\n\n\n\t\t\t\t\t"
             << "*WELCOME*" << endl;

        cout << "\n\t\t\t\t\t"
             << "1. View account information" << endl;

        cout << "\n\t\t\t\t\t"
             << "2. deposit money" << endl;

        cout << "\n\t\t\t\t\t"
             << "3. Withdraw money" << endl;

        cout << "\n\t\t\t\t\t"
             << "4. View transaction history" << endl;

        cout << "\n\t\t\t\t\t"
             << "5. View balance" << endl;

        cout << "\n\n\t\t\t\t"
             << "  Enter your choice : ";

        cin >> a;

        system("cls");

        answer = a;
    }
};

// account.cpp
#include <iostream>
#include <fstream>
#include <string>

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
                    for (int i = 0; i < 7; ++i)
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
        int New_withdraw;
        std::cin >> New_withdraw;
        int balanceint = std::stoi(balance) - New_withdraw;
        std::cout << "Mission accomplished" << std::endl;
        balance = std::to_string(balanceint);
        int num = std::stoi(accnum.substr(10, 14)) - 1;
        std::string originalFilePath = "accountNumbers.txt";
        int lineNumber = num * 7 + 6;
        std::string newLineContent = "Balance : " + balance;
        std::ifstream originalFile("accountNumbers.txt");
        std::ofstream tempFile("temp.txt");

        if (originalFile.is_open() && tempFile.is_open())
        {
            std::string line;
            int currentLineNumber = 0;

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
    }

    void deposit_money(std::string accnum, std::string balance)
    {
        std::cout << "\n\n\t\t\t\tEnter the amount you want to deposit: ";
        int New_deposit;
        std::cin >> New_deposit;
        int balanceint = std::stoi(balance) + New_deposit;
        std::cout << "Mission accomplished" << std::endl;
        balance = std::to_string(balanceint);
        int num = std::stoi(accnum.substr(10, 14)) - 1;
        std::string originalFilePath = "accountNumbers.txt";
        int lineNumber = num * 7 + 6;
        std::string newLineContent = "Balance : " + balance;
        std::ifstream originalFile("accountNumbers.txt");
        std::ofstream tempFile("temp.txt");

        if (originalFile.is_open() && tempFile.is_open())
        {
            std::string line;
            int currentLineNumber = 0;

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
    }
};

void login()
{
    string str, invent, User, inventory, balance;

    user A1;

    account A2;

    int answer;

    A1.identity_confirmation(User);

    system("cls");

    A1.submenu(answer);
    str = A2.find_accnum(User);
    balance = A2.getbalance(str);
    if (answer == 1)

        A1.Personal_information(User);

    else if (answer == 2)
    {
        A2.deposit_money(str, balance);
    }
    else if (answer == 3)
    {
        A2.withdraw_money(str, balance);
    }
    else if (answer == 4)
    {
    }
    else if (answer == 5)
    {
        cout << "balance: " << balance << endl;
    }
}

void MAIN_MENU()
{
    int ans;

    user A1;

    cout << "\n\t\t\t\t\t"
         << "    ***MAIN MENU***" << endl;

    cout << "\n\t\t\t\t\t"
         << "  1. Create an account " << endl;

    cout << "\n\t\t\t\t\t"
         << "  2. Login to the account " << endl;

    cout << "\n\t\t\t\t\t"
         << "  3. For employees " << endl;

    cout << "\n\n\t\t\t\t\t"
         << "  Enter your choice : ";

    cin >> ans;

    system("cls");

    if (ans == 1)

        A1.Register();

    if (ans == 2 || ans == 3)

        login();
}

int main()
{

    MAIN_MENU();
}
