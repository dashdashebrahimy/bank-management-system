#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
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
                               << "accountNumber : "
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
                              << "AccountType: " << type << endl;

            write_accountinfo << "\n"
                              << "Balance: "
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

            string word, realpass, creditnum;

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
            // system("cls");
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

        cout << "\n\n\t\t\t\t"
             << "  Enter your choice : ";

        cin >> a;

        //	system("cls");

        answer = a;
    }
};
class account
{
private:
    string accnum, word, invent, New_deposit, New_inventory, result = "", balance;

    int carry = 0, i, j;

public:
    string find_accnum(string username)
    {
        ifstream myfile;

        myfile.open("Customerinformation.txt");

        if (myfile.is_open())
        {
            while (myfile >> word)
            {
                if (word == username)
                {
                    myfile >> word;

                    myfile >> word;

                    myfile >> word;

                    myfile >> word;

                    myfile >> word;

                    myfile >> word;

                    myfile >> word;

                    accnum = word;

                    break;
                }
            }
        }
        else

            cout << "the file could not be opened!";

        myfile.close();
        return accnum;
    }
    string getbalance(string ccn)
    {
        ifstream myfile;

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

                    balance = word;

                    break;
                }
            }
        }
        else

            cout << "the file could not be opened!";

        myfile.close();
        return balance;
    }
    string Invent(string str)
    {
        string invent;

        ifstream Myfile;

        Myfile.open("Customerinformation.txt");

        if (Myfile.is_open())
        {
            string word1;

            while (Myfile >> word1)
            {
                if (word1 == str)
                {
                    Myfile >> word1;

                    Myfile >> word1;

                    Myfile >> word1;

                    invent = word1;

                    break;
                }
            }
        }
        else

            cout << "the file could not be opened!";

        Myfile.close();

        if (invent == "")

            return "Account number not found!";

        else

            return invent;
    }
    void input()
    {
        string line;
        ofstream temp;
        ifstream accountnumbers;
        temp.open("temp.txt", ios::app);
        accountnumbers.("accountNumbers.txt");
        if (accountnumbers.is_open())
        {
            while (getline(accountnumbers, line))
            {
                cout << line << endl;
                temp << line << endl;
            }

            temp.close();
            accountnumbers.close();
        }
    }

    void deposit_money(string accnum, string balance)
    {
        // string invent = Invent(accnum);

        cout << "\n\n\t\t\t\t"
             << "Enter the amount you want to deposit: ";
        int New_deposit;
        cin >> New_deposit;
        int balanceint = stoi(balance) + New_deposit;
        balance = to_string(balanceint);
        int num = stoi(accnum.substr(10, 14)) - 1;

        // New_inventory = Increase_in_inventory(invent, New_deposit);

        // inventory = New_inventory;
    }
}

void
withdraw_money(string accnum, string balance)
{
    cout << "\n\n\t\t\t\t"
         << "Enter the amount you want to withdraw: ";
    int New_withdraw;
    cin >> New_withdraw;
    int balanceint = stoi(balance) - New_withdraw;
    balance = to_string(balanceint);
    int num = stoi(accnum.substr(10, 14)) - 1;
    // cout << num;
    fstream myfile("accountNumbers.txt", ios::in | ios::out);

    if (myfile.is_open())
    {
        string line;
        int currentLineNumber = 0;

        while (getline(myfile, line))
        {
            currentLineNumber++;
            if (currentLineNumber == (num * 7) + 6)
            {
                istringstream iss(line);
                string word;
                int currentWordPosition = 0;
                while (iss >> word)
                {

                    currentWordPosition++;
                    if (currentWordPosition == 2)
                    {
                        // cout << word;
                        word = balance;
                        cout << "new Value: " << word;
                        break;
                    }
                }
                break;
            }
        }
        myfile.close();
    }

    else

        cout << "the file could not be opened!";
}
string Increase_in_inventory(string a, string b)
{
    i = a.length() - 1;

    j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0)
    {
        int n1 = (i >= 0) ? a[i] - '0' : 0;

        int n2 = (j >= 0) ? b[j] - '0' : 0;

        int s = n1 + n2 + carry;

        result = char(s % 10 + '0') + result;

        carry = s / 10;

        i--;

        j--;
    }

    return result;
}
}
;
class transaction
{
};
void login()
{
    string str, invent, User, inventory, creditnum, balance;

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
        // invent = A2.Invent(str);
        A2.deposit_money(str, balance);
        /*cout << "\n\n\t\t\t\t"
             << "NEW_inventory : " << inventory;*/
    }
    else if (answer == 3)
    {
        A2.withdraw_money(str, balance);
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
