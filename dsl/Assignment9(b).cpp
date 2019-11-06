//============================================================================
// Name        : Assignment9(b).cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define size 5

class spq
{
    int f,r,job,djob;            
    int prioq[size];
public:
    spq() 
    {
     f=r=-1; 
     job=djob=0;
     prioq[-1]=0;
    }
  
    int isQfull()
    {
        if(r==size-1)
            return 1;
        else
            return 0;
    }

    int isQempty()
    {
        if((f==-1)||(f>r))
            return 1;
        else
            return 0;
    }
    
    void prioqadd();
    void delprioQ();
    void showprioQ();
};


void spq::delprioQ()
{
    if(isQempty())
        cout<<"\nSorry Q is empty...\n";
    else
    {
        djob=prioq[f];
        f=f+1;
        cout<<"\nDeleted job is: "<<djob;
    }
}


void spq::showprioQ()
{
    cout<<"\nThe priority Queue job are as follows....\n";
    int temp;
    for(temp=f;temp<=r;temp++)
    {
        cout<<"\t"<<prioq[temp];
    }
}


void spq::prioqadd()
{
    int t=0;
    cout<<"\nEnter the job: ";
    cin>>job;
    if(isQfull())
        cout<<"\nSorry!! Priority Queue is full...\n";
    else
    {
        if(f==-1)
        {
            f=r=0; 
            prioq[r]=job;
        }
        else if(job<prioq[r]) 
        {
         t=r;
         while(job<prioq[t])
         {
            prioq[t+1]=prioq[t]; 
            t=t-1; 
         }
         t=t+1; 
         prioq[t]=job; 
         r=r+1; 
        }
        else
        {
            r=r+1; 
            prioq[r]=job;
        }
    }
}

int main()
{
    spq s2; 
    int ch;
    do
    {
     cout<< "\n\t!!!Operating System Job Queue!!!" << endl; 
     cout<<"\n1.PrioQ Add Job\n2.PrioQ Del Job\n3.Show PrioQ";
     cout<<"\nEnter Your Choice:";
     cin>>ch;
     switch(ch)
     {
      case 1:s2.prioqadd();break;
      case 2:s2.delprioQ();break;
      case 3:s2.showprioQ();break;
     }
    }while(ch!=4);
    return 0;
}
