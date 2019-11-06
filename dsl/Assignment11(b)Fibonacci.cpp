//============================================================================
// Name        : Assignment11(b)Fibonacci.cpp
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
	int min(int x, int y) { return (x<=y)? x : y; }
	int fib(int x, int n, student s[])
	{
	    int f2= 0;
	    int f1 = 1;
	    int fm = f2+ f1;
	    while (fm < n)
	    {
	        f2 = f1;
	        f1 = fm;
	        fm  = f2 + f1;
	    }
	    int offset = -1;
	    while (fm > 1)
	    {
	        int i = min(offset+f2, n-1);
	        if (s[i].roll < x)
	        {
	            fm  = f1;
	            f1 = f2;
	            f2 = fm - f1;
	            offset = i;
	        }
	        else if (s[i].roll > x)
	        {
	            fm  = f2;
	            f1 = f1 - f2;
	            f2 = fm - f1;
	        }
	        else
	        {
	        	cout<<"Present"<<"\n";
	        	return 0;
	        }
	    }
	    if(f1 && s[offset+1].roll==x)
	    {
	    	cout<<"Present"<<"\n";
	    	return 0;
	    }


	    cout<<"Absent\n";
	    return 0;
	}
};

int main() {
	int n;
	cin>>n;
	student s[n+1];
	int i;
	for(i=0;i<n;i++)
	{
		s[i].get();
	}
	int r;
	cin>>r;
	s[0].fib(r,n,s);
}

