//============================================================================
// Name        : Assignment12(b)Shell.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class student
{
	float m;
public:

	void sort(int n,student s[],int i)
	{
		for(int k=n/2;k>0;k/=2)
		    {
		        for(int i=k;i<n;i++)
		        {
		            int temp=s[i].m;
		            int j;
		            for (j=i;j>=k&&s[j-k].m>temp;j-=k)
		                s[j].m =s[j-k].m;
		            s[j].m=temp;
		        }
		    }
	}
	void display(int n,student s[])
		{
			int i;
			for(i=0;i<n;i++)
			{
				cout<<s[i].m<<endl;
			}
		}
	void getdata()
	{
		cin>>m;
	}
};
int main() {
	int n;
	cin>>n;
	student s[n];
	int i;
	for(i=0;i<n;i++)
		{
			s[i].getdata();
		}
	for(i=0;i<n;i++)
	{
		s[i].sort(n,s,i);
	}
	s[0].display(n,s);
}

