//============================================================================
// Name        : Ass5.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
#include<cstring>
#include<iostream>

using namespace std;
class database
{	static int count;
	int roll;
	string name;
	int cls;
	char div;
	string birth;
	string bloodgp;
	string address;
	long long int tele;
	long long int lic;
public:
	database ()
	{
		count++;
		roll=1;
		name="XYZ";
		cls=1;
		div='A';
		birth="1/1/2000";
		bloodgp="none";
		address="No address";
		tele=0000000;
		lic=00000000000;
	}
	database(int roll,string name,int cls,char div,string birth,string bloodgp,string address,long long int tele,long long lic)
	{
		count++;
		this ->roll=roll;
		this ->name=name;
		this ->cls=cls;
		this ->div=div;
		this ->birth=birth;
		this ->bloodgp=bloodgp;
		this ->address=address;
		this ->tele=tele;
		this ->lic=lic;

	}
	database(database &s)
	{
		count++;
		roll=s.roll;
		name=s.name;
		cls=s.cls;
		div=s.div;
		birth=s.birth;
		bloodgp=s.bloodgp;
		address=s.address;
		tele=s.tele;
		lic=s.lic;
	}
	friend class personal;
	~database()
	{
		cout<<"Object destroyed";
	}

};
class personal
{
public:
	void display(database &s)
	{
		cout<<s.roll<<endl;
		cout<<s.name<<endl;
		cout<<s.cls<<endl;
		cout<<s.div<<endl;
		cout<<s.birth<<endl;
		cout<<s.bloodgp<<endl;
		cout<<s.address<<endl;
		cout<<s.tele<<endl;
		cout<<s.lic<<endl;

	}
};
int database ::count=0;

int main() {
	database s1;
	database s2(2,"Viraj",9,'B',"5/6/2001","B+","sosdnosncsasasdjbv",2426543,435252434),s3(s2);
	personal p1,p2,p3;
	p1.display(s1);
	p2.display(s2);
	p3.display(s3);



}
