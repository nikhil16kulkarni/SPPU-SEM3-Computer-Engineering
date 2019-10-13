//============================================================================
// Name        : Assignment13.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
/*class personal
{

	string name;
	string dob;
	long int tel;
public:
	personal()
	{
		name='\0';
		dob='\0';
		tel=0;
	}
	string getname()
	{
		return name;
	}
	void getdata()
	{
		cout<<"\nEnter name ";
		cin>>name;
		cout<<"Enter date of birth ";
		cin>>dob;
		cout<<"Enter telephone number ";
		cin>>tel;
		cout<<endl;
	}

	void display()
	{
		cout<<"Name : "<<name<<endl;
		cout<<"Date of birth : "<<dob<<endl;
		cout<<"Telephone number : "<<tel<<endl;
	}

};
bool compare(personal a1,personal a2)
  {
	   return (a1.getname()<(a2.getname()));
  }
int main()
{
	int m;
	cout<<"Enter number of students ";
	cin>>m;
	personal p[m];
	string search;
	int k,l;
	char ch;
	cout<<"1)Personal record 2)Item record ";
	cin>>l;
	switch(l)
	{
	 case 1:
	   {
		   do
		  {
		   cout<<"Enter your choice\n1)Input\n2)Sorting\n3)Searching\n4)Display ";
	       cin>>k;

	       switch(k)
	       {
	       case 1:
	          for(int i=0;i<m;i++)
	          {
	        	  p[i].getdata();
	          }
	          break;
	       case 2:

	    		  sort(p,p+m,compare);
	    		  cout<<"\nSorted list is "<<endl;
	    		 for(int i=0;i<m;i++)
	    		 {
	    		  p[i].display();
	    		 }
	    	     break;



	       case 3:
	       { cout<<"Enter the name to be searched ";
              cin>>search;
              string temp[m];
              for(int i=0;i<m;i++)
              {
            	temp[i]=p[i].getname();
              }
              if(binary_search(temp,temp+m,search))
                cout<<"Person is present ";
              else
            	cout<< "Person is absent ";
              break;
	       }
	       case 4:
	    	   p[0].display();
	    	   break;
           }
	       cout<<"\nDo you want to continue ";
	       cin>>ch;

	      }while(ch=='y');

	   }
	   break;
	}

return 0;
}*/
int main()
{
	long long int n;
	long int t;
	cin>>t;


	for(int i=0;i<t;i++)
	{
		cin>>n;
		while(n%59!=0)
		{
		 n=n%59;
		}
		int a[n];
		a[0]=0;
		a[1]=1;
		for(int i=2;i<n;i++)
		{
			a[i]=a[i-1]+a[i-2];

		}
		while(n/2!=0)
		{
			int k=1;
			for(int j=0;j<n/2;j++)
			{
				a[j]=a[k];
		        k=k+2;
			}
		   n=n/2;
		}
      cout<<(a[0])%10;

	}

return 0;
}





