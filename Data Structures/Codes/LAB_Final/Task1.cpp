#include<iostream>
#include<iostream>
using namespace std;
bool sum(int i,int j,int n,int arr[]){
	int sum1=arr[i]+arr[j];bool found=false;
	for(int key3=0;key3<n;key3++){
		for(int key4=key3+1;key4<n;key4++){
			int sum2=arr[key3]+arr[key4];
			if(key3!=i&&key3!=j&&key4!=i&&key4!=j&&sum1==sum2){
				found=true;
				cout<<"("<<arr[i]<<","<<arr[j]<<") and ("<<arr[key3]<<","<<arr[key4]<<")"<<endl;
			}
				
		}	
	}
	return found;
}
int main(){
	int n=7;int found=0;
	int arr1[n]={3,4,7,1,2,9,8};
	cout<<"Combinations for array 1"<<endl<<endl;
	for(int key1=0;key1<n;key1++){
		for(int key2=key1+1;key2<n;key2++){
			found=found+sum(key1,key2,n,arr1);
		}	
	}
	if(found==0)
		cout<<"No pairs found"<<endl;
	else
		cout<<found<<" pairs found"<<endl;	
	cout<<endl;
	n=6;found=0;
	int arr2[n]={3,4,7,1,12,9};
	cout<<"Combinations for array 2"<<endl<<endl;
	for(int key1=0;key1<n;key1++){
		for(int key2=key1+1;key2<n;key2++){
			found=found+sum(key1,key2,n,arr2);
		}	
	}
	if(found==0)
		cout<<"No pairs found"<<endl;
	else
		cout<<found<<" pairs found"<<endl;		
}
