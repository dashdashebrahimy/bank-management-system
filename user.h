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
using namespace std;

class user
{
private:
    string Fname, Lname, DOBirth, mob, password, repassword, E_mail, ans, acnum, type;

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
	string username;
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
        bool contin=true;
        while (flag1 == true)
        {
            cout << "\n\t\t\t"
                 << "9. National code : ";
            cin >> username;

            if (username_check(username) == 'N')

                flag1 = false;
            
            else
            {
                cout << "\n\t\t\t"
                     << "***This national code has already been registered. Please select the login option.***"<<endl;
                     flag1 = false;
                     char x;
                     cout<<"\n\t\t\t"<<"Press a key to go back : ";
		             cin>>x;
		             contin=false;
		             system("cls");
                     
			}
                
        }
        if(contin==true)
        {
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
                           << "NationalCode : " << username << endl;

            write_CustInfo << "\n"
                           << "password : " << password << endl;

            if (type == "S"||type=="s")
            {
                srand(time(0));

                int a = rand() % 9000 + 1000;

                write_CustInfo << "\n"
                               << "accountNumber : "
                               << "4523-1111-" << setw(4) << setfill('0') << usernames.size() + 1 << "-" << a << endl;
                write_accountinfo << "\n"
                                  << "account number : "
                                  << "4523-1111-" << setw(4) << setfill('0') << usernames.size() + 1 << "-" << a << endl;
            }
            else if (type == "C"||type=="c")
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
                           << "Balance : " << 0 << endl;

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
        }
        else

            cout << "the file could not be opened!";

        write_CustInfo.close();
            
		    char x;
       
		    cout<<"\n\n\n\t\t\t"<<"The account was created successfully."<<endl;
		    
		    cout<<"\n\t\t\t"<<"Press a key to go back : ";
		    cin>>x;
		    system("cls");
		}
        
    }
    void identity_confirmation(string &User)
    {
        USERS();

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

                User = username;
                flag2 = false;
                system("cls");
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
        
        char x;
        
         cout<<"\n\t\t\t"<<"Press a key to go back : ";
		 cin>>x;
		  system("cls");

        
	        } 	
	    
    
};
#endif