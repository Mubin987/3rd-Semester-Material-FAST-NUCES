#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter array length:";
	cin>>n;
	int arr[n];
	int i,j;
	for(i=0;i<n;i++){
			cout<<"Enter array [" <<i<<"] value: ";
			cin>>*(arr + i);
	}
	for(i=0;i<n;i++){
			cout<<*(arr + i)<<", ";
	}
	cout<<endl;
	int temp,tmp;
	for(i=1;i<n;i++){
		temp=arr[i];
		for(j=i-1;j>=0;j--){
			if(temp<arr[j]){
				arr[i]=arr[j];
				arr[j]=temp;
			}
			if(arr[j]<arr[j-1])
				swap(arr[j],arr[j-1]);
		}
		tmp=i;
		for(i=0;i<n;i++){
			cout<<*(arr + i)<<", ";
	}
		cout<<endl;
		i=tmp;

	}
	for(i=0;i<n;i++){
			cout<<"Sorted array [" <<i<<"] value: "<<*(arr + i)<<endl;
	}
}

