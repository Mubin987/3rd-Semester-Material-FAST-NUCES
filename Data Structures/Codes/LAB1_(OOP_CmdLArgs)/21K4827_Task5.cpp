#include<iostream>
using namespace std;
void minmax(int* , int *,int *,int);
int main(){
	int num;
	cout<<"Enter array size:";
	cin>>num;
	
	int min=1000;
	int max;
	
	int arr[num];
	for(int i=0;i<num;i++){
		cout<<"Enter value ["<<i<<"]:";
		cin>>arr[i];
	}
	
	minmax(arr,&min,&max,num);
	
	cout<<"Ther largest value is "<<max<<endl;
	
	cout<<"The smallest value is "<<min<<endl;
}
void minmax(int ar[], int *p,int *q,int n){
	for(int i=0;i<n;i++){
		if(ar[i]<*p){
			*p=ar[i];	
		}
		if(ar[i]>*q){
			*q=ar[i];	
		}
	}
}
