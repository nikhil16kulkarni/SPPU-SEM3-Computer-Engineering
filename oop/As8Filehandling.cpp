//============================================================================
// Name        : Assignment8.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include<iostream>
using namespace std;

class student
{
	char name[20];
	int age;

public:
	void getdata()
	{
		cout<<"Enter name ";
		cin>>name;
		cout<<"Enter age ";
		cin>>age;
	}
	void display()
	{
		cout<<"\nName "<<name;
		cout<<"\nAge "<<age;

	}
};

int main()
{
	student s;
	char ch;
	fstream f;
	f.open("object.txt",ios::in|ios::out|ios::app|ios::binary);
	do{
	s.getdata();
	f.write((char*)&s,sizeof(s));
	cout<<"Enter your choice ";
	cin>>ch;
	}while(ch=='y');
	f.seekg(0);
	while(f)
	{
	f.read((char*)&s,sizeof(s));
	if(f.eof())
		break;
	s.display();
	}

}
