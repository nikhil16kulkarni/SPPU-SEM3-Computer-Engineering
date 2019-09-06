//============================================================================
// Name        : Assignment7.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class stack
{
public:
	char s[100];
	int top;
	stack()
	{
		top=-1;
	}
	void push(char s1)
	{
			top++;
			s[top]=s1;

	}
	char top1()
	{
		return s[top];
	}
	void pop()
	{
		s[top]=NULL;

		{
			top--;
		}
	}
};

int main() {
	stack s3;
	string s;
	cin>>s;
	int i,flag=0;
	char x;
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='('||s[i]=='{'||s[i]=='[')
		{
			s3.push(s[i]);
		}
		else if(s3.top==-1)
		{
			cout<<"Incorrect Parenthesis"<<endl;
			flag=1;
			break;
		}
		else
		{
			switch (s[i])
			{
			case '}':
				x=s3.s[s3.top];
				if(x=='('||x=='[')
				{
					flag=1;
					cout<<"Incorrect Parenthesis"<<endl;
					break;
				}
				else
				{
					s3.pop();
				}
				break;
			case ')' :
				x=s3.s[s3.top];
				if(x=='{'||x=='[')
				{
					flag=1;
					cout<<"Incorrect Parenthesis"<<endl;
					break;
				}
				else
				{
					s3.pop();
				}
				break;
			case ']':
				x=s3.s[s3.top];
				if(x=='{'||x=='(')
				{
					flag=1;
					cout<<"Incorrect Parenthesis"<<endl;
					break;
				}
				else
				{
					s3.pop();
				}
				break;
			}
		}
		if(flag==1)
		{
			break;
		}
	}
	if(flag==0)
	{
		cout<<"Correct Parenthesis"<<endl;
	}
}
