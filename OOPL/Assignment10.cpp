//============================================================================
// Name        : Assignment7.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
template<class t,class t1>
void ssort(t a[],t1 n)
{
	int i,j;
	t max;
	int k;
	for(i=0;i<n;i++)
	{
		max=a[i];
		for(j=i+1;j<n-1;j++)
		{
			 if(max>a[j])
			 {
				 max=a[j];
				 k=j;
			 }
		}
		t temp;
		temp=a[i];
		a[i]=a[k];
		a[k]=temp;
		cout<<a[i]<<endl;
	}
	cout<<a[n]<<endl;

}
int main()
{
	int n;
	cout<<"Enter no. of elements: ";
	cin>>n;

	int a[n];
	float b[n];
	char c[n];
	int i;
	cout<<"Enter int values: ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter float values: ";
	for(i=0;i<n;i++)
	{
		cin>>b[i];
	}
	cout<<"Enter char values: ";
	for(i=0;i<n;i++)
	{
		cin>>c[i];
	}
	ssort(a,n);
	ssort(b,n);
	ssort(c,n);
}
