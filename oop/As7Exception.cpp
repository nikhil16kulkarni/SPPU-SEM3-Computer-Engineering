//============================================================================
// Name        : Assignment7.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class person
{
	int age;
	double income;
	bool vehicle;
    int city;
public:
	class error
	{

	};

	void getdata()
	{
		cout<<"Enter age ";
		cin>>age;
		cout<<"Enter income ";
	    cin>>income;
	    cout<<"Enter vehicle 1)yes 2)no  ";
	    cin>>vehicle;
	    cout<<"Enter city 1)Pune 2)Mumbai 3)Banglore 4)Chennai 5)Other ";
	    cin>>city;



		if(age<18 || age>55)
			throw error();
		if(income<50000 || income>100000)
			throw error();
		if(vehicle==0)
			throw error();
		if(city==5)
	        throw error();
	}



	void display()
	{
		cout<<"\nAge "<<age;
		cout<<"\nIncome "<< income;
	    cout<<"\nVehicle 1)yes 2)no  "<<vehicle;
	    cout<<"\nCity "<<city;
	}

};
int main()
{
	person a1;
	int flag=1;
	try
	{
	 a1.getdata();
	}

	catch(person::error)
		{

		  cout<<"Invalid";
		  flag=0;
		}
	if(flag==1)
		{cout<<"\nEntered data is correct ";}
	a1.display();

}
