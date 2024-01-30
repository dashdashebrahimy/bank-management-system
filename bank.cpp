#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std ;

class user
{
   private:
   	
   	  string Fname,Lname,DOBirth,mob,username,password,repassword,E_mail;
    
      int age,i;
    
      vector<string> usernames;
    
    void USERS()
    {
      ifstream read_CustInfo;
	  read_CustInfo.open("Customerinformation.txt");
	  if (read_CustInfo.is_open())
		{
		  string word;
    	  while(read_CustInfo>>word)
    	   {
    	     if(word=="username")
			  {
			    read_CustInfo>>word;
			    read_CustInfo>>word;
		    	usernames.push_back(word);
			  }	
		   }	
		}
		read_CustInfo.close();
	}
   
   public:
   	
    void Register()
    {
	    
		USERS();
	    for(int i=0;i<usernames.size();i++)////
		cout<<usernames.at(i)<<"\n";///////
		
		ofstream write_CustInfo;
		write_CustInfo.open("Customerinformation.txt",ios::app);
		if(write_CustInfo.is_open())
		{
		   cout<<"\n\t\t\t"<<"1. first name : ";
    	cin>>Fname;
    	write_CustInfo<<"\n"<<"first name : "<<Fname<<endl;
    	
    	cout<<"\n\t\t\t"<<"2. last name : ";
    	cin>>Lname;
    	write_CustInfo<<"\n"<<"last name : "<<Lname<<endl;
    	
    	cout<<"\n\t\t\t"<<"3. date of birth (****/**/**) : ";
    	cin>>DOBirth;
    	write_CustInfo<<"\n"<<"date of birth : "<<DOBirth<<endl;
    	
    	cout<<"\n\t\t\t"<<"5. age : ";
    	cin>>age;
    	write_CustInfo<<"\n"<<"age: "<<age<<endl;
    	
    	cout<<"\n\t\t\t"<<"6. mobile number : ";
    	cin>>mob;
    	write_CustInfo<<"\n"<<"mobile number: "<<mob<<endl;
    	
    	cout<<"\n\t\t\t"<<"7. E-mail : ";
    	cin>>E_mail;
    	write_CustInfo<<"\n"<<"E-mail: "<<E_mail<<endl;
    	
       bool flag1=true;	
	   while(flag1==true)
	   {
	      cout<<"\n\t\t\t"<<"8. username : ";
          cin>>username;	
          if(username_check(username)=='N')
            flag1=false;
	      else
	        cout<<"\n\t\t\t"<<"***This username has already been selected. Please choose another username.***";	
	   }
			
        write_CustInfo<<"\n"<<"username : "<<username<<endl;
    
        bool flag2=true;
        while(flag2==true)
    	{
    	   cout<<"\n\t\t\t"<<"9. password : ";
    	   cin>>password;
    	   cout<<"\n\t\t\t"<<"10. repeat password : ";
    	   cin>>repassword;
    	   if(password_check(password,repassword)=='Y')
    	     flag2=false;
    	   else
    	     cout<<"\n\t\t\t"<<"***Did not match! Please try again.***"<<endl;
		}
		write_CustInfo<<"\n"<<"password : "<<password<<endl;	
		}	
		write_CustInfo.close();	
    }
    char username_check(string s1)
    {
    	int i,m=0;
		 for(i=0;i<usernames.size();i++)
		 {
		 	if(usernames.at(i)==s1)
		 	m++;
		 }
		 if(m==0)
		 return 'N';
		 else
		 return 'Y';
	}
    char password_check(string s1,string s2)
    {
    	int i,m=0;
    	if(s1.size()!=s2.size())
		return 'N';
		else
		{
		 for(i=0;i<s1.size();i++)
		 {
		 	if(s1[i]==s2[i])
		 	m++;
		 }
		 if(m==s1.size())
		 return 'Y';
		 else
		 return 'N';
		}
		
	}
    void login()
    {
      USERS();
	  bool flag1=true;
	  while(flag1==true)
	  {
   	  cout<<"\n\t\t\t"<<"1. username : ";
      cin>>username;
	  	
      if(username_check(username)=='Y')
      flag1=false;
	  else
	  cout<<"\n\t\t\t"<<"***Username not found! Try again.***"<<"\n";	
	  }
	  bool flag2=true;
	  while(flag2==true)
	  {
      cout<<"\n\t\t\t"<<"2. password : ";
      cin>>password;
      ifstream read_CustInfo("Customerinformation.txt");
	  string word,realpass;
    	while(read_CustInfo>>word)
    	{
    	    if(word==username)
			{
			 read_CustInfo>>word;
			 read_CustInfo>>word;
			 read_CustInfo>>word;
			realpass=word;
			}	
	    }
	    read_CustInfo.close();
	    if(password==realpass)
	    {
	    cout<<"\n\t\t\t"<<"welcome dear "<<username;
	    flag2=false;
		}
	    else
	    cout<<"\n\t\t\t"<<"The password is incorrect! please try again."<<endl;
    }
    }
};
class Account {
private:
    int accountNumber;
    string accountType;
    double balance;  
    double interestRate;
public:
    Account(int number, const std::string& type, double initialBalance, double rate)
        : accountNumber(number), accountType(type), balance(initialBalance), interestRate(rate) {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit of $" << amount << " successful. New balance: $" << balance << endl;
    }
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal of $" << amount << " successful. New balance: $" << balance << endl;
        } 
		else {
            cout << "Insufficient funds for withdrawal." << endl;
        }
    }
    double checkBalance() const { return balance; }
    int getAccountNumber() const { return accountNumber; }
    string getAccountType() const { return accountType; }
};

int main()
{
	user A1;
	A1.Register();
//	A1.login();
	
}