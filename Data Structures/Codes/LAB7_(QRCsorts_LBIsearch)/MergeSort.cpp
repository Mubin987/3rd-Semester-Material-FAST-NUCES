#include<iostream>
using namespace std;

void merge(int arr[],int l,int h,int mid){
	int arrlength=h-l+1;
	int arr1size=mid-l+1;
	int arr2size=h-mid;
	int arrIndex=l;
	int arr1[arr1size],arr2[arr2size];
	for(int i=0;i<arr1size;i++){
			arr1[i]=arr[arrIndex++];
	}
	arrIndex=mid+1;
	for(int i=0;i<arr2size;i++){
			arr2[i]=arr[arrIndex++];
	}
	int a1=0,a2=0,a=l;
	while(a1<arr1size&&a2<arr2size){
		if(arr1[a1]<arr2[a2]){
			arr[a]=arr1[a1];
			a1++;
		}
		else{
			arr[a]=arr2[a2];
			a2++;
		}
		a++;
	}
	while(a1<arr1size){
		arr[a]=arr1[a1];
		a1++;
		a++;
	}
	while(a2<arr2size){
		arr[a]=arr2[a2];
		a2++;
		a++;
	}
}
void mergesort(int arr[],int l,int h){
	if(l<h){
		int mid=l+(h-l)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,h);
		merge(arr,l,h,mid);
	}
}
int main(){
	int arr[]={37,15,4,12,10,54,80,2,22};
	int n=sizeof(arr)/sizeof(int);
	mergesort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

