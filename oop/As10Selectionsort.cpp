#include <iostream>
using namespace std;
template <class T>
void selection_sort(T arr_,int size){
	for(int i=0;i<size-1;i++){
		for(int j=i+1;j<size;j++){
			if(arr_[j]<arr_[i]){
				swap(arr_[i],arr_[j]);
			}
		}
	}
	for(int i=0;i<size;i++){
		cout<<arr_[i]<<" ";
	}
}
int main() {
	int choice,n;
	cout<<"1. Integer Array";
	cout<<"\n2. Float Array";
	cout<<"\n Enter your choice of the array:";
	cin>>choice;
	switch(choice){
	case 1:
		cout<<"\nEnter the number of the elements in your integer array: ";
		cin>>n;
		int arr[n];
		cout<<"\nNow enter your numbers of the integer array: ";
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<"\nThe elements of your array after selection sort is: ";
				selection_sort(arr,n);
		break;
	case 2:
		cout<<"\nEnter the number of the elements in your float array: ";
		cin>>n;
		float arr1[n];
		cout<<"\nNow enter your numbers of the float array: ";
		for(int i=0;i<n;i++){
			cin>>arr1[i];
		}
		cout<<"\nThe elements of your array after selection sort is: ";
				selection_sort(arr1,n);
		break;
	default:
		cout<<"\n You have entered a wrong choice:{";
		break;
	}
	return 0;
}
