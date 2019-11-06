#include<bits/stdc++.h>
using namespace std;
class matrix{
    public:
    int n,i,j,flag=0,sum,mi,ma,l,k;
    
    int m1[10][10],m2[10][10],m3[10][10],m4[10][10],m5[10][10];
    
    void i1(){
        cout<<"Enter order of Matrix"<<endl;
        cin>>n;
    }
    void input(){
        cout<<"Enter 1st Matrix"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<"Enter Element : "<<"A["<<i+1<<"]["<<j+1<<"]";
                cin>>m1[i][j];
            }
        }

    }
    
    int output(){
        cout<<"Entered Matrix is"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<m1[i][j]<<"   ";
            }
            cout<<endl;
        }
        return 0;
    }
    
    void input2(){
        cout<<"Enter 2nd Matrix";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<"Enter Element : "<<"B["<<i+1<<"]["<<j+1<<"]";
                cin>>m2[i][j];
            }
        }
      
    }
    
    void triangular(){
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(m1[i][j]!=0) flag=1;
            }
        }
        if(flag==1) cout<<"Matrix is not Upper Triangular"<<endl;
        else cout<<"Matrix is Triangular"<<endl;
    }
    
    int add(){
        cout<<"Addition of two Matrices is"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m3[i][j]=m1[i][j]+m2[i][j];
                cout<<m3[i][j]<<"   ";
            }
            cout<<endl;
        }
        return 0;
    }
    
    int sub(){
        cout<<"Subtraction of two Matrices is"<<endl;;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m4[i][j]=m1[i][j]-m2[i][j];
                cout<<m4[i][j]<<"   ";
            }
            cout<<endl;
        }
        return 0;
    }
    
    int mul(){
        cout<<"Multiplication of two matrices is"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m5[i][j]=0;
                for(int k=0;k<n;k++){
                    m5[i][j]+=m1[i][k] * m2[k][j];
                }
                cout<<m5[i][j]<<"   ";
            }
            cout<<endl;
        }
        return 0;
    }
    
    int dia(){
        cout<<"Summation of diagonal elements is : "<<endl;
        sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)  sum+=m1[i][j];  
            }
        }
        cout<<sum<<endl;
        return 0;
    }
    
    int trans(){
        cout<<"Transpose of Matrix is :"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<m1[j][i]<<"   ";
            }
            cout<<endl;
        }
        return 0;
    }
    
    int sp(){
        for(int i=0;i<n;i++){
            mi=m1[i][0];
            for(int j=0;j<n;j++){
                mi=min(mi,m1[i][j]);
                if(mi!=m1[i][0])
            	     	l=j;
            	   	else
            	   		l=0;
            }
            
            ma=m1[0][i];
            for(int k=1;k<n;k++){
                ma=max(ma,m1[k][l]);
            }
            if(mi==ma)  cout<<"Saddle Point Found in "<<i+1<<"th Row : "<<ma<<endl;
            else    cout<<"Saddle Point not Found in"<<i+1<<"th Row"<<endl;
        }
        return 0;
    }
};
int main(){
    matrix m;
    int z;
    m.i1();
    m.input();
    m.output();
    char yn;
    do{
    cout<<"\n1.Check whether it is upper Triangular or not\n2.Summation of Diagonal Elements\n3.Transpose of Matrix\n4.Addition of Two MAtrices\n5.Subtraction of Two Matrices\n6.Multiplication of Two Matrices\n7.Check for Saddle Point\n";
    cout<<"Enter Choice"<<endl;
    cin>>z;
    switch(z){
        case 1 : m.triangular();    break;
        case 2 : m.dia();  break;
        case 3 : m.trans(); break;
        case 4 : m.input2();
                    m.add();
                    break;
        case 5 : m.input2();
                    m.sub();
                    break;
        case 6 : m.input2();
                    m.mul();
                    break;
        case 7 : m.sp();    break;
        default : cout<<"Incorrect Choice Entered"<<endl;   break;
    }
    cout<<"Do you want to continue?(y/n)"<<endl;
    cin>>yn;
    }while(yn=='y');
    
}




