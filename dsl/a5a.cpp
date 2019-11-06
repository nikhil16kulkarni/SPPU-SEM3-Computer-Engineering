#include <iostream>

#include<vector>

using namespace std;

struct node

{

	int data;

	node* next;

	node* prev;
};


node* Create(int x)

{

	node* temp=new node;

	temp->data=x;

	temp->next=NULL;

	temp->prev=NULL;

	return temp;

}

void Insert(node** head,int x)

{

	node *temp=Create(x);

	if(*head==NULL)

	{

		*head=temp;

	}

	else {

		(*head)->prev=temp;

		temp->next=*head;

		*head=temp;

	}

}



void print(node* head)

{

	node* temp=head;

	cout<<"\ndata: ";

	while(temp!=NULL)

	{

		cout<<temp->data<<" ";

		temp=temp->next;

	}

	cout<<endl;

}

int sum(int a,int b,int c)

{

	return a^b^c;

}

int carry(int a,int b,int c)

{

	int x=a*b;

	int y=b*c;

	int z=c*a;

	int s=sum(x,y,z);

	return s;

}

node* get_sum(node** head1,node** head2,node** result)

{

	* result=NULL;

	node* temp1=*head1;

	node* temp2=*head2;

	int c=0;

	while(temp1!=NULL && temp2!=NULL)

	{

		int s=sum(temp1->data,temp2->data,c);

		c=carry(temp1->data,temp2->data,c);

		Insert(result,s);

		temp1=temp1->next;

		temp2=temp2->next;

	}

	Insert(result,c);

	return *result;

}

int flip(int x)

{

	if(x == 1)

	return 0;

	return 1;

}

node* first_comp(node** head,node** result)

{

	node* temp=*head;

	*result=NULL;

	while(temp!=NULL)

	{

		Insert(result,flip(temp->data));

		temp=temp->next;

	}

	return *result;

}

int main() {

	int ch,n,m;

	node* pnode,*qnode,*rnode,*res,*flip,*twos;

	node* p;

	p=NULL;

	pnode=qnode=rnode=flip=res=twos=NULL;

	cout<<"Enter size of first list : "<<endl;

	cin>>n;

	do{

		cout<<"\tWelcome\n";

		cout<<" 1.Create List 1\n";

		cout<<" 2.Create List 2\n";

		cout<<" 3.1's compliment\n";

		cout<<" 4.2's compliment\n";

		cout<<" 5.Binary Addition\n";

		cout<<" 6.Exit\n";

		cout<<"Enter your choice : \n";

		cin>>ch;

		switch (ch)

		{

			case 1:

			cout<<"Enter elements in first node."<<endl;

			for(int i=0;i<n;++i) {

				cin>>m;

				Insert(&pnode, m);

				//print(pnode);

			}

			cout<<"printing first list : ";

			print(pnode);

			break;

			case 2:

			cout<<"Enter elements in second node."<<endl;

			for(int i=0;i<n;++i) {	

				cin>>m;

				Insert(&qnode, m);

			}

			break;

			case 3:

			flip=first_comp(&pnode,&flip);

			print(flip);

			break;

			case 4:

			for(int i=0;i<n;++i){

				if(i<n-1)

				Insert(&p,0);

				else

				Insert(&p,1);

			}

			twos=get_sum(&flip,&p,&twos);

			print(twos);

			break;

			case 5:

			res=get_sum(&pnode,&qnode,&res);

			print(res);

			break;

		}

	}while (ch>=1 && ch<=6);

	return 0;

}

