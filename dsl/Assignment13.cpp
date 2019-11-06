//============================================================================
// Name        : Assignment13.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*#include <bits/stdc++.h>
using namespace std;

void swap(int s1,int s2)
{
    int t = s1;
    s1=s2;
    s2=t;
}

int partition(float ar[],int start,int end)
{
    float a = ar[end];
    int b =(start-1);

    for(int j=start;j<=end-1;j++)
    {
        if (ar[j]<=a)
        {
            b++;
            swap(ar[b],ar[j]);
        }
    }
    swap(ar[b+1],ar[end]);
    return (b+1);
}

void quicksort(float ar[],int start,int end)
{
    if (start<end)
    {

        int pi= partition(ar,start,end);
        quicksort(ar,start,pi-1);
        quicksort(ar,pi+1,end);
    }
}

int main() {
	cout<<"Enter total no. of students"<<endl;
	int n;
	cin>>n;
	cout<<"Enter Percentage of each student"<<endl;
	float p[n];
	for(int i=0;i<n;i++)	cin>>p[i];
	quicksort(p,0,n-1);
	cout<<"Percentage after sorting : "<<endl;
	for(int i=0;i<n;i++)	cout<<p[i]<<endl;
	cout<<"Top 5 scorers are : "<<endl;
	for(int i=n-1;i>=n-5;i--)	cout<<p[i]<<endl;
}*/

//============================================================================
// Name        : Assignment3(b).cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <bits/stdc++.h>
using namespace std;
class Term{
	float coefficient;
	int exponent;
	friend class Polynomial;
};
class Polynomial{
	int n;
	Term p[100];
	public:
	Polynomial(){ n=0; }
	void menu();
	void read();
	void display();
	void arrange();
	float eval(float);
	Polynomial add(Polynomial);
	Polynomial multiply(Polynomial);
};
void Polynomial::menu(){
	cout<<"------------------POLYNOMIAL--------------------"<<endl;
	cout<<"\tPress 1 : Enter Expression"<<endl;
	cout<<"\tPress 2 : Display Expression"<<endl;
	cout<<"\tPress 3 : Add Another Polynomial"<<endl;
	cout<<"\tPress 4 : Multiply Another Polynomial"<<endl;
	cout<<"\tPress 5 : Evaluate Expression for x"<<endl;
	cout<<"\tPress 0 to exit"<<endl;
}
void Polynomial::read(){
	int i;
	cout<<"Enter the no. of terms: ";
	cin>>n;
	for(i=0;i<n;i++){
		cout<<"Enter Term "<<i+1<<": ";
		cin>>p[i].coefficient>>p[i].exponent;
	}
	arrange();
}
void Polynomial::arrange(){
	Term temp;
	int i,j,count=0,f=0;
	//sorting by exponents;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].exponent<p[j].exponent)
			{
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
			}
		}
	}
	//adding duplicates;
	for(i=0;i<n;i++)
	{
		if(p[i].coefficient)
		for(j=i+1;j<n;j++)
		{
			if(p[i].exponent==p[j].exponent)
			{
				p[i].coefficient+=p[j].coefficient;
				p[j].coefficient=0;
				count++;
			}
		}
	}
	//removing blanks;
	for(i=0;i<n;i++){
		if(!p[i].coefficient){
			for(j=i;j<n;j++){
				p[j]=p[j+1];
			}
		}
	}
	n-=count;
}
void Polynomial::display(){
	int i;
	for(i=0;i<n-1;i++)
			cout<<p[i].coefficient<<"x^"<<p[i].exponent<<" + ";
	if(p[i].exponent)
		cout<<p[i].coefficient<<"x^"<<p[i].exponent;
	else
		cout<<p[i].coefficient;
}
Polynomial Polynomial::add(Polynomial exp2){
	Polynomial e;
	int terms=0,i,j;
	float temp;
	for(i=0,j=0;i<n&&j<exp2.n;){
		if(p[i].exponent>exp2.p[j].exponent){
			e.p[terms].exponent=p[i].exponent;
			e.p[terms].coefficient=p[i].coefficient;
			terms++;
			i++;
		}
		else if(p[i].exponent<exp2.p[j].exponent){
			e.p[terms].exponent=exp2.p[j].exponent;
			e.p[terms].coefficient=exp2.p[j].coefficient;
			terms++;
			j++;
		}
		else{
			temp=p[i].coefficient+exp2.p[j].coefficient;
			if(temp){
				e.p[terms].exponent=p[i].exponent;
				e.p[terms].coefficient=temp;
				terms++;
				i++;
				j++;
			}
			else{
				i++;
				j++;
			}
		}
	}
	for(;i<n;i++){
		e.p[terms].exponent=p[i].exponent;
		e.p[terms].coefficient=p[i].coefficient;
		terms++;
	}
	for(;j<exp2.n;j++){
		e.p[terms].exponent=exp2.p[j].exponent;
		e.p[terms].coefficient=exp2.p[j].coefficient;
		terms++;
	}
	e.n=terms;
	e.arrange();
	return e;
}
float Polynomial::eval(float x){
	int i;
	float val=0;
	for(i=0;i<n;i++){
		val+=p[i].coefficient*pow(x,p[i].exponent);
	}
	return val;
}
Polynomial Polynomial::multiply(Polynomial exp2){
	int i,j,e;
	float c;
	Polynomial temp,partial,product;
	product.n=1;
	product.p[0].coefficient=0;
	product.p[0].exponent=0;
	for(i=0;i<exp2.n;i++){
		c=exp2.p[i].coefficient;
		e=exp2.p[i].exponent;
		for(j=0;j<n;j++){
			partial.p[j].coefficient=p[j].coefficient*c;
			partial.p[j].exponent=p[j].exponent+e;

		}
		partial.n=j;
		partial.arrange();
		product=product.add(partial);
	}
	product.arrange();
	if(product.p[product.n-1].coefficient==0){
		product.n--;
	}
	return product;
}
int main()
{
	Polynomial exp1,exp2,exp3;
	int ch=1;
	float x;
	exp1.menu();
	cout<<"Enter The Expression:"<<endl;
	while(ch!=0){
		switch(ch){
			case 1:
				exp1.read();
				break;
			case 2:
				exp1.display();
				break;
			case 3:
				cout<<"Enter Second Expression:"<<endl;
				exp2.read();
				exp3=exp1.add(exp2);
				exp3.display();
				break;
			case 4:
				cout<<"Enter Second Expression:"<<endl;
				exp2.read();
				exp3=exp1.multiply(exp2);
				exp3.display();
				break;
			case 5:
				cout<<"Enter The Value of x: ";
				cin>>x;
				cout<<"p("<<x<<") = "<<exp1.eval(x);
				break;
			default:
				cout<<"Invalid choice "<<ch;
		}
		cout<<endl<<"_______________________________________________";
		cout<<endl<<"Enter Choice from Menu [Press 0 to exit]: ";
		cin>>ch;
	}
	return 0;
}
