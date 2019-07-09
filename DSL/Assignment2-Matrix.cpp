//============================================================================
// Name        : Assignment2(Matrix).cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style

// Problem statement : Write C++ program for storing matrix. Write functions for
//                     Check whether given matrix is upper triangular or not
//                     Compute summation of diagonal elements 
//                     Compute transpose of matrix 
//                     Add, subtract and multiply two matrices  
//                     Check saddle point is present or not.

//============================================================================

#include<iostream>
using namespace std;
class matrix
{
private:
  int mat[50][50];
  int row,col,i,j;
public:
  void acceptMatrix();
  void displayMatrix();
  matrix()
  {
    for(i=0;i<50;i++)
      for(j=0;j<50;j++)
        mat[i][j]=0;
  }
  matrix addMatrix(matrix mat2);
  matrix subMatrix(matrix mat2);
  matrix mulMatrix(matrix mat2);
};
void matrix::acceptMatrix()
{
  cout<<"\nEnter Number of Rows and Columns:";
  cin>>row>>col;
  cout<<"\nEnter Matrix Elements:";
  for(i=0;i<row;i++)
    for(j=0;j<col;j++)
      cin>>mat[i][j];
}
void matrix::displayMatrix()
{
  cout<<"\nMatrix:";
  for(i=0;i<row;i++)
  {
    cout<<"\n\n";
    for(j=0;j<col;j++)
      cout<<mat[i][j]<<" ";
  }
}
matrix matrix::addMatrix(matrix m2)
{
  matrix temp;
  temp.row=row;
  temp.col=col;
  for(i=0;i<temp.row;i++)
  {
    for(j=0;j<temp.col;j++)
    {
      temp.mat[i][j]=mat[i][j]+m2.mat[i][j];
    }
  }
  return temp;
}
matrix matrix::mulMatrix(matrix m2)
{
  matrix temp;
  temp.row=row;
  temp.col=m2.col;
  for(i=0;i<row;i++)
  {
    for(j=0;j<m2.col;j++)
    {
      temp.mat[i][j]=0;
      for(int k=0;k<col;k++)
      {
        temp.mat[i][j]+=mat[i][k]*m2.mat[k][j];
      }
    }
  }
  return temp;
}
matrix matrix::subMatrix(matrix m2)
{
  matrix temp;
  temp.row=row;
  temp.col=col;
  for(i=0;i<row;i++)
  {
    for(j=0;j<col;j++)
    {
      temp.mat[i][j]=mat[i][j]-m2.mat[i][j];
    }
  }
  return temp;
}
int main()
{
  int choice;
  matrix A,B,C;
  cout<<"\nEnter 1st matrix:\n";
  A.acceptMatrix();
  cout<<"\nEnter 2nd matrix: \n";
  B.acceptMatrix();
  do
  {
    cout<<"\nMENU\n\n1.Addition\n\n2.Subtraction\n\n3.Multiplication\n\n4.Exit\n\n";
    cout<<"Enter choice:";
    cin>>choice;
    switch(choice)
    {
    case 1: C=A.addMatrix(B);
      cout<<"\nAddition is:\n";
      C.displayMatrix();
      break;
    case 2: C=A.subMatrix(B);
      cout<<"\nSubtraction is:\n";
      C.displayMatrix();
      break;                 
    case 3: C=A.mulMatrix(B);
      cout<<"\nMuliplication is:\n";
      C.displayMatrix();
      break;
    case 4: break;
    default:cout<<"You have entred wrong choice";
    }
  }
  while(choice!=4);;
  return 0;
}   
