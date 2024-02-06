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

using namespace std;

class account
{
private:
    std::string accnum, word, balance;

    vector<string> usernames;
    vector<string> Personal;

    void USERS()
    {

        ifstream read_CustInfo;

        read_CustInfo.open("Customerinformation.txt");

        if (read_CustInfo.is_open())
        {
            string word;

            while (read_CustInfo >> word)
            {

                if (word == "NationalCode")
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

    void Personal_information(string username)
    {

        ifstream myfile;
        myfile.open("Customerinformation.txt");
        if (myfile.is_open())
        {
            string line;

            while (getline(myfile, line))
            {
                if (line.find(username) != string::npos)
                {
                    Personal.push_back(line);

                    int count = 0;

                    for (int i = 0; i < 21; i++)
                    {
                        if (getline(myfile, line))
                        {
                            Personal.push_back(line);

                            count++;
                        }
                        else

                            break;
                    }

                    if (count == 21)

                        break;
                }
            }
        }
        else

            cout << "the file could not be opened!";

        myfile.close();
        
    }

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
    char find_type(string accnum)
    {
        if (accnum[5] == '0')
            return 'C';
        else
            return 'S';
    }
    string subtract(string a, string b) {
    if (a.length() < b.length()) {
        return "-" + subtract(b, a);
    }
    int diff = a.length() - b.length();
    if (diff > 0) {
        b.insert(0, diff, '0');
    }
    int borrow = 0;
    string result = "";
    for (int i = a.length() - 1; i >= 0; i--) {
        int sub = (a[i] - '0') - (b[i] - '0') - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        result.insert(0, to_string(sub));
    }
    int j = 0;
    while (result[j] == '0') {
        j++;
    }
    result.erase(0, j);
    if (borrow == 1) {
        result.insert(0, "-");
    }
    return result;
}

    int compare(string a, string b) {
    if (a.length() > b.length()) {
        return 1;
    }
    else if (a.length() < b.length()) {
        return -1;
    }
    else {
        for (int i = 0; i < a.length(); i++) {
            if (a[i] > b[i]) {
                return 1;
            }
            else if (a[i] < b[i]) {
                return -1;
            }
        }
        return 0;
    }
}

    void withdraw_money(string accnum, string balance, string amount)
    {
       
        if (compare(balance, amount)==1||compare(balance, amount)==0)
        {
        vector<string> olddata;
        string line,newbalance;
        ifstream my;
        my.open("accountNumbers.txt");
        if(my.is_open())
        {	
			while(getline(my,line))
			{
				olddata.push_back(line);
			}	
		}
		else
		cout << "Error opening files." <<endl;
		my.close();
        
        newbalance=subtract(balance, amount);
        
        for(int i=0;i<olddata.size();i++)
        {
        	if(olddata.at(i).find(accnum)!=string::npos)
        	{
        		olddata.at(i+2)="Balance : "+newbalance;
        		break;
			}
		}
        
        ofstream My;
		My.open("accountNumbers.txt");
        if(My.is_open())
        {	
			
			for(int j=0;j<olddata.size();j++)
				My<<olddata.at(j)<<endl;
				
		}
		else
		cout << "Error opening files." <<endl;
		My.close();
        
        vector<string> olddat;
        ifstream myfile;
        myfile.open("Customerinformation.txt");
        if(myfile.is_open())
        {	
			while(getline(myfile,line))
			{
				olddat.push_back(line);
			}	
		}
		else
		cout << "Error opening files." <<endl;
		myfile.close();
        
        for(int i=0;i<olddat.size();i++)
        {
        	if(olddat.at(i).find(accnum)!=string::npos)
        	{
        		olddat.at(i+2)="Balance : "+newbalance;
        		break;
			}
		}
        
        ofstream Myfile;
		Myfile.open("Customerinformation.txt");
        if(Myfile.is_open())
        {	
			
			for(int j=0;j<olddat.size();j++)
				Myfile<<olddat.at(j)<<endl;
				
		}
		else
		cout << "Error opening files." <<endl;
		Myfile.close();
            
        }
        else
        {
            cout << "The account balance is insufficient" << endl;
        }
         system("PAUSE");
        system("cls");
    }

    string Increase_in_inventory(string a, string b)
    {
	string result;
	int i,j,carry=0;

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
	
	void deposit_money(string accnum,string balance, string amount)
    {
		vector<string> olddata;
        string line,newbalance;
        ifstream my;
        my.open("accountNumbers.txt");
        if(my.is_open())
        {	
			while(getline(my,line))
			{
				olddata.push_back(line);
			}	
		}
		else
		cout << "Error opening files." <<endl;
		my.close();
        
        newbalance=Increase_in_inventory(balance, amount);
        
        for(int i=0;i<olddata.size();i++)
        {
        	if(olddata.at(i).find(accnum)!=string::npos)
        	{
        		olddata.at(i+2)="Balance : "+newbalance;
        		break;
			}
		}
        
        ofstream My;
		My.open("accountNumbers.txt");
        if(My.is_open())
        {	
			
			for(int j=0;j<olddata.size();j++)
				My<<olddata.at(j)<<endl;
				
		}
		else
		cout << "Error opening files." <<endl;
		My.close();
        
        vector<string> olddat;
        ifstream myfile;
        myfile.open("Customerinformation.txt");
        if(myfile.is_open())
        {	
			while(getline(myfile,line))
			{
				olddat.push_back(line);
			}	
		}
		else
		cout << "Error opening files." <<endl;
		myfile.close();
        
        for(int i=0;i<olddat.size();i++)
        {
        	if(olddat.at(i).find(accnum)!=string::npos)
        	{
        		olddat.at(i+2)="Balance : "+newbalance;
        		break;
			}
		}
        
        ofstream Myfile;
		Myfile.open("Customerinformation.txt");
        if(Myfile.is_open())
        {	
			
			for(int j=0;j<olddat.size();j++)
				Myfile<<olddat.at(j)<<endl;
				
		}
		else
		cout << "Error opening files." <<endl;
		Myfile.close();
        
        
        
        system("PAUSE");
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

    void add_account(string username)
    {
        Personal_information(username);
        USERS();
        bool done = true;
        string firstbalance, input;
        string type;
        while (done)
        {
            cout << "\n\t\t\t"
                 << "1. Account type (Current(C) or Savings(S)): ";
            cin >> type;
            if (type == "c" || type == "C" || type == "s" || type == "S")
                done = false;
            else
            {
                cout << "\n\t\t\t"
                     << "!. Please choose between S and C" << endl;
                done = true;
            }
            
                if (type == "S" || type == "s")
                {
                    cout << "\t\t\t\t\t\tHow much money do you want to save?";
                    cin >> input;            
                }
               

            ofstream myfile, Myfile;
            myfile.open("Customerinformation.txt", ios::app);
            Myfile.open("accountNumbers.txt", ios::app);
            if (myfile.is_open() && Myfile.is_open())
            {
                for (int i = 0; i < Personal.size(); i++)
                {
                    if (i == 4)
                    {
                        if (type == "S" || type == "s")
                        {
                            srand(time(0));

                            int a = rand() % 9000 + 1000;

                            myfile << "accountNumber : "
                                   << "4523-1111-" << setw(4) << setfill('0') << usernames.size() + 1 << "-" << a << endl;
                            Myfile << "accountNumber : "
                                   << "4523-1111-" << setw(4) << setfill('0') << usernames.size() + 1 << "-" << a << endl;
                                   
                        }
                        else if (type == "C" || type == "c")
                        {

                            srand(time(0));

                            int a = rand() % 9000 + 1000;

                            myfile << "accountNumber : "
                                   << "4523-0000-" << setw(4) << setfill('0') << usernames.size() + 1 << "-" << a << endl;
                            Myfile << "accountNumber : "
                                   << "4523-0000-" << setw(4) << setfill('0') << usernames.size() + 1 << "-" << a << endl;
                                   
                        }
                    }
                    else if (i == 6)
                    {
                        if(type == "S" || type == "s")
                        {
                        	myfile << "Balance : " <<input<< endl;
                            Myfile << "\nBalance : " <<input<< endl;
						}
						else if(type == "C" || type == "c")
                        {
                        	myfile << "Balance : 0" << endl;
                            Myfile << "\nBalance : 0"<< endl;
						}
						         
                    }
                    else if (i == 20)
                    {
                        myfile << "AccountType : " << type << endl;
                        Myfile << "\nAccountType : " << type << endl<<endl;
                               
                    }

                    else
                        myfile << Personal.at(i) << endl;
                }
            }
            else
                cout << "the file could not be opened!";
            myfile.close();
            Myfile.close();
        }

        char x;

        system("PAUSE");
        system("cls");
    }
    vector<string> account_numbers;

    int Checking_the_number_of_accounts(string username)
    {

        string word, word2;
        int m = 0;
        ifstream myfile;
        myfile.open("Customerinformation.txt");
        if (myfile.is_open())
        {
            while (myfile >> word)
            {
               
                
                if (word == username && myfile>>word2&&word2 == "password")
                {
                    m++;
                    myfile >> word;
                    myfile >> word;
                    myfile >> word;
                    myfile >> word;
                    myfile >> word;
                    account_numbers.push_back(word);
                }
            }
        }
        else
            cout << "the file could not be opened!";
        myfile.close();
        return m;
    }

    void show_accounts(string User)
    {
        int a,i;
        int n=Checking_the_number_of_accounts(User);

        for (i = 0; i < n; i++)
        {
            cout << "\n\n\n\t\t\t\t" << i + 1 << " : " << account_numbers.at(i) << endl;
        }

    }
};
class Transaction
{
private:
    string amount;
    std::string type;

public:
    void save_toFile_deposit(string accnum, string amount)
    {
        time_t currentTime = time(nullptr);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&currentTime));
        ofstream write_transactioninfo;
        write_transactioninfo.open("transaction.txt", ios::app);
        if (write_transactioninfo.is_open())
        {
            write_transactioninfo << "\n"
                                  << "account number : " << accnum << endl;

            write_transactioninfo << "\n"
                                  << "type : deposit" << endl;

            write_transactioninfo << "\n"
                                  << "amount : " << amount << endl;

            write_transactioninfo << "\n"
                                  << "time : " << buffer << endl;
        }

        else
            cout << "the file could not be opened!";

        write_transactioninfo.close();
    }
    void save_toFile_withdraw(string accnum, string amount)
    {
        time_t currentTime = time(nullptr);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&currentTime));
        ofstream write_transactioninfo;
        write_transactioninfo.open("transaction.txt", ios::app);
        if (write_transactioninfo.is_open())
        {
            write_transactioninfo << "\n"
                                  << "account number : " << accnum << endl;

            write_transactioninfo << "\n"
                                  << "type : withdtraw" << endl;

            write_transactioninfo << "\n"
                                  << "amount : " << amount << endl;

            write_transactioninfo << "\n"
                                  << "time : " << buffer << endl;
        }

        else
            cout << "the file could not be opened!";

        write_transactioninfo.close();
    }
    void find_histtransaction(string accnum)
    {
        string word, line, line2, x;
        int count = 0;
        cout << "Your last 10 transactions : " << endl;
        ifstream myfile;
        myfile.open("transaction.txt");
        if (myfile.is_open())
        {
            while (myfile >> word)
            {
                if (word == accnum)
                {
                    myfile >> word;
                    myfile >> word;
                    myfile >> word;
                    cout << "type : " << word << endl;
                    myfile >> word;
                    myfile >> word;
                    myfile >> word;
                    cout << "amount : " << word << endl;
                    myfile >> word;
                    myfile >> word;
                    myfile >> word;
                    cout << "time : " << word;
                    myfile >> word;
                    cout << word << endl;
                }
            }
        }
        else
        {
            std::cout << "The file could not be opened!";
        }

        myfile.close();
        system("PAUSE");
        system("cls");
    }
};
#endif
