//============================================================================
// Name        : Calculator.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Problem Statement : 
//Write a C++ program to create a calculator for an arithmetic operator (+, -,
//*, /). The program should take two operands from user and performs the
//operation on those two operands depending upon the operator entered by
//user. Use a switch statement to select the operation. Finally, display the
//result.
//Some sample interaction with the program might look like this:
//Enter first number, operator, second number: 10 / 3
//Answer = 3.333333
//Do another (y/n)? y
//Enter first number, operator, second number: 12 + 100
//Answer = 112
//Do another (y/n)? n


#include <iostream>
using namespace std;

int main() {
	int n1,n2;
	char choice;
	char a;
	do{
	cout<<"Enter 1st number"<<endl;
	cin>>n1;
	cout<<"Enter operator(+,-,*,/)"<<endl;
	cin>>choice;
	cout<<"Enter 2nd number"<<endl;
	cin>>n2;
	switch (choice)
	{
	case '+' : cout<<n1+n2;
		break;
	case '-' : cout<<n1-n2;
		break;
	case '*' : cout<<n1*n2;
		break;
	case '/' : cout<<n1/n2;
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




