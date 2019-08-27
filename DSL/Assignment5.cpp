//============================================================================
// Name        : Assignment5.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int flag;
    char movie_name[20];
    char name[20];
    long mno;
    node *next;
    node *prev;
};

struct hnode
{
    node *next;
    int cnt;
};

class Cinemax
{
    hnode *head[11];
    node *temp,*t1,*p;
    int n,i,j;
   public:
    Cinemax()
    {
     for(i=1;i<=10;i++)
     {
      head[i]=new hnode;
          head[i]->next= NULL;
      head[i]->cnt=0;
     }
     temp=t1=p=NULL;
     n=i=j=0;
    }

    void create();
    void show();
    int book_my_show(int,int,char[]);
    int cancel_my_show(int,int,char[]);
};



int Cinemax::book_my_show(int r,int n,char name[20])
{
  cout<<"\nYour request for "<<n <<" Tickets of "<<name<<" movie: \n";
  temp=head[r]->next;
  int max;
  max=head[r]->cnt;
  if(max==7)
  {
   cout<<"\nSorry there is no seat available in this row..";
   return 0;
  }
  else
  {
   int seat[5],cnt=0,sn;
   for(i=0;i<n;i++)
   {
    cout<<"\nEnter the seat no's: ";
    cin>>sn;
    seat[i]=sn-1;
   }
   i=0;
   while(temp->next!=head[r]->next)
   {
    if(cnt!=seat[i])
    {
     cnt++;
     temp=temp->next;
    }
    else
    {
     if(temp->flag==0)
     {
      strcpy(temp->movie_name,name);
      temp->flag=1;
      cout<<"\nEnter u r name:";
      cin>>temp->name;
      cout<<"\nEnter u r mobile no: ";
      cin>>temp->mno;
      head[r]->cnt=head[r]->cnt+1;
      cnt=0;
      temp=head[r]->next;
      i++;
      if(i==n)
        break;
     }
    }
   }
 }
 if((temp->next==head[r]->next))
 {
  if(temp->flag==0)
  {
   strcpy(temp->movie_name,name);
   temp->flag=1;
   cout<<"\nEnter u r name:";
   cin>>temp->name;
   cout<<"\nEnter u r mobile no: ";
   cin>>temp->mno;
   head[r]->cnt=head[r]->cnt+1;
  }
 }
 return 1;
}




int Cinemax::cancel_my_show(int r,int n,char name[20])
{
  cout<<"\nYour cancel request for "<<n <<" Tickets of "<<name<<" movie: \n";
  temp=head[r]->next;
  int max;
  max=head[r]->cnt;
  if(max==-1)
  {
   cout<<"\nSorry there is no such seat available in this row for cancel..";
   return 0;
  }
  else
  {
   int seat[5],cnt=0,sn;
   for(i=0;i<n;i++)
   {
    cout<<"\nEnter the seat no's: ";
    cin>>sn;
    seat[i]=sn-1;
   }
   i=0;
   while(temp->next!=head[r]->next)
   {
    if(cnt!=seat[i])
    {
     cnt++;
     temp=temp->next;
    }
    else
    {
     if(temp->flag==1)
     {
      strcpy(temp->movie_name,"NIL");
      temp->flag=0;
      strcpy(temp->name,"NIL");
      temp->mno=00;
      head[r]->cnt=head[r]->cnt-1;
      cnt=0;
      temp=head[r]->next;
      i++;
      if(i==n)
        break;
     }
    }
   }
 }
 if((temp->next==head[r]->next))
 {
  if(temp->flag==1)
  {
   strcpy(temp->movie_name,"NIL");
   temp->flag=0;
   strcpy(temp->name,"NIL");
   temp->mno=00;
   head[r]->cnt=head[r]->cnt-1;
  }
 }
 return 1;
}



void Cinemax::create()
{
    node *f1;
    cout<<"\n\n!!! Welcome To Cinemax Theater !!!\n";
    for(i=1;i<=10;i++)
    {
        p = new node;
        p->next=NULL;
        p->prev=NULL;
        p->flag=0;
        strcpy(p->movie_name,"NIL");
        strcpy(p->name,"NIL");
        p->mno=0;

        if(head[i]->next==NULL)
        {
         head[i]->next= p;
         p->prev=p;
         p->next=p;
        }


            temp=head[i]->next;
            f1=temp;
            for(j=1;j<=6;j++)
            {
                t1=new node;
                t1->flag=0;
                t1->mno=0;
                strcpy(t1->movie_name,"NIL");
                strcpy(t1->name,"NIL");

                t1->next=head[i]->next;
                temp->next=t1;
                t1->prev=temp;
                f1->prev=t1;
                temp=t1;
            }

     }

}


void Cinemax::show()
{
    cout<<"Rows Status are as follows...\n";
    cout<<"\nHead Node\tCol1\t\tCol2\t\tCol3\t\tCol4\t\tCol5\t\tCol6\t\tCol7";
    for(i=1;i<=10;i++)
    {
        cout<<"\nRow : "<<i;
        temp=head[i]->next;
         cout<<"[ "<<head[i]->cnt<<" ]--->";
        while(temp->next!=head[i]->next)
        {
         cout<<"[ "<<temp->flag<<"|"<<temp->movie_name<<"|"<<temp->name<<"]->";
         temp=temp->next;
        }
        if(temp->next==head[i]->next)
        {
         cout<<"[ "<<temp->flag<<"|"<<temp->movie_name<<"|"<<temp->name<<"]->";
        }
        cout<<"\n\n";
    }
}

int main()
{
    Cinemax c1;
        int row,n,am,ch,amnt=150;
     char mname[20];
    c1.create();
    do
     {
    cout<< "\n!!!Cinemax Theator!!!" << endl;

    cout<<"\n1.Book_my_Show\n2.Display Seat status\n3.Cancel_my_show";

    cout<<"\nEnter u R Choice: ";
    cin>>ch;
    switch(ch)
    {
     case 1:cout<<"\nWelcome To Cinemax Theater For Book your Show...\n";
        cout<<"\n Movies are as follows...\n";
        cout<<"\n1.A\n2.B\n3.C\n4.D\n5.E\n6.F\n7.G.\n";
        cout<<"\nEnter u r movie name to book the show:(Note: space is not allowed in movie name)::  ";
                cin>>mname;
        c1.show();
        cout<<"\nEnter the row number to book u r ticket: ";
            cin>>row;
        cout<<"\nHow many Tickets u want to Book: ";
        cin>>n;
        am=c1.book_my_show(row,n,mname);
        if(am!=0)
        {
         c1.show();
         cout<<"\n\n Please pay the cash: u r total amount is: "<<amnt*n;;
         cout<<"\n\nYour booking is confirmed please see the status: ..\n\n";
                }
        else
        {
         cout<<"\n\nTry for another row...\n";
         }
                break;
         case 2:cout<<"\n The Booking status of the Cinemax Theator are as follows...\n\n";
        c1.show();
                break;
         case 3:cout<<"\nWelcome To Cinemax Theator For Cancel your Show...";
        cout<<"\nEnter u r movie name to cancel the show:(Note: space is not allowed in movie name)::  ";
                cin>>mname;
        c1.show();
        cout<<"\nEnter the row number to cancel u r ticket: ";
            cin>>row;
        cout<<"\nHow many Tickets u want to Cancel: ";
        cin>>n;
        am=c1.cancel_my_show(row,n,mname);
        if(am!=0)
        {
         c1.show();
         cout<<"\n\n Your total refund amount is: "<<((amnt*n)-50);;
         cout<<"\n\nYour booking is cancel please see the status: ..\n\n";
                }
        else
        {
         cout<<"\n\nTry for another row...\n";
         }
                break;
         default:
        	 cout<<"Incorrect Choice Entered"<<endl;
    }
     }while(ch!=4);


    return 0;
}
