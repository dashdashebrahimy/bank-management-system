#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "user.h"
#include "account.h"
using namespace std;

void login();

void MAIN_MENU();

void submenu(string User);

int main()
{
    user A1;
    MAIN_MENU();
     
}

void MAIN_MENU()
{
    int ans;

    user A1;
    string user;
    
//    system("cls");

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
    {
    	A1.Register();
        user=A1.username;
        MAIN_MENU();
	}

        

    if (ans == 2 || ans == 3)

        login();
}

void submenu(string User)
    {
        int b;
		    
		    string str,invent,inventory, creditnum, balance;
		    
		    user A1;
		    
			account A2;
		    
		 
		    cout<<"\n\n\n\t\t\t\t\t"<<"*WELCOME*"<<endl;
		    
    	    cout<<"\n\t\t\t\t\t"<<"1. View account information"<<endl;
    	    
    	    cout<<"\n\t\t\t\t\t"<<"2. deposit money"<<endl;
    	    
    	    cout<<"\n\t\t\t\t\t"<<"3. Withdraw money"<<endl;
    	    
	        cout<<"\n\t\t\t\t\t"<<"4. View transaction history"<<endl;

		    cout<<"\n\n\t\t\t\t"<<"  Enter your choice : ";
		    
		    cin>>b;
		    
		    system("cls");
		    
		    str = A2.find_accnum(User);
            balance = A2.getbalance(str);
		    
		    if(b==1)
		    {
		    	A1.Personal_information(User);
		    	submenu(User);
		    	
		    	
			}
		    else if(b==2)
		    {
			
			    A2.deposit_money(str, balance);	
		    }   
			else if (b == 3)
            {
                A2.withdraw_money(str, balance);
            }	
		    
			
		    
    }
    
    void login()
{
    string str, invent, User, inventory, creditnum, balance;

    user A1;

    account A2;


    A1.identity_confirmation(User);

    
    submenu(User);
    
    
}
