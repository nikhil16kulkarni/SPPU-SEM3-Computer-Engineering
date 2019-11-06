//============================================================================
// Name        : Assignment6(b).cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int coef , exp;
    struct Node* next;
};


struct Node* create( struct Node* p ){

    int i , c , x , t;
    cout<<"\nNumber of terms: ";
    cin>>t;
    for( i = 0 ; i < t ; i++ ){
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        cout<<"Enter Coefficient & Exponent: ";
        cin>>c>>x;
        temp->coef = c;
        temp->exp = x;
        if( p == NULL ){
            p = temp;
            temp->next = p;
        }else{
            struct Node* temp1 = p;
            while( temp1->next != p ) temp1 = temp1->next;
            temp1->next = temp;
            temp->next = p;
        }
    }
    return p;
}

void display( struct Node* p ){

    struct Node* temp = p;
    cout<<"\nPOLYNOMIAL: ";

    do{
        cout<<p->coef<<"x^"<<p->exp;
        temp = temp->next;
        if( temp != p ){
            cout<<" + ";
        }
    }while(temp!=p);
}

int main(){

    int val , choice;
    struct Node* A = NULL;
    struct Node* B = NULL;

    A = create(A);
    B = create(B);
    display(A);
    display(B);

    do{
        cout<<"\n\n-----POLYNOMIAL OPERATIONS-----\n1.Addition\n2.Evaluate\n3.Exit\n--->";
        cin>>choice;

        switch( choice ){
            case 1://Adding
                    break;
            case 2://Evaluating
                    break;
        }

    }while( choice != 3 );


    return 0;
}


