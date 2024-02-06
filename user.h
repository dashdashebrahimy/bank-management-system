#ifndef USER
#define USER
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "account.h"
using namespace std;

class user
{
private:
    

    
    
public:
	
	string Fname, Lname, DOBirth, mob, password, repassword, E_mail, ans, acnum, type;

    int age, i, number;
    
    string username;
    
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

    
    vector<string> usernames;

    void USERS(string nfile)
    {

        ifstream read_CustInfo;

        read_CustInfo.open(nfile);

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
        {
            cout << "the file could not be opened!";
        }

        read_CustInfo.close();
    }
    void Register()
    {
        USERS("Customerinformation.txt");

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

        bool done = true;
        while (done)
        {
            cout << "\n\t\t\t"
                 << "7. Account type (Current(C) or Savings(S)): ";
            cin >> type;
            if (type == "c" || type == "C" || type == "s" || type == "S")
                done = false;
            else
            {
                cout << "\n\t\t\t"
                     << "!. Please choose between S and C" << endl;
                done = true;
            }
        }

        bool flag1 = true;
        bool contin = true;
        while (flag1 == true)
        {
            cout << "\n\t\t\t"
                 << "8. National code : ";
            cin >> username;

            if (username_check(username) == 'N')

                flag1 = false;

            else
            {
                cout << "\n\t\t\t"
                     << "***This national code has already been registered. Please select the login option.***" << endl;
                flag1 = false;
                char x;
                cout << "\n\t\t\t"
                     << "Press a key to go back : ";
                cin >> x;
                contin = false;
                system("cls");
            }
        }
        if (contin == true)
        {
            bool flag2 = true;

            while (flag2 == true)
            {
                cout << "\n\t\t\t"
                     << "9. password : ";
                cin >> password;

                cout << "\n\t\t\t"
                     << "10. repeat password : ";
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

                write_CustInfo << "NationalCode : " << username << endl;

                write_CustInfo << "\n"
                               << "password : " << password << endl;

                if (type == "S" || type == "s")
                {
                    srand(time(0));

                    int a = rand() % 9000 + 1000;

                    write_CustInfo << "\n"
                                   << "accountNumber : "
                                   << "4523-1111-" << setw(4) << setfill('0') << usernames.size() + 1 << "-" << a << endl;
                    write_accountinfo << "accountNumber : "
                                      << "4523-1111-" << setw(4) << setfill('0') << usernames.size() + 1 << "-" << a << endl;
                }
                else if (type == "C" || type == "c")
                {

                    srand(time(0));

                    int a = rand() % 9000 + 1000;

                    write_CustInfo << "\n"
                                   << "accountNumber : "
                                   << "4523-0000-" << setw(4) << setfill('0') << usernames.size() + 1 << "-" << a << endl;
                    write_accountinfo << "accountNumber : "
                                      << "4523-0000-" << setw(4) << setfill('0') << usernames.size() + 1 << "-" << a << endl;
                }
                
				string firstbalance, input;
                if (type == "S" || type == "s")
                {
                    cout << "\n\t\t\t11. How much money do you want to save? ";
                    cin >> input;
                    write_accountinfo << "\n"
                                      << "Balance : "
                                      << input
                                      << endl;
                                      
                    write_CustInfo << "\n"
                                   << "Balance : " << input << endl;               
                }
                else
                {
                    write_accountinfo << "\n"
                                      << "Balance : "
                                      << "0"
                                      << endl;
                   write_CustInfo << "\n"
                                   << "Balance : " <<"0" << endl;                    
                                      
                }		
				
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
                               << "AccountType : " << type << endl<<endl;

                write_accountinfo << "\n"
                                  << "AccountType : " << type << endl<<endl;

                
            }
            else

                cout << "the file could not be opened!";

            write_CustInfo.close();

            char x;

            cout << "\n\n\n\t\t\t"
                 << "The account was created successfully." << endl;

            system("PAUSE");
            system("cls");
        }
    }
    void identity_confirmation(string &accnum)
    {
        USERS("Customerinformation.txt");

        bool flag1 = true;

        while (flag1 == true)
        {
            cout << "\n\n\n\n\n\t\t\t\t\t\t"
                 << "1. National code : ";
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

                accnum = username;
                flag2 = false;
                system("cls");
            }
            else

                cout << "\n\t\t\t"
                     << "The password is incorrect! please try again." << endl;
        }
    }

    void Personal_information(string username, string accnum_done)
    {

        ifstream myfile;
        int i;

        vector<string> infor;

        myfile.open("Customerinformation.txt");

        if (myfile.is_open())
        {
            string line;

            while (getline(myfile, line))
            {

                infor.push_back(line);
            }
        }

        else

            cout << "the file could not be opened!";

        myfile.close();
        cout << "\n";

        int k = 0;
        bool found = false;
        while (found == false)
        {
            if (infor.at(k).find(username) != string::npos && infor.at(k + 4).find(accnum_done) != string::npos)
            {
                for (int j = k; j < k + 22; j++)
                    cout << "\t\t\t" << infor.at(j) << endl;
                found = true;
            }
            else
                k += 22;
        }

        system("PAUSE");
        system("cls");
    }
};
class Clerk : public user
{
	public:
		 
		 vector<string> information;
	string line;
	
	
		void identity_confirm(string &user)
        {
        USERS("Employee information.txt");

        bool flag1 = true;

        while (flag1 == true)
        {
            cout << "\n\n\n\n\n\t\t\t\t\t\t"
                 << "1. National code : ";
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

            read_CustInfo.open("Employee information.txt");

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
                 user=username;
                flag2 = false;
                system("cls");
            }
            else

                cout << "\n\t\t\t"
                     << "The password is incorrect! please try again." << endl;
        }
    }
    void customer_information()
    {
    	string line;
		ifstream my;
		my.open("Customerinformation.txt");
		if(my.is_open())
		{
			while(getline(my,line))
			cout<<line<<endl;
		}
		else
		 cout << "the file could not be opened!";
        my.close();
	}
	void acc_inform(string user)
    {
    	string line;
		ifstream my;
		my.open("Employee information.txt");
		if(my.is_open())
		{
			while(getline(my,line))
			{
				if(line.find(user)!=string::npos)
				
				{
					cout<<line<<endl;
					for(int i=0;i<20;i++)
					{
						getline(my,line);
						cout<<line<<endl;
					}
				}
			}
			
		}
		else
		 cout << "the file could not be opened!";
        my.close();
	}
	
};
class Bank_CEO : public Clerk
{
    
	public:
	
	
	void total_inventory()
	{
		account A2;
		vector<string> balance;
		string word;
		ifstream my;
		my.open("accountNumbers.txt");
		if(my.is_open())
		{
			while(my>>word)
			{
				if(word=="Balance")
				{
					my>>word;
					my>>word;
					balance.push_back(word);
				}

			}	
		}
		else
		cout << "the file could not be opened!";
        my.close();
        string sum="0";
		
		for(int i=0;i<balance.size();i++)
		{
			sum=A2.Increase_in_inventory(sum, balance.at(i));
		}
		
		
		cout<< "\n\t\t\t"<<"The total bank balance is "<<sum<< "$"<<endl;
		
		
	}
	void Balance_of_C_S_accounts(string type)
	{
		string done;
		if(type=="s"||type=="S")
		done="1111";
		else if(type=="c"||type=="C")
		done="0000";
		
		account A2;
		vector<string> balance;
		string word,line;
		ifstream my;
		my.open("accountNumbers.txt");
		if(my.is_open())
		{
			while(getline(my,line))
			{
				if(line.find(done)!=string::npos)
				{
					my>>word;
					my>>word;
					my>>word;
					balance.push_back(word);
				}

			}	
		}
		else
		cout << "the file could not be opened!";
        my.close();
        string sum="0";
		
		for(int i=0;i<balance.size();i++)
		{
			sum=A2.Increase_in_inventory(sum, balance.at(i));
    

		}
		
		if(type=="s"||type=="S")
		cout<< "\n\t\t\t"<<"Balance of savings accounts is "<<sum<< "$"<<endl;
		else if(type=="c"||type=="C")
		cout<< "\n\t\t\t"<<"Balance of current accounts is "<<sum<< "$"<<endl;
		
		
	}
	void employee_information()
	{
		string line;
		ifstream my;
		my.open("Employee information.txt");
		if(my.is_open())
		{
			for(int i=0;i<19;i++)
			getline(my,line);
			while(getline(my,line))
			cout<<line<<endl;
			
		}
		else
		 cout << "the file could not be opened!";
        my.close();
	}
	

	
	
};

#endif















