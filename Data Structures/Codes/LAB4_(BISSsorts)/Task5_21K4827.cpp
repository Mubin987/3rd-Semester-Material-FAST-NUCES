#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter number of crates:";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
			cout<<"Enter array [" <<i<<"] value: ";
			cin>>*(arr + i);
	}
	for(int gap=n/2;gap>=1;gap/2){
		for(int j=gap;j<n;j++){
			for(int i=j-gap;i>=0;i-gap){
				if(arr[i+gap]>arr[i]){
					break;
				}
				else{
					swap(arr[i+gap],arr[i]);
				}
			}
		}
	}
	for(int k=0;k<n;k++){
			cout<<"Sorted array [" <<k<<"] value: "<<*(arr + k)<<endl;
	}
}
//Shell Sort
