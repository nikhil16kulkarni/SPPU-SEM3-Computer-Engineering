//============================================================================
// Name        : minip.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;


class account
{
	int acno;
	char name[50];
	int deposit;
	char type;
public:
	void create_account();	//get data from user
	void show_account() const;	//show data on screen
	void modify();	//add new data
	void dep(int);	//accept amount and add to balance amount
	void withdraw(int);	//accept amount and subtract from balance amount
	void report() const;	//show data in tabular format
	int retacno() const;	//return account number
	int retdeposit() const;	//return balance amount
	char rettype() const;	//return type of account
};

void account::create_account()
{
	cout<<"\nEnter The account No. :";
	cin>>acno;
	cout<<"\n\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter Type of The account (Current/Saving) : ";
	cin>>type;
	cout<<"\nEnter The Initial amount(>=500 for Saving Account and >=1000 for current Account) : ";
	cin>>deposit;
	cout<<"\n\n\n Congrats!! Your Account has been Created!!";
}

void account::show_account() const
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
}


void account::modify()
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nModify Type of Account : ";
	cin>>type;
	cout<<"\nModify Balance amount : ";
	cin>>deposit;
}


void account::dep(int x)
{
	deposit+=x;
}

void account::withdraw(int x)
{
	deposit-=x;
}

void account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}


int account::retacno() const
{
	return acno;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}



void intro();



int main()
{	int n;
intro();
	cout<<"No. of customers :"<<endl;
	cin>>n;
	account s[n];
	char c;
	int ch;
	int num;

	for(int i=0;i<n;i++){
	do
	{
		cout<<"\nSelect Option ";
		cout<<"\n01. NEW ACCOUNT";
		cout<<"\n02. DEPOSIT AMOUNT";
		cout<<"\n03. WITHDRAW AMOUNT";
		cout<<"\n04. BALANCE ENQUIRY";
		cout<<"\n05. CLOSE AN ACCOUNT";
		cout<<"\n06. DISPLAY AN ACCOUNT";
		cout<<"\n07. EXIT";

		cin>>ch;

		switch(ch)
		{
		case 1:
			s[i].create_account();
			break;
		case 2:
			cout<<"\n\nDesposit Amount : ";	cin>>num;
			s[i].dep(num);
			break;
		case 3:
			cout<<"\n\n\tWithdraw Amount : "; cin>>num;
			s[i].withdraw(num);
			break;
		case 4:
			cout<<"\n\n\tBalance Enquiry: ";
			s[i].retdeposit();
			break;
		/*case 6:
			display_all();
			break;
		case 5:
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;*/
		 case 7:
			cout<<"\n\n\tThanks for using bank management system";
			break;
		 default :cout<<"\a";
		}
		cout<<"Do you want to continue:(y/n)";
		cin>>c;
	}while(c=='y');
	}
	return 0;
}






void intro()
{
	cout<<"\n\n\n\t  BANK MANAGEMENT SYSTEM";
	cout<<"\n\n\n\nMADE BY : Atharv Kulkarni(21233) & Nikhil Kulkarni(21234) ";
	cout<<"\n\nSUBJECT : OOP";
	cin.get();
}
