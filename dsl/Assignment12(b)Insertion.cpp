//============================================================================
// Name        : Assignment12(b)Insertion.cpp
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
		cin>>m;
		int j,k;
		int temp;
		for(j=0;j<i;j++)
		{
			if(m<s[j].m)
			{
				temp=m;
				k=i-1;
				while(s[k].m>temp&&k>=0)
				{
					s[k+1].m=s[k].m;
					k--;
				}
				s[k+1].m=temp;
				break;
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
};
int main(){
	int n;
	cin>>n;
	student s[n+1];
	int i;
	for(i=0;i<n;i++)
	{
		s[i].sort(n+1,s,i);
	}
	s[0].display(n,s);
}
