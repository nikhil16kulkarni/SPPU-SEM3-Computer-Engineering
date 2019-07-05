//============================================================================
// Name        : Complex_no.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Problem Statement :
//Implement a class Complex which represents the Complex Number data
//type. Implement the following operations:
//1. Constructor (including a default constructor which creates the
//complex number 0+0i).
//2. Overloaded operator+ to add two complex numbers.
//3. Overloaded operator* to multiply two complex numbers.
//4. Overloaded << and >> to print and read complex Numbers.


#include <iostream>
using namespace std;

class complex{
	float r,im;
public:
	void getData(){
		cout<<endl<<"Enter Complex no."<<endl;
		cin>>r>>im;
	}
	void display(){
		cout<<endl<<"Given complex no. is"<<endl;
		cout<<r<<"+"<<im<<"i";
	}
	complex operator +(complex c2){
		complex c3;
		c3.r=r+c2.r;
		c3.im=im+c2.im;
		return c3;
	}
	complex operator -(complex c2){
			complex c3;
			c3.r=r-c2.r;
			c3.im=im-c2.im;
			return c3;
		}
	complex operator *(complex c2){
		complex c3;
		c3.r=((r*c2.r)-(im*c2.im));
		c3.im=((r*c2.im)+(im*c2.r));
		return c3;
	}
	complex operator /(complex c2){
		complex c3;
		c3.r=(((r*c2.r)+(im*c2.im))/((c2.r*c2.r)+(c2.im*c2.im)));
		c3.im=(((im*c2.r)-(r*c2.im))/((c2.r*c2.r)+(c2.im*c2.im)));
		return c3;
		}
	void dis(){

		if(im>0)
			cout<<r<<"+"<<im<<"i"<<endl;
		else
			cout<<r<<im<<"i"<<endl;
	}
};
int main(){
	complex c1,c2,c3;
	char choice;
		char a;
		do{
		c1.getData();
		c2.getData();
		c1.display();
		c2.display();
		cout<<endl<<"Enter operator(+,-,*,/)"<<endl;
		cin>>choice;
		switch (choice)
		{
		case '+' :  c3=c1+c2;
					cout<<endl<<"Addition is"<<endl;
					c3.dis();
			break;
		case '-' :  c3=c1-c2;
					cout<<endl<<"Subtraction is"<<endl;
					c3.dis();
					break;
		case '*' :  c3=c1*c2;
					cout<<endl<<"Multiplication is"<<endl;
					c3.dis();
			break;
		case '/' :  c3=c1/c2;
					cout<<endl<<"Division is"<<endl;
					c3.dis();
			break;
		default :
			cout<<"Incorrect operator entered"<<endl;
		}
		cout<<"Do Another?(y/n)";
		cin>>a;
		}
		while(a=='y');
			return 0;
}
