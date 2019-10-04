//============================================================================
// Name        : Assignment13.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

void swap(int s1,int s2)
{
    int t = s1;
    s1=s2;
    s2=t;
}

int partition(float ar[],int start,int end)
{
    float a = ar[end];
    int b =(start-1);

    for(int j=start;j<=end-1;j++)
    {
        if (ar[j]<=a)
        {
            b++;
            swap(ar[b],ar[j]);
        }
    }
    swap(ar[b+1],ar[end]);
    return (b+1);
}

void quicksort(float ar[],int start,int end)
{
    if (start<end)
    {

        int pi= partition(ar,start,end);
        quicksort(ar,start,pi-1);
        quicksort(ar,pi+1,end);
    }
}

int main() {
	cout<<"Enter total no. of students"<<endl;
	int n;
	cin>>n;
	cout<<"Enter Percentage of each student"<<endl;
	float p[n];
	for(int i=0;i<n;i++)	cin>>p[i];
	quicksort(p,0,n-1);
	for(int i=n;i>=n-5;i--)	cout<<p[i]<<endl;
}
