//============================================================================
// Name        : Assignment2(String).cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style

// Problem statement : Write C++ program with class for String. Write a function  
//                     Copy, Concatenate, check substring, Equal, Reverse and Length.
//                     Frequency that determines the frequency of occurrence of particular character in the string.  
//                     Delete that accepts two integers, start and length. The function computes a new string that is equivalent to the original string, except that length characters being at start have been removed.  
//                     Chardelete that accepts a character c. The function returns the string with all occurrences of c removed.  
//                     Replace to make an in-place replacement of a substring w of a string by the string x. note that w may not be of same size of x . 
//                     Palindrome to check whether given string is palindrome or not
//                     (Note: Make use of character array to perform all operations)

//============================================================================
// INCOMPLETE //
#include <iostream>
using namespace std;
class String
{
	char str[200];
	int len;
public:
String()
{
	cout<<"Enter the string\n";
	cin.getline(str,199);
}
	void copy();
	void length();
	void equal();
	void concat();
	void rev();
	void substring();
	void freq();
	void del();
	void chardelete();
};
void String::copy()
{
	int i=0;
	char scpy[200];
	while(str[i]!='\0')
	{
		scpy[i]=str[i];
		i++;
	}
	scpy[i]='\0';
	cout<<"\nThe copied string is:"<<scpy;
}
void String::length()
{
	int i=0;
	while(str[i]!='\0')
	{
		i++;
	}
	len=i;
	cout<<"Length of the string is "<<len;
}
void String::equal()
{
	int i=0,j=0,flag=0;
	char snew[200];
	cout<<"\nEnter another String to check whether equal or not\n";
	cin.getline(snew,199);
	while(str[i]!='\0'||snew[j]!='\0')
	{
		if(str[i]!=snew[j])
		{
			cout<<"Both strings are not equal\n";
			flag=1;
			break;
		}
		i++;
		j++;
	}
	if(i==j&&flag==0)
	{
		cout<<"Both strings are equal\n";
	}
}
void String::concat()
{
	char scat[200];
	int j=0,i=len;
	cout<<"\nEnter the string to concat with first string\n";
	cin.getline(scat,199);
	while(scat[j]!='\0')
	{
		str[i]=scat[j];
		i++;
		j++;
	}
	str[i]='\0';
	cout<<"After concatenation the new string is\n"<<str;
}
void String::rev()
{
	char srev[200];
	int i=0;
	while(str[i]!='\0')
	{
		srev[i]=str[len-1-i];
		i++;
	}
	srev[i]='\0';
	cout<<"Reverse string is:"<<srev;
}
void String::substring()
{
	char sub[199],sub2[199];
	int i,lsub,j=0,pos,length,flag=0;
	cout<<"\nEnter the position and length from which substring has to be taken\n";
	cin>>pos>>length;
	i=0;
	while(i<length)
	{
		sub[i]=str[pos+i-1];
		i++;
	}
	sub[i]='\0';
	cout<<"SubString is "<<sub;
	cout<<"\nEnter the string to check whether substring or not\n";
	cin.ignore(1);
	cin.getline(sub2,198);
	i=0;
	while(sub2[i]!='\0')
	{
		i++;
	}
	lsub=i;
	i=0;
	while(str[i]!='\0'&&sub2[j]!='\0')
	{
		if(str[i]==sub2[j])
		{
			flag++;
			i++;
			j++;
		}
		else
		{
			flag=0;
			i++;
		}
	}
	if(flag==lsub)
	{
		cout<<"SubString is present\n";
	}
	else
	{
		cout<<"SubString not present\n";
	}
}
void String::freq()
{
	int cnt=0,i;
	char ch;
	cout<<"Enter the character whose frequency you wish to find\n";
	cin>>ch;
	for(i=0;i<len;i++)
	{
		if(str[i]==ch)
		{
			cnt++;
		}
	}
	cout<<"Frequency of the character is "<<cnt<<endl;
}
void String::del()
{
	char sub[199];
	int i=0,length,start;
	cout<<"Enter the start and length from which new string has to be taken\n";
	cin>>start>>length;
	while(i<length)
	{
		sub[i]=str[start+i];
		i++;
	}
	sub[i]='\0';
	cout<<"New String is "<<sub;
}
void String::chardelete()
{
	int i=0,j=0;
	while(str[i]!='\0')
	{
		if(str[i]=='c'||str[i]=='C')
		{
			j=i+1;
			while(str[j]!='\0')
			{
				str[j-1]=str[j];
				j++;
			}
		}
		i++;
	}
	cout<<endl<<"After removing C/c the new string is:"<<str;
}
int main()
{
	String Str;
	Str.length();
	Str.copy();
	Str.equal();
	Str.rev();
	Str.concat();
	Str.substring();
	Str.freq();
	Str.chardelete();
	//Str.del();
	//Str.chardelete();
	return 0;
}
