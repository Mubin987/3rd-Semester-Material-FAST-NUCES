#include<iostream>
using namespace std;
int main(){
	int arr[9];
	int i,j;
	for(i=0;i<9;i++){
			cout<<"Enter array [" <<i<<"] value: ";
			cin>>*(arr + i);
		
	}
	int temp;
	for(i=0;i<9;i++){
		for(j=0;j<9-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(i=0;i<9;i++){
			cout<<"Sorted array [" <<i<<"] value: "<<*(arr + i)<<endl;
	}
}

