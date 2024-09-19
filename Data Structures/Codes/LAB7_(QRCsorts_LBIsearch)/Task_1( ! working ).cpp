#include<iostream>
using namespace std;
bool not_sorted(int[],int);
void Quick_sort(int arr[],int n,int l,int h,int l_retain,int h_retain,int flag){
	if(h==l)
		return;
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
	if(flag==0){
		Quick_sort(arr,n,l_retain,i-1,l_retain,h_retain,flag+1);
	}
	if(flag==1){
		Quick_sort(arr,n,h+2,h_retain,l_retain,h_retain,flag-1);
	}
	
}
bool not_sorted(int arr[],int n){
	for(int i=0;i<n;i++){
		if(arr[i]>arr[i+1])
			return 0;
	}
	return 1;
}
int main(){
	int n, array[]={19,4,15,12,16,18,7,11,13};
	n=sizeof(array)/sizeof(int);
	cout<<n<<endl;
	Quick_sort(array,n,0,n-1,0,n-1,0);
}


