 //============================================================================
// Name        : Assignment1.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style

// Problem Statement :
// Write C/C++ program to store marks scored for first test of subject 'Data Structures and Algorithms' for N students. Compute
// I. The average score of class
// II. Highest score and lowest score of class
// III. Marks scored by most of the students
// IV. list of students who were absent for the test

//============================================================================

 #include<iostream>
 using namespace std;

 class student{
 	char name[50];
 	int roll;
 	float marks;

 public:

 	char* getname()
 	{
 		return name;
 	}
 	float getmarks()
 	{
 		return marks;


 	}
 	int getrollno()
 	{
 		return roll;

 	}
 	void read(){
 		cout<<"Enter the name of student"<<endl;
 		cin>>name;
 	    cout<<"Enter the marks scored"<<endl;
 	    cout<<"Enter marks as -1 if the student is absent";
 	    cin>>marks;
 		cout<<"Enter roll number"<<endl;
 		cin>>roll;

 	}
 	void display(){

 		cout<<name<<endl;
 		cout<<marks<<endl;
 		cout<<roll<<endl;
 	}

 };

 class dsclass{
 	int n;
 	int count=0;
 	student s[100];

 public:
 	void read()
 	{  int i;
 	cout<<"Enter number of students"<<endl;
 	cin>>n;
 		for(i=0;i<n;i++)
 		{

 			 s[i].read();
 		}
 	}
 	void display()
 	{
 		int i;
 		for(i=0;i<n;i++)
 		{
 			s[i].display();
 		}
 	}

 	void average()
 	{
 		int i;
 		float sum=0,avg;
 		for(i=0;i<n;i++)
 		{
 			if(s[i].getmarks()!=-1)
 			{
 			sum=sum+s[i].getmarks();
 		}
 			avg=sum/n;



 	}
 		cout<<"Average is"<<avg;
 	}
 	int maximum()
 	{
 		int i;
 		float max = s[0].getmarks();
 		for(i=1;i<n;i++)
 		{
 			if(s[i].getmarks()!=-1)
 			{
 				if(max<s[i].getmarks())
 				max=s[i].getmarks();
 			}
 		}
 		return max;
 	}
	int minimum()
 	{
 		int i;
 		float min=s[0].getmarks();
 		for(i=1;i<n;i++)
 		{
 			if(s[i].getmarks()!=-1)
 			{
 			if(min>s[i].getmarks())
 			{
 				min=s[i].getmarks();
 			}
 		}


 	}
 		return min;
 	}

 	void absent()
 	{
 		int i;
 		for(i=0;i<n;i++)
 		{
 			if(s[i].getmarks()==-1)
 			{
 				cout<<endl<<s[i].getname()<<endl;
 			}
 		}
 	}
 	void most()
 	{
 		int m[n],i,j,r;
 		for( i=0;i<n;i++)
 		{
 			m[i]=0;
		}
 		for(i=0;i<n;i++)
 		{
 			for(j=i+1;j<n;j++)
 			{
 				if(s[i].getmarks()==s[j].getmarks())
 				{
 					m[i]++;
 					r=i;
 				}
 			}
 		}
 		cout<<"maximum students scored"<<s[r].getmarks()<<endl;
 	}



 };


 int main()
 {
 	dsclass s;
 	int x;
 	int b;
 	s.read();
 	s.display();
 	do{
 	cout<<"Enter choice 1-average 2-maximum marks 3-minimum marks 4-list of absent students 5-marks scored by most of students"<<endl;
 	cin>>x;
 	switch(x){



 	case 1:s.average();
 	break;
 	case 2:cout<<"\nMaximum marks are"<<s.maximum();
 	break;
 	case 3:cout<<"\nMinimum marks are"<<s.minimum();
 	break;
 	case 4:s.absent();
 	break;
 	case 5:s.most();
 	break;
 	default:cout<<"wrong input"<<endl;
 	}
 	cout<<"Enter 1 to continue"<<endl;

 	cin>>b;

 	}while(b==1);

 	return 0;


 }


