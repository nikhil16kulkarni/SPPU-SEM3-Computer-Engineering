//============================================================================
// Name        : polynomial.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : do not copy
// Description : Hello World in C++, Ansi-style
/* Problem Statement - Write a C++ program to realize polynomial equation and perform operations. Write function    
                       To input &output polynomials represented as bmxem+ bm-1xem-1 +….. +b0xe0.  Your functions should overload the << and >> operators. 
                       Evaluates a polynomial at given value of x 
                       Add two polynomials. 
                       Multiplies two polynomials.*/
//============================================================================

#include<bits/stdc++.h>
#include<math.h>
using namespace std;
const int N = 100;
int len;

struct node{
	int power = 0;
	int coeff = 0;
};

class polynomial{

public:
	struct node poly[N];
	int size ;
	polynomial();
	polynomial(int);
	void rearrange();
	polynomial(polynomial a , polynomial b);
	int F(int );

	polynomial operator + (polynomial& add);
	polynomial operator * (polynomial& mul);

	friend istream &operator >> (istream & take,polynomial& m){
			cout << "Enter the coefficients and their powers : \n";

			for(int x=0;x<len;x++)
				take>> m.poly[x].coeff >> m.poly[x].power;

		    return take;

		}

	friend ostream &operator << (ostream &give, polynomial& m){

		cout << "\nThe Polynomial is : \t ";

			for(int x=0;x<m.size;x++)
				give << m.poly[x].coeff << "X^" << m.poly[x].power <<( (x!= m.size - 1) == true ?  " + " : " ");

				give << "\n\n";
			  return give;
			}

};

int polynomial::F(int X){
	int len = size;
	int ans = 0;

	for(int x= 0;x<len;x++)
		ans += ( poly[x].coeff *( pow(X, poly[x].power) ));

	return ans;

}

void polynomial:: rearrange(){

	for(int x=0;x<size -1;x++)
		for(int y=x+1 ;y <size ;y++)
			if(poly[x].power < poly[y].power)
				swap(poly[x] , poly[y]);

}

polynomial polynomial ::operator +(polynomial& add){
	//int mx = max(size , add.size);
	int fi = 0 , se = 0;

	polynomial addition;	//addition.size = mx;
	int ind = 0;

	while(fi < size or se < add.size){
		if(poly[fi].power == add.poly[se].power ){
			addition.poly[ind].coeff = poly[fi].coeff + add.poly[se].coeff ;
			addition.poly[ind].power = poly[fi].power;
			ind++ , fi++ , se++;
		}
		else if(poly[fi].power > add.poly[se].power ){
			addition.poly[ind].coeff = poly[fi].coeff ;
			addition.poly[ind].power = poly[fi].power ;
			fi++ , ind++;
		}
		else{
			addition.poly[ind].coeff = add.poly[se].coeff ;
			addition.poly[ind].power = add.poly[se].power;
			se++ , ind ++;
		}
	}

	if(fi <= size -1){
		while(fi < size){
			addition.poly[ind].coeff = poly[fi].coeff;
			addition.poly[ind].power = poly[fi].power;
			fi++ , ind++;
		}
	}
	if(se <= add.size -1){
		while(fi < add.size){
					addition.poly[ind].coeff = poly[se].coeff;
					addition.poly[ind].power = poly[se].power;
					se++ , ind++;
				}
	}

	addition.size = ind;

	cout << "Size of addition polynomial is : " << addition.size << endl;

	return addition;

}

polynomial polynomial ::operator *(polynomial& mul){
	int fisize = size , sesize = mul.size;

	polynomial ans;

	int mxpow = -1;

	int answer[100] = {0};
	// index is power and value at index is coeff;

	for(int x=0;x<size;x++){
		for(int y=0;y<sesize;y++){
			int power = poly[x].power + mul.poly[y].power;
			int coefff = poly[x].coeff * mul.poly[y].coeff;
			mxpow = max(mxpow , power);
			answer[power] += coefff;
		}
	}




	int length = 0;

	for(int x=0 , i = 0;x<=mxpow ; x++){
		if(answer[x] != 0){
			ans.poly[i].coeff = answer[x] , ans.poly[i].power = x;
			i++; length++;
		}
	}

	ans.size = length;

	return ans;

}

polynomial:: polynomial(int len){
	size = len;
	for(int x=0;x<N ;x++)
		poly[x].coeff = 0 , poly[x].power = 0;
}

polynomial :: polynomial(){

	for(int x=0;x<N;x++)
		poly[x].coeff = 0 , poly[x].power = 0;


}

int main() {

	cout << "Enter length of polynomial : ";	cin>> len;

	polynomial p;	p.size = len;
	cin >> p;	p.rearrange();
	cout << p;
	cout << "Enter length of polynomial : ";	cin>> len;
	polynomial q;	q.size = len;
	cin >> q;	q.rearrange();
	cout << q;

	cout << "Length of p = " << p.size << endl;
	cout << "Length of q = " << q.size << endl;

	polynomial add = p + q;
	add.rearrange();
	cout << add;

	cout << "Evaluate value of 'a' at : " ;	int X;	cin>> X;
	cout << " = " << p.F(X) << endl;

	cout << "Evaluate value of 'b' at : " ;			cin>> X;
	cout << " = " << q.F(X) << endl;

	cout << "Multiplication of first two polynomials is : " << endl;

	polynomial tt = p * q;	tt.rearrange();
	cout << tt << endl;

	return 0;
}









