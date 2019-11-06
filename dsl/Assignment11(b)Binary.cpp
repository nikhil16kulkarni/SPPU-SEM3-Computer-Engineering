//============================================================================
// Name        : Assignment11(b)Binary.cpp
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
	void getdata()
	{
		cin>>roll;
	}
	void binary (int n, student s[],int r)
	{

		int left =0;
		int right =n-1;
		int mid;
		int count=0;
		while(left<right)
		{
			mid=(left+right)/2;
			if(s[mid].roll==r)
			{
				cout<<"Present"<<endl;
				count=1;
				break;
			}
			else if(r<s[mid].roll)
			{
				right=mid-1;
			}
			else
			{
				left=mid+1;
			}
		}
		if(count==0)
		{
			cout<<"Not Present"<<endl;
		}
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
	int r;
	cin>>r;
	s[0].binary(n,s,r);

}
