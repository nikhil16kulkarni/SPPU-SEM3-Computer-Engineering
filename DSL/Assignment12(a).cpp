//============================================================================
// Name        : Assignment12(a).cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style

// Problem Statement : Write C++ program to store first year percentage of students in array. Write function for sorting array 
//                     of floating point numbers in ascending order using 
//             	       a) Selection Sort 
//	               b) Bubble sort 
//	               and display top five scores.
//============================================================================

#include <iostream>
using namespace std;
class student
{
    float m;
public:
    void getdata()
    {
    	cin>>m;
    }
    void arrange(int n,student s[])
{
	int i,j,k;
	float min;
	float temp;
	for(i=0;i<n;i++)
	{
		min=s[i].m;
		k=i;
	for(j=i+1;j<n;j++)
	{

		if(min>s[j].m)
		{
			min=s[j].m;
			k=j;
		}
	}
		temp=s[k].m;
		s[k].m=s[i].m;
		s[i].m=temp;
		cout<<s[i].m<<endl;

	}
	cout<<"top five scores are: "<<endl;
	for(i=n-1;i!=n-6;i--)
	{
		cout<<s[i].m<<endl;
	}


}

    void arrange1(int n, student s[])
    {
    	int i,j,temp;
    	for(i=0;i<n-1;i++)
    	{
    		for(j=0;j<n-i-1;j++)
    		{
    			if(s[j].m>s[j+1].m)
    			{
    				temp=s[j].m;
    				s[j].m=s[j+1].m;
    				s[j+1].m=temp;
    			}
    		}
    	}
    	for(i=0;i<n;i++)
    	{
    		cout<<s[i].m<<endl;
    	}
    	cout<<"top five scores are: "<<endl;
    		for(i=n-1;i!=n-6;i--)
    		{
    			cout<<s[i].m<<endl;
    		}
    }
};

int main()
{
	int n;
	cout<<"Enter the no. of students: ";
	cin>>n;
	student s[n];
	student s1[n];
	int i;
	cout<<"Enter Percentage"<<endl;
	for(i=0;i<n;i++)
	{
		s[i].getdata();
	}

	cout<<"Selection Sort"<<endl;;
	s[0].arrange(n,s);
	cout<<"Enter Percentage"<<endl;
	for(i=0;i<n;i++)
		{
			s1[i].getdata();
		}
	cout<<"Bubble Sort"<<endl;;
	s1[0].arrange1(n,s1);

}
