//============================================================================
// Name        : Assignment11(a).cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class student
{
	int roll;
public:
	void get()
	{
		cin>>roll;
	}
	void linear(int r,int n,student s[])
	{	cout<<"Linear Search"<<endl;
		int i;

		for(i=0;i<n;i++)
		{
			if(r==s[i].roll)
			{
				cout<<"present at position "<<i<<endl;
				break;
			}
		}
		if(i==n)
		{
			cout<<"Not present"<<endl;
		}
	}
	void sentinel(int r, int n,student s[])
	{	cout<<"Sentinel Search"<<endl;
		s[n].roll=r;
		int i=0;
		while(s[i].roll!=r)
			{
			i++;}


					if(i<n)
					{
						cout<<"present at position "<<i<<endl;

					}
					else
					{
						cout<<"not present"<<endl;


					}
	}
};

int main() {
	int n;
	cout<<"Enter no. of students"<<endl;
	cin>>n;
	student s[n+1];
	int i;
	cout<<"Enter roll no."<<endl;
	for(i=0;i<n;i++)
	{
		s[i].get();
	}
	int r;
	cout<<"Enter the roll no. of student to be searched"<<endl;
	cin>>r;
	s[0].linear(r,n,s);
	s[0].sentinel(r,n,s);
}
