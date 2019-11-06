//============================================================================
// Name        : Assignment3(b).cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <math.h>
using namespace std;

struct Term
{
	int expo;
	int coeff;
};


class Polynomial
{

	int n;
	Term *poly;

public:
	Polynomial()
	{
		int n=0;
		poly= new Term[n];
	}
	void getpoly()
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>poly[i].coeff>>poly[i].expo;
		}
	}

	void printpoly()
	{
		for(int i=0;i<n;i++)
		{
			if(poly[i].expo==0)
			cout<<"+"<<poly[i].coeff;
			else if(poly[i].coeff==0)
			continue;
			else
			cout<<"+"<<poly[i].coeff<<"X^"<<poly[i].expo;
		}
	}
	Polynomial add(Polynomial p1)
	{
		Polynomial temp;
		int i=0,j=0,k=0;
		temp.n=n+p1.n;
		while(i<n && j<p1.n)
		{
			if(poly[i].expo > p1.poly[j].expo)
			{
				temp.poly[k].expo=poly[i].expo;
				temp.poly[k].coeff=poly[i].coeff;
				i++;
				k++;
			}
			else if(poly[i].expo < p1.poly[j].expo)
			{
				temp.poly[k].expo=p1.poly[j].expo;
				temp.poly[k].coeff=p1.poly[j].coeff;
				j++;
				k++;
			}
			else if(poly[i].expo==p1.poly[j].expo)
			{
				temp.poly[k].expo=poly[i].expo;
				temp.poly[k].coeff=poly[i].coeff+p1.poly[j].coeff;
				i++;
				j++;
				k++;
			}
		}
		if(i<n)
		{
			for(int i1=i;i1<n;i1++)
			{
				temp.poly[k].expo=poly[i1].expo;
				temp.poly[k].coeff=poly[i1].coeff;
				k++;

			}
		}
		if(j<p1.n)
		{
			for(int i1=j;i1<p1.n;i1++)
			{
				temp.poly[k].expo=p1.poly[i1].expo;
				temp.poly[k].coeff=p1.poly[i1].coeff;
				k++;
			}
		}
		temp.n=k;
		return temp;
	}

	Polynomial multiply(Polynomial p1)
	{
		Polynomial temp;
		temp.n=n*p1.n+1;
		int k=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<p1.n;j++)
			{
				temp.poly[k].coeff=poly[i].coeff*p1.poly[j].coeff;
				temp.poly[k].expo=poly[i].expo+p1.poly[j].expo;
				k++;
			}
		}
		temp.n=k;
		for(int i=0;i<k;i++)
		{
			for(int j=i+1;j<k;j++)
			{
				if(temp.poly[i].expo==temp.poly[j].expo)
				{
					temp.poly[i].coeff+=temp.poly[j].coeff;
					temp.poly[j].coeff=0;
					temp.poly[j].expo=0;
				}
			}
		}
		return temp;
	}

	void eval()
	{
		int k,sum=0;
		cout<<"ENTER THE INT TO EVALUATE POLYNOMIAL\n";
		cin>>k;
		for(int i=0;i<n;i++)
		{
			sum+=poly[i].coeff * pow(k,poly[i].expo);
		}
		cout<<sum;
	}
};

int main() {
	Polynomial p,p1,p2,p3;
	p.getpoly();
	p.printpoly();
	p1.getpoly();
	p1.printpoly();
	p2=p.add(p1);
	p2.printpoly();
	p3=p.multiply(p1);
	p3.printpoly();
	p.eval();
	return 0;
}
