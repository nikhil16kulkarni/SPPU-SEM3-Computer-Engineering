//============================================================================
// Name        : Assignment7.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
/* Problem Statement :  In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[]. 
                        Write C++ program using stack to check whether given expression is well parenthesized or not. */
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define size 100

class stack{
    int top;
    char stk[size];
public:
    stack()
    {
     top=-1;
    }
    void push(char);
    char pop();
    int Isfull();
    int Isempty();
};

void stack::push(char x)
{
    top=top+1;
    stk[top]=x;
}

char stack::pop()
{
    char s;
    s=stk[top];
    top=top-1;
    return s;
}

int stack::Isfull()
{
    if(top==size)
        return 1;
    else
        return 0;
}

int stack::Isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int main()
{
    stack s1;
    char exp[20],ch;
    int i=0;
    cout<<"\nEnter the expression to check whether it is valid or invalid :  ";
    cin>>exp;
    if((exp[0]==')')||(exp[0]==']')||(exp[0]=='}'))
    {
        cout<<"\n Invalid Expression.....\n";
        return 0;
    }
    else
    {
        while(exp[i]!='\0')
        {
            ch=exp[i];
            switch(ch)
            {
            case '(':s1.push(ch);break;
            case '[':s1.push(ch);break;
            case '{':s1.push(ch);break;
            case ')':s1.pop();break;
            case ']':s1.pop();break;
            case '}':s1.pop();break;
            }
            i=i+1;
        }
    }
    if(s1.isempty())
    {
        cout<<"\nValid Expresion...!!\n";
    }
    else
    {
        cout<<"\nInvalid Expression or not in well parenthesized....\n";
    }
    return 0;
}





