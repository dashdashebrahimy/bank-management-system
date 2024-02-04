#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in;
string line;
string search;
string name, gender;
ofstream book; // this is my temporary file where the record will be stored temporarily
void input()
{
    ofstream out;
    book.open("temp.txt", ios::app);
    // out.open("try.txt");
    // cout<<"Enter the name and gender"<<endl;
    // cin>>name>>gender;

    // out<<name<<"\t"<<"  "<<gender<<endl;
    in.open("try.txt");

    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
            book << line << endl;
        }

        book.close();
        in.close();
    }
}

void find()
{

    cout << "Enter the id you want to search" << endl;
    cin >> search;

    in.open("try.txt");
    book.open("temp.txt");

    while (in >> name >> gender)
    {

        if (search.compare(name) == 0)
        {
            cout << "Match found" << endl;
            cout << name << gender << endl;

            cout << "Enter the word you want to replace" << endl;
            cin >> name;
            book << name << "\t" << gender << endl;
            in.close();
            book.close();

            remove("try.txt");
            rename("temp.txt", "try.txt");
        }
    }
}

int main()
{

    input();

    find();

    system("pause");
}