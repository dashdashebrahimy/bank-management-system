#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

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
        accountnumbers.open("accountNumbers.txt");
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

    void deposit_money(string accnum, string balance,string username)
    {
        // string invent = Invent(accnum);

        cout << "\n\n\t\t\t\t"
             << "Enter the amount you want to deposit: ";
        int New_deposit,ans;
        cin >> New_deposit;
        int balanceint = stoi(balance) + New_deposit;
        balance = to_string(balanceint);
        int num = stoi(accnum.substr(10, 14)) - 1;

        // New_inventory = Increase_in_inventory(invent, New_deposit);

        // inventory = New_inventory;
        
		
    }
//}

void withdraw_money(string accnum, string balance)
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
};