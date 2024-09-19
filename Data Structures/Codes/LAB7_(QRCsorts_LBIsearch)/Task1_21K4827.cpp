#include<iostream>
using namespace std;
int Quick_sort_partion(int arr[],int n,int l,int h){
	int pivot,i,temp;
	i=l;
	pivot=h;	
	for(int j=l;j<=h;j++){
		if(arr[pivot]>arr[j]){
			temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
			i++;
		}
		if(j==h){
			temp=arr[i];
			arr[i]=arr[pivot];
			arr[pivot]=temp;
		}
	}
	for(int k=0;k<n;k++){
		cout<<arr[k]<<",";
	}
	cout<<endl;
	return i;
	
}
void Quick_sort(int arr[],int n,int l,int h){
	int loc;
	if(l<h){
		loc=Quick_sort_partion(arr,n,l,h);
		Quick_sort(arr,n,loc+1,h);
		Quick_sort(arr,n,l,loc-1);
	}
}
int main(){
	int n, array[]={19,4,15,12,16,18,7,11,13};
	n=sizeof(array)/sizeof(int);
	Quick_sort(array,n,0,n-1);
}


