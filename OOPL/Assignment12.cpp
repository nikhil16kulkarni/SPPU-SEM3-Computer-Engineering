//============================================================================
// Name        : deque.cpp
// Author      : kandlagunta rohith
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<deque>
using namespace std;
void print_deque(deque <int> d)
{
	while(!d.empty())
	{
		cout<<d.back()<<" ";
		d.pop_back();
	}
	cout<<endl;
}
int main()
{
	deque <int> d;
	int t=1;
	while(t)
	{
		cout<<"Enter Choice:\n1.Push Front\n2.Push Back\n3.Pop Front\n4.Pop Back\n5.Size of Deque\n6.Display Front\n7.Display back\n8.Display Deque\n9.EXIT"<<endl;
		int c;
		cin>>c;
		switch(c)
		{
		case 1:cout<<"Enter Element: "<<endl;
		int n;
		cin>>n;
		d.push_front(n);
		break;
		case 2:cout<<"Enter Element: "<<endl;
		cin>>n;
		d.push_back(n);
		break;
		case 3:d.pop_front();
		break;
		case 4:d.pop_back();
		break;
		case 5:cout<<"Size of Deque: "<<d.size()<<endl;
		break;
		case 6:cout<<"Front Element of Deque: "<<d.front()<<endl;
		break;
		case 7:cout<<"Back Element of Deque: "<<d.back()<<endl;
		break;
		case 8:print_deque(d);
		break;
		case 9:t=0;
		}
	}

	return 0;
}
