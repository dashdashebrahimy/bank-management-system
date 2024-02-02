#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<iomanip>
using namespace std ;

string Invent(string str)
{
	string invent;
	ifstream Myfile;
	Myfile.open("Customerinformation.txt");
	if(Myfile.is_open())
	{
		string word1;
    	while(Myfile>>word1)
    	{
    	    if(word1==str)
			{
			   Myfile>>word1;
			   Myfile>>word1;
			   Myfile>>word1;
		       invent=word1;
			   break;
			} 
		}
		   	
	}
	else
	cout<<"the file could not be opened!";
	Myfile.close();
	if(invent=="")
	return "Account number not found!";
	else
	return invent;
}
///////////////////////////////////////////////////////////////////////////////////////////////////class user
class user
{
   private:
   	 
	string Fname,Lname,DOBirth,mob,username,password,repassword,E_mail,ans,acnum,type;
    
    int age,i,number;
    
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
		else
	    cout<<"the file could not be opened!";
		read_CustInfo.close();
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
   public:
   	
    void Register()
    {
	    
		USERS();
//	    for(int i=0;i<usernames.size();i++)////**********************************************
//		cout<<usernames.at(i)<<"\n";///////******************************************
		
		cout<<"\n\t\t\t"<<"1. first name : ";
    	cin>>Fname;
		cout<<"\n\t\t\t"<<"2. last name : ";
    	cin>>Lname;
		cout<<"\n\t\t\t"<<"3. date of birth (****/**/**) : ";
    	cin>>DOBirth;
    	cout<<"\n\t\t\t"<<"4. age : ";
    	cin>>age;
    	cout<<"\n\t\t\t"<<"5. mobile number : ";
    	cin>>mob;
    	cout<<"\n\t\t\t"<<"6. E-mail : ";
    	cin>>E_mail;
    	cout<<"\n\t\t\t"<<"7. Account type (Current(C) or Savings(S)): ";
    	cin>>type;
    	bool flag1=true;	
	   while(flag1==true)
	   {
	      cout<<"\n\t\t\t"<<"9. username : ";
          cin>>username;	
          if(username_check(username)=='N')
            flag1=false;
	      else
	        cout<<"\n\t\t\t"<<"***This username has already been selected. Please choose another username.***";	
	   }
	   bool flag2=true;
        while(flag2==true)
    	{
    	   cout<<"\n\t\t\t"<<"10. password : ";
    	   cin>>password;
    	   cout<<"\n\t\t\t"<<"11. repeat password : ";
    	   cin>>repassword;
    	   if(password_check(password,repassword)=='Y')
    	     flag2=false;
    	   else
    	     cout<<"\n\t\t\t"<<"***Did not match! Please try again.***"<<endl;
		}
		
		
    	ofstream write_CustInfo;
		write_CustInfo.open("Customerinformation.txt",ios::app);
		
		if(write_CustInfo.is_open())
		{
			write_CustInfo<<"\n"<<"username : "<<username<<endl;
			write_CustInfo<<"\n"<<"password : "<<password<<endl;
			if(type=="S")
		   {
		    srand(time(0));
	    	int a=rand()%9000+1000;
	    	write_CustInfo<<"\n"<<"account number : "<<"4523-1111-"<<setw(4)<<setfill('0')<<usernames.size()+1<<"-"<<a<<endl;
	    	}
	    	else if(type=="C")
	    	{
	    	srand(time(0));
	    	int a=rand()%9000+1000;
	    	write_CustInfo<<"\n"<<"accountNumber : "<<"4523-0000-"<<setw(4)<<setfill('0')<<usernames.size()+1<<"-"<<a<<endl;
    		}	
    		write_CustInfo<<"\n"<<"inventory : "<<0<<endl;
    	    write_CustInfo<<"\n"<<"FirstName : "<<Fname<<endl;
         	write_CustInfo<<"\n"<<"LastName : "<<Lname<<endl;
        	write_CustInfo<<"\n"<<"DateOfBirth : "<<DOBirth<<endl;
        	write_CustInfo<<"\n"<<"age : "<<age<<endl;
        	write_CustInfo<<"\n"<<"MobileNumber : "<<mob<<endl;
        	write_CustInfo<<"\n"<<"E-mail : "<<E_mail<<endl;
        	write_CustInfo<<"\n"<<"AccountType : "<<type<<endl<<endl;
        	
    	    
        	cout<<"\n\t\t\t"<<"8. Do you have other accounts? (Y or N)";
        	cin>>ans;
        	bool flag3=true;
        	while(flag3==true)
        	{
        		if(ans=="N")
        		{
    	    	  write_CustInfo<<"AssociatedAccountNumbers : "<<"does not have"<<endl;
    	    	  flag3=false;
		    	}
    		
    	    	else if(ans=="Y")
    	     	{
    	    		cout<<"\n\t\t\t"<<"Enter the number of your other accounts : ";
    	    		cin>>number;
		    		write_CustInfo<<"AssociatedAccountNumbers : ";
		    		for(i=0;i<number;i++)
		     		{
		    		cout<<"\n\t\t\t"<<"Please enter your account number "<<i+1<<" : ";
    	    		cin>>acnum;	
    	     		write_CustInfo<<acnum;
    	    		if(i+1!=number)
    	    		write_CustInfo<<" , ";
			    	}
				
    		    	flag3=false;
			   }
		}
    	
    
    
		
		
		}
		else
	    cout<<"the file could not be opened!";	
		write_CustInfo.close();	
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

    void identity_confirmation(string &result)
    {
      USERS();
      
	  bool flag1=true;
	  while(flag1==true)
	  {
   	  cout<<"\n\n\n\n\n\t\t\t\t\t\t"<<"1. username : ";
      cin>>username;
	  	
      if(username_check(username)=='Y')
      flag1=false;
	  else
	  cout<<"\n\t\t\t\t\t"<<"***Username not found! Try again.***"<<"\n";	
	  }
	  bool flag2=true;
	  while(flag2==true)
	  {
      cout<<"\n\n\t\t\t\t\t\t"<<"2. password : ";
      cin>>password;
      ifstream read_CustInfo;
	  read_CustInfo.open("Customerinformation.txt");
	  string word,realpass;
	  if(read_CustInfo.is_open())
	  {
	  	
    	while(read_CustInfo>>word)
    	{
    	    if(word==username)
			{
			 read_CustInfo>>word;
			 read_CustInfo>>word;
			 read_CustInfo>>word;
			realpass=word;
			break;
			}	
	    }
	  }
	    else
	    cout<<"the file could not be opened!";	
	    read_CustInfo.close();
	    
	    if(password==realpass)
	    {
	    result=username;
	    flag2=false;
		}
	    else
	    {
	    cout<<"\n\t\t\t"<<"The password is incorrect! please try again."<<endl;	
		}
	    
    }
    }
    void Personal_information(string username)
    {
    	int anss,ans;
    	ifstream myfile;
    	myfile.open("Customerinformation.txt");
    	if(myfile.is_open())
	{
        string line;
       
        while (getline(myfile, line)) {
            
            if (line.find(username) != string::npos) {
                
                cout <<"\n\t\t\t\t\t"<< line << endl;
               
                int count = 0;
               
                for (int i = 0; i < 22; i++) {
                   
                    if (getline(myfile, line)) {
                       
                        cout <<"\t\t\t\t\t"<< line << endl;
                       
                        count++;
                    }
                    else {
                        
                        break;
                    }
                }
               
                if (count == 22) {
                    
                    break;
                }
            }
        }
        
        myfile.close();
		   	
	}
	else
	cout<<"the file could not be opened!";	
	myfile.close();
	
	bool flag3=true;
	while(flag3==true)
	{
		cout<<"\n\t\t\t\t\t"<<"Press 1 to go back : ";
		cin>>anss;
		system("cls");
		if(anss==1)
		submenu(ans);
		
	}
	
    	
	}
	
	
	void submenu(int &ans)
	{
		int anser;
		
		cout<<"\n\n\n\t\t\t\t\t"<<"*WELCOME*"<<endl;
    	cout<<"\n\t\t\t\t\t"<<"1. View account information"<<endl;
    	cout<<"\n\t\t\t\t\t"<<"2. deposit money"<<endl;
    	cout<<"\n\t\t\t\t\t"<<"3. Withdraw money"<<endl;
		cout<<"\n\t\t\t\t\t"<<"4. View transaction history"<<endl;
		cout<<"\n\n\t\t\t\t"<<"  Enter your choice : ";
		cin>>anser;
		system("cls");
		ans=anser;
}
};
string find_accnum(string username)
{
	string accnum,word;
	ifstream myfile;
	myfile.open("Customerinformation.txt");
	if(myfile.is_open())
	{
		
		while(myfile>>word)
		{
			if(word==username)
			{
			myfile>>word;
			myfile>>word;
			myfile>>word;
			myfile>>word;
        	myfile>>word;
        	myfile>>word;

			accnum=word;

			break;
			}
			
		}
		
	}
	else
	cout<<"the file could not be opened!";
	myfile.close();
	return accnum;
	
}



    	



class account
{
	private:
		string invent;
	
	public:
		
		string deposit_money(string accnum)
		{
			string New_deposit,New_inventory;
			string invent=Invent(accnum);
			cout<<"Enter the amount you want : ";
			cin>>New_deposit;
			New_inventory=Increase_in_inventory(invent,New_deposit );
			
			return New_inventory;
		}
		string Increase_in_inventory(string a, string b) 
		{
            int carry = 0;
            string result = "";
            int i = a.length() - 1; 
            int j = b.length() - 1; 
            
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




void login()
    {
    	string result,str,invent;
		user A1;
		account A2;
		int ans;
		A1.identity_confirmation(result);
		system("cls");
		A1.submenu(ans);
	    if(ans==1)
	    A1.Personal_information(result);
		else if(ans==2)
		{
			str=find_accnum(result);

			invent=Invent(str);
			cout<<"New_inventory"<<A2.deposit_money(str);
			
		}
		
		
    	
}


////////////////////////////////////////////////////////////////////////////////////كلاس هارا بايد بالاي اين بنويسيم
void MAIN_MENU()
{
	int ans;
	user A1;
	cout<<"\n\t\t\t\t\t"<<"***MAIN MENU***"<<endl;
    cout<<"\n\t\t\t\t"<<"  1. Create an account "<<endl;
    cout<<"\n\t\t\t\t"<<"  2. Login to the account "<<endl;
    cout<<"\n\t\t\t\t"<<"  3. For employees "<<endl;
    cout<<"\n\n\t\t\t\t"<<"  Enter your choice : ";
    cin>>ans;
    system("cls");	
    if(ans==1)
    A1.Register();
    if(ans==2||ans==3)
    login();	
}
///////////////////////////////////////////////////////////////////////////////////

int main()
{




MAIN_MENU();

	
	
	
}