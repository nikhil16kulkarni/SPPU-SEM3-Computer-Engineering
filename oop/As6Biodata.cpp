//============================================================================
// Name        : Assignment6.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
/* Problem Statement :  Create employee bio-data using following classes
			i)Personal record
			ii)Professional record
			iii)Academic record
			Assume appropriate data members and member function to accept required
			data & print bio-data. Create bio-data using multiple inheritances using C++ */
//============================================================================


#include <bits/stdc++.h>
using namespace std;
class personal
		{
	string name;
	int age;
		public:
	personal()
		{
			age=0;
			name="";
			cout<<"Personal Constructor"<<endl;
		}
	void getdata()
	{
		cout<<"Enter name: ";
		getline(cin,name);
		cout<<"Enter age: ";
		cin>>age;
	}
	void putdata()
	{
		cout<<name<<endl<<age<<endl;
	}
	~personal()
	{
		cout<<"Personal Destructor"<<endl;
	}
		};
class professional
{
	string qual;
	int exp;
public:
	professional()
			{
				exp=0;
				qual="";
				cout<<"Professional Constructor"<<endl;
			}
		void getdata()
		{
			cout<<"Enter qualification: ";
			cin>>qual;
			cout<<"Enter experience: ";
			cin>>exp;
		}
		void putdata()
		{
			cout<<qual<<endl<<exp<<endl;
		}
		~professional()
		{
			cout<<"Professional Destructor"<<endl;
		}
};
class academic
{
	int percent;
	char grade;
public:
	academic()
			{
				percent=0;
				grade='Z';
				cout<<"Academic Constructor"<<endl;
			}
		void getdata()
		{
			cout<<"Enter Percentage: ";
			cin>>percent;
			cout<<"Enter grade: ";
			cin>>grade;
		}
		void putdata()
		{
			cout<<percent<<"%"<<endl<<grade<<endl;
		}
		~academic()
		{
			cout<<"Professional Destructor"<<endl;
		}
};
class employee:public personal,public professional,public academic
{
public:
	employee()
{
		cout<<"Employee contructor"<<endl;
}
	void getdata()
	{
		personal::getdata();
		professional::getdata();
		academic::getdata();
	}
	void putdata()
	{
		personal::putdata();
		professional::putdata();
		academic::putdata();
	}
~employee()
{
	cout<<"Empolyee Destructor"<<endl;
}
};
int main() {
 employee e;
 e.getdata();
 e.putdata();
	return 0;
}
