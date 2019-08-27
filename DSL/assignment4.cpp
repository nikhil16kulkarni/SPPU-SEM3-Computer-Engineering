//============================================================================
// Name        : Assignment4.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
/* Problem Statement :  Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of Second, third and final year of department can be granted membership on request. Similarly one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club. Write C++ program to maintain club member‘s information using singly linked list. Store student PRN and Name. Write functions to
			Add and delete the members as well as president or even secretary.
			Compute total number of members of club 
			Display members 
			Display list in reverse order using recursion 
			Two linked lists exists for two divisions. Concatenate two lists
			Merge two sorted singly linked lists.*/
//============================================================================


/*INCOMPLETE*/

#include<bits/stdc++.h>
#include<string>
using namespace std;
class node
{
public:
	char name[100];
	long int PRN;
	node * link;

};
class llist
{
public:
	node* previous;
	node* start;
	node* current;
	node* last;
	int count;
	llist()
	{
		start=NULL;
		last=NULL;
		previous=NULL;
	}
	void insert()
	{
		int location;
		node* new1=new node;


		if(start==NULL)
		{
			cout<<"Enter the member name: ";
			cin>>new1->name;
			cout<<"Enter PRN no.: ";
			cin>>new1->PRN;
			start=new1;
			new1->link=last;
			return;
		}
		cout<<"Enter location to add the element: ";
		cin>>location;
		cout<<"Enter the member name: ";
		cin>>new1->name;
		cout<<"Enter PRN no.: ";
		cin>>new1->PRN;
		if(location==1)
		{
			new1->link=start;
			start=new1;
		}
		else
		{
			previous=start;
			count=1;
			while(count<=location-1&&previous!=NULL)
			{
				previous=previous->link;
				count++;
			}
			new1->link=previous->link;
			previous->link=new1;
		}
	}
	void delete1()
		{
			int location;
			cout<<"Enter the location for deletion: ";
			cin>>location;
			current=start;
			previous=NULL;
			if(start==NULL)
			{
				cout<<"Empty list";
			}
			else if(location==1)
			{
				start=current->link;
				current->link=NULL;
				delete(current);
			}
			else
			{
				int i;
				for(i=1;i<=location-1;i++)
				{
					previous=current;
					current=current->link;
				}
				previous->link=current->link;
				current->link=NULL;
				delete(current);
			}
		}
	void compute()
	{
		int n=0;
		current=start;
		while(current->link!=NULL)
		{
			current=current->link;
			n++;
		}
		cout<<"Total no. of members are:"<<n+1<<endl;
	}
	void display()
	{
		current=start;
		while(current->link!=NULL)
		{
			cout<<"Member: "<<current->name<<endl<<"PRN: "<<current->PRN<<endl;
			current=current->link;
		}
		cout<<"Member: "<<current->name<<endl<<"PRN: "<<current->PRN<<endl;

	}
	void reverse(node* head)
	{

		if(head==NULL)
		{
			return;
		}
		reverse(head->link);
		cout<<"Member: "<<head->name<<endl<<"PRN: "<<head->PRN<<endl;
	}
	void insert1()
	{

	}
	void con(llist l,llist k)
	{

		l.current=l.start;
		int i;
		previous=l.current;
		for(i=0;i<l.count;i++)
		{

			node* new1=new node;
			if(start==NULL)
			{
				start=new1;
				new1->PRN=l.current->PRN;
				previous->link=new1;
			}
			else
			{
				previous->link->link=new1;
				new1->PRN=l.current->PRN;
				previous->link=new1;
			}
			l.current=l.current->link;
		}
		k.current=k.start;
		for(i=0;i<k.count;i++)
		{
			node* new1=new node;
			previous->link->link=new1;
			new1->PRN=k.current->PRN;
			previous->link=new1;
			k.current=k.current->link;
		}
		previous->link->link=NULL;
/*		new1->PRN=l.current->PRN;
		for(i=1;i<l.count-1;i++)
		{
			node* new2=new node;
			new1->link=new2;

			l.current=l.current->link;

			new1->PRN=l.current->PRN;
			new3->link=new2->link;
		}
		new1->PRN=l.current->PRN;
		k.current=k.start;

		new1->PRN=k.current->PRN;
		for(i=1;i<k.count-1;i++)
		{
			node* new2=new node;
			new1->link=new2;
			k.current=k.current->link;

			new2->PRN=k.current->PRN;
			new1->link=new2->link;
		}
		new1->PRN=k.current->PRN;	*/

		}
	void ssort()
	{
		current=start;
		int i,j;
		long int temp;
		for(i=0;i<count;i++)
		{
			current=start;
			for(j=0;j<count-1;j++)
			{
				if(current->PRN>current->link->PRN)
				{
					temp=current->PRN;
					current->PRN=current->link->PRN;
					current->link->PRN=temp;
				}
				current=current->link;
			}
		}
	}

};

int main() {
	llist l,k,m;
	char a='y';

	do
		{
			l.insert();
			cout<<"Do you want to add another member(y/n)??: ";
			cin>>a;
		}while(a!='n');
	do
			{
				k.insert();
				cout<<"Do you want to add another member(y/n)??: ";
				cin>>a;
			}while(a!='n');
/*	do
		{
			l.delete1();
			cout<<"Do you want to delete another member(y/n)??: ";
			cin>>a;
		}while(a!='n');
	l.compute();
	l.display();
	k.compute();
	k.display();
	l.reverse(l.start);
	m.con(l,k);
	m.display();
	l.ssort();
	l.display();	*/
}

