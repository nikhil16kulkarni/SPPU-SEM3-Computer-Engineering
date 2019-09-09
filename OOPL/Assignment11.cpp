//============================================================================
// Name        : Assignment11.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
/* Problem Statement :  Write C++ program using STL for implementation of stack & queue using SLL */
//============================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
stack<int> st;
queue<int> qu;
int choice, item,ch;
char yn;
Start:

cout<<"\n\t\tImplementation of Stack and Queue using STL.\n";
cout<<"\n 1) Stack\n 2)Queue\n";
cout<<"Enter your choice:";
cin>>ch;

if(ch==1)
{
while (1)
{
cout<<"Stack Implementation in STL"<<endl;
cout<<"1.Insert Element into the Stack"<<endl;
cout<<"2.Delete Element from the Stack"<<endl;
cout<<"3.Size of the Stack"<<endl;
cout<<"4.Top Element of the Stack"<<endl;
cout<<"5.Exit"<<endl;
cout<<"6.Display"<<endl;
cout<<"Enter your Choice: ";
cin>>choice;
switch(choice)
{
case 1:
cout<<"Enter value to be inserted: ";
cin>>item;
st.push(item);
break;
case 2:
item = st.top();
st.pop();
cout<<"Element "<<item<<" Deleted"<<endl;
break;
case 3:
cout<<"Size of the : ";
cout<<st.size()<<endl;
break;
case 4:
cout<<"Top Element of the Stack: ";
cout<<st.top()<<endl;
break;
case 5:
exit(1);
case 6:
	cout<<"Displaying all the elements of stack:"<<endl;
	while(!st.empty()){
		cout<<st.top()<<endl;
		st.pop();
	}
	break;
break;
default:
cout<<"Wrong Choice"<<endl;
}
}
}

else if(ch==2)
{
while(1)
{
cout<<"\n Queue Implementation in STL"<<endl;
cout<<"\n1.Insert Element into the queue";

cout<<"1.Insert Element into the Queue"<<endl;
cout<<"2.Delete Element from the Queue"<<endl;
cout<<"3.Size of the Queue"<<endl;
cout<<"4.Front Element of the Queue"<<endl;
cout<<"5.Last Element of the Queue"<<endl;
cout<<"6.Exit"<<endl;
cout<<"7.Display"<<endl;
cout<<"Enter your Choice: ";
cin>>choice;
switch(choice)
{
case 1:
cout<<"Enter value to be inserted: ";
cin>>item;
qu.push(item);
break;
case 2:
item = qu.front();
qu.pop();
cout<<"Element "<<item<<" Deleted"<<endl;
break;
case 3:
cout<<"Size of the Queue: ";
cout<<qu.size()<<endl;
break;
case 4:
cout<<"Front Element of the Queue: ";
cout<<qu.front()<<endl;
break;
case 5:
cout<<"Back Element of the Queue: ";
cout<<qu.back()<<endl;
break;
case 6:
exit(1);
case 7:
	cout<<"Displaying all the elements of queue:"<<endl;
	while(!qu.empty()){
		cout<<qu.front()<<endl;
		qu.pop();
	}
	break;
break;
default:
cout<<"Wrong Choice"<<endl;
}

}
}

else
{
cout<<"\nWrong choice.\1";
goto Start;
}

cout<<"\nDo you want to continue? Yes(y) No(n):";
cin>>yn;

if(yn=='y')
{
goto Start;
}
return 0;
}
