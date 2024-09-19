#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter array length:";
	cin>>n;
	int arr[n];
	int i,j,start,end;
	for(i=0;i<n;i++){
			cout<<"Enter array [" <<i<<"] value: ";
			cin>>*(arr + i);
	}
	for(i=0;i<n;i++){
			cout<<*(arr + i)<<", ";
	}
	cout<<endl;
	int min,max;
	for(i=0;i<n;i++){
		max=arr[i];
		if(max<arr[i-1]){
			for(int k=0;k<i;k++){
				if(max>arr[k]&&max<arr[k+1]){
					start=k+1;
					break;
				}
			}break;
		}
	}
	for(j=n-2;j>=0;j--){
		min=arr[j];
		if(min>arr[j+1]){
			for(int k=j+1;k<n;k++){
				if(min>arr[k]&&min<arr[k+1]){
					end=k+1;
					break;
				}
			}break;
		}
	}
	
	cout<<"Unsorted subarray lies between "<<start<<" and "<<end<<endl;
	
	int temp,tmp;
	for(i=start+1;i<=end;i++){
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
		for(i=start;i<=end;i++){
			cout<<*(arr + i)<<", ";
	}
		cout<<endl;
		i=tmp;

	}
	for(i=0;i<n;i++){
			cout<<"Sorted array [" <<i<<"] value: "<<*(arr + i)<<endl;
	}
}
