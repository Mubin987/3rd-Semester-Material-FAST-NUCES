#include<iostream>
using namespace std;
int main(){
	int *arr = new int[10];
	int i,j;
	char order;
	for(i=0;i<10;i++){
		cout<<"Enter Element " <<i <<":" ;
		cin>>*(arr + i);
	}
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){ 
			if(*(arr + j+1)<*(arr + j)){
				int temp;
				temp=*(arr + j);
				*(arr + j)=*(arr + j+1);
				*(arr + j+1)=temp;
			}
		}
	}
	cout<<"Ascending: ";
	for(i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\nDescending: ";
	for(i=9;i>=0;i--){
		cout<<arr[i]<<" ";
	}
}