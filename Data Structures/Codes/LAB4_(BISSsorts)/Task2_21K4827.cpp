#include<iostream>
using namespace std;
int main(){
	typedef struct{
		int day;
		int month;
		int year;
	}date;
	
	int arr[10];
	int i,j;
	for(i=0;i<10;i++){
			cout<<"Enter array [" <<i<<"] value: ";
			cin>>*(arr + i);
		
	}
	int temp;
	for(i=0;i<10;i++){
		int min=1000;
		for(j=i;j<10;j++){
			if(arr[j]<min){
				min=arr[j];
			}
		}
		arr[i]=min;
	}
	for(i=0;i<10;i++){
			cout<<"Sorted array [" <<i<<"] value: "<<*(arr + i)<<endl;
	}
}

