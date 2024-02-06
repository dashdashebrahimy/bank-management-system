#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include<conio.h>
#include "user.h"
#include "account.h"
using namespace std;

void login();

void MAIN_MENU();

void submenu(string User);

void Clerk_mene(string user);

void boss_menu(string user);

void Staff_menu();

int main()
{
    account A2;
    user A1;
    
    MAIN_MENU();

   
}

void MAIN_MENU()
{
    int ans;

    user A1;
    string user;

  

    cout << "\n\t\t\t\t\t"
         << "    ***MAIN MENU***" << endl;

    cout << "\n\t\t\t\t\t"
         << "  1. Create an account " << endl;

    cout << "\n\t\t\t\t\t"
         << "  2. Login to the account " << endl;

    cout << "\n\t\t\t\t\t"
         << "  3. For bank members " << endl;

    cout << "\n\n\t\t\t\t\t"
         << "  Enter your choice : ";

    cin >> ans;

    system("cls");

    if (ans == 1)
    {
        A1.Register();
        user = A1.username;
        MAIN_MENU();
    }

    else if (ans == 2)

        login();
        
    else if(ans==3)
    Staff_menu();
        
}

void submenu(string User, string accnum_done)
{
    int b;

    string str, invent, inventory, creditnum, balance;

    user A1;

    account A2;

    Transaction A3;

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
         << "5. Add account" << endl;

    cout << "\n\t\t\t\t\t"
         << "6. Back" << endl;

    cout << "\n\n\t\t\t\t"
         << "  Enter your choice : ";

    cin >> b;

    system("cls");

    balance = A2.getbalance(accnum_done);

    if (b == 1)
    {
        A1.Personal_information(User, accnum_done);
        submenu(User, accnum_done);
    }
    else if (b == 2)
    {
        if (A2.find_type(accnum_done) == 'C')
        {
            cout << "\n\n\t\t\t\tEnter the amount you want to deposit: ";
            string amount;
            cin >> amount;
            A2.deposit_money(accnum_done, balance, amount);
            A3.save_toFile_deposit(accnum_done, amount);
            submenu(User, accnum_done);
        }
        else
        {
            cout << "It is not possible to withdraw from the savings account";
            submenu(User, accnum_done);
        }
    }
    else if (b == 3)
    {
        if (A2.find_type(accnum_done) == 'C')
        {
            cout << "\n\n\t\t\t\tEnter the amount you want to get: ";
            string amount;
            cin >> amount;
            A2.withdraw_money(accnum_done, balance, amount);
            A3.save_toFile_withdraw(accnum_done, amount);
            submenu(User, accnum_done);
        }
        else
        {
            cout << "It is not possible to withdraw from the savings account";
            submenu(User, accnum_done);
        }
    }
    else if (b == 4)
    {
        A3.find_histtransaction(accnum_done);
        submenu(User, accnum_done);
    }
    else if (b == 5)
    {
        A2.add_account(User);
        submenu(User, accnum_done);
    }
    else if (b == 6)
    {
        int a;

        A2.show_accounts(User);

        cout << "\n\n\t\t\t\t"
             << "  Enter your choice : ";

        cin >> a;

        system("cls");

        accnum_done = A2.account_numbers.at(a - 1);

        //                cout<<accnum_done;

        submenu(User, accnum_done);
    }
}

void login()
{
    string User, accnum_done;

    user A1;

    account A2;
    int a,m;

    A1.identity_confirmation(User);

    A2.show_accounts(User);

    m=A2.Checking_the_number_of_accounts(User);

    cout << "\n\n\t\t\t\t"
         << "  Enter your choice : ";

    cin >> a;
    system("cls");

    accnum_done = A2.account_numbers.at(a - 1);


    submenu(User, accnum_done);
}
void Staff_menu()
{
	Clerk A1;
	int a;
	system("cls");
	cout<< "\n\n\n\t\t\t\t\t"<<"1. The arrival of the president"<<endl;
	
	cout<< "\n\t\t\t\t\t"<<"2. Entry of employees"<<endl;
	
	cout<< "\n\t\t\t\t\t"<<"3. back"<<endl;
	
	cout << "\n\n\t\t\t\t\t"<< "  Enter your choice : ";
	
	
	cin>>a;
	system("cls");
	string user;
	if(a==1)
	{	
		A1.identity_confirm(user);
		boss_menu(user);
	}
	else if(a==2)
	{
		A1.identity_confirm(user);
		Clerk_mene(user);
	}
	else if(a==3)
	{
	  MAIN_MENU();	
	}
	else
	{
		cout<< "\n\n\t\t\t\t\t"<<"Please choose between 1 and 2"<<endl;
		system("PAUSE");
		Staff_menu();
		system("cls");
		
	}
	
	
}

void boss_menu(string user)
{
		Bank_CEO A1;
		account A2;
		int b;
		cout<< "\n\n\t\t\t\t\t"<<"1. View all bank balance"<<endl;
		cout<< "\n\t\t\t\t\t"<<"2. View Balance of savings accounts"<<endl;
		cout<< "\n\t\t\t\t\t"<<"3. Search based on national code"<<endl;
		cout<< "\n\t\t\t\t\t"<<"4. View Balance of current accounts"<<endl;
		cout<< "\n\t\t\t\t\t"<<"5. Viewing employee information"<<endl;
		cout<< "\n\t\t\t\t\t"<<"6. View customer information"<<endl;
		cout<< "\n\t\t\t\t\t"<<"7. View account information" << endl;
		cout<< "\n\t\t\t\t\t"<<"8. Back" << endl;
		cin>>b;
		system("cls");
		
		if(b==1)
		{
			A1.total_inventory();
			system("PAUSE");
			system("cls");
			boss_menu(user);
			
		}
		else if(b==2)
		{
			A1.Balance_of_C_S_accounts("s");
			system("PAUSE");
			system("cls");
			boss_menu(user);
		}
		else if(b==3)
		{
		 string User,accnum_done;
		 int a;
		 cout<<"Enter the national code : ";
		 cin>>User;
		 A2.show_accounts(User);

         A2.Checking_the_number_of_accounts(User);

        cout << "\n\n\t\t\t\t"
         << "  Enter your choice : ";

        cin >> a;

         system("cls");

        accnum_done = A2.account_numbers.at(a - 1);

           submenu(User, accnum_done);	
	        system("PAUSE");
			system("cls");
		    boss_menu(user);
        }
		else if(b==4)
		{
			A1.Balance_of_C_S_accounts("c");
			system("PAUSE");
			system("cls");
			boss_menu(user);
			
		}
		else if(b==5)
		{
			A1.employee_information();
			system("PAUSE");
			system("cls");
			boss_menu(user);
		}
		else if(b==6)
		{
		 A1.customer_information();	
	        system("PAUSE");
			system("cls");
			boss_menu(user);
        }
        else if(b==7)
		{
		 A1.acc_inform(user);	
	        system("PAUSE");
			system("cls");
			boss_menu(user);
        }
        else if(b==8)
		{
		 Staff_menu();
        }
        else
        {
        	cout<<"Please choose from 1 to 8";
        	 system("PAUSE");
			system("cls");
        	boss_menu(user);
		}
}
void Clerk_mene(string user)
{
     Clerk A1;
     account A2;
		int b;
		
	    cout<< "\n\t\t\t\t\t"<<"1. View customer information"<<endl;
		cout<< "\n\t\t\t\t\t"<<"2. Search based on national code"<<endl;
		cout<< "\n\t\t\t\t\t"<<"3. View account information" << endl;
		cout<< "\n\t\t\t\t\t"<<"4. Back" << endl;
		cin>>b;
		system("cls");
		
		 if(b==1)
		{
		 A1.customer_information();	
	        system("PAUSE");
			system("cls");
			Clerk_mene(user);
        }
        else if(b==2)
		{
		 string User,accnum_done;
		 int a;
		 cout<<"Enter the national code : ";
		 cin>>User;
		 A2.show_accounts(User);

         A2.Checking_the_number_of_accounts(User);

        cout << "\n\n\t\t\t\t"
         << "  Enter your choice : ";

        cin >> a;

         system("cls");

        accnum_done = A2.account_numbers.at(a - 1);

           submenu(User, accnum_done);	
	        system("PAUSE");
			system("cls");
		    Clerk_mene(user);
        }
        
        else if(b==3)
		{
		 A1.acc_inform(user);	
	        system("PAUSE");
			system("cls");
			Clerk_mene(user);
        }
        else if(b==4)
		{
		 Staff_menu();
        }
        else
        {
        	cout<<"Please choose from 1 to 4";
        	 system("PAUSE");
			system("cls");
        	boss_menu(user);
		}	
	
}



















