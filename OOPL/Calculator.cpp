//============================================================================
// Name        : Calculator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

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




