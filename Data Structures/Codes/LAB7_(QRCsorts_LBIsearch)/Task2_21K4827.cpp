#include<iostream>
using namespace std;
int find_digits(int m){
	int d;
	if(m>=0&&m<10)
		d=1;
	if(m>=10&&m<100)
		d=2;
	if(m>=100&&m<1000)
		d=3;
	if(m>=1000&&m<10000)
		d=4;
	return d;			
}

int *update_arr(int count[],int arr[],int n,int digit){
	int *u_arr=new int[n],j;
	switch(digit){
		case 1:
			for(int i=n-1;i>=0;i--){
				j=arr[i]%10;
				count[j]--;
				u_arr[count[j]]=arr[i];
			}
		break;	
		case 2:
			for(int i=n-1;i>=0;i--){
				j=arr[i]%100/10;
				count[j]--;
				u_arr[count[j]]=arr[i];
			}
		break;	
		case 3:
			for(int i=n-1;i>=0;i--){
				j=arr[i]%1000/100;
				count[j]--;
				u_arr[count[j]]=arr[i];
			}
		break;	
	}
	cout<<endl<<endl;
	for(int i=0;i<n;i++){
		cout<<u_arr[i]<<",";
	}
	cout<<endl;
	return u_arr;
}
int *count_calc(int array[],int n,int digit){
	int temp_count[10]={0};
	static int count[10]={0};
	int match=0;
	switch(digit){
		case 1:	
			for(int i=0;i<n;i++){
				match=0;
				match=array[i]%10;
				temp_count[match]++;
			}
			for(int i=0;i<10;i++){
				cout<<temp_count[i]<<",";
			}
			for(int i=0;i<10;i++){
				count[i]=temp_count[i]+count[i-1];
			}
			break;
		case 2:
			for(int i=0;i<n;i++){
				match=0;
				match=array[i]%100/10;
				temp_count[match]++;
			}
			cout<<endl;
			for(int i=0;i<10;i++){
				cout<<temp_count[i]<<",";
			}
			for(int i=0;i<10;i++){
				count[i]=temp_count[i]+count[i-1];
			}
			break;
		case 3:
			for(int i=0;i<n;i++){
				match=0;
				match=array[i]%1000/100;
				temp_count[match]++;
			}
			cout<<endl;
			for(int i=0;i<10;i++){
				cout<<temp_count[i]<<",";
			}
			for(int i=0;i<10;i++){
				count[i]=temp_count[i]+count[i-1];
			}
			break;	
	}
	return count;
}
void Radix_sort(int arr[],int n,int dtot){
	int counter=1;
	int *count,*up_arr;
	while(counter<=dtot){
		switch(counter){
			case 1:
				count=count_calc(arr,n,1);
				cout<<endl;
				for(int i=0;i<10;i++){
					cout<<count[i]<<",";
				}
				up_arr=update_arr(count,arr,n,1);
			break;
			case 2:
				count=count_calc(arr,n,2);
				cout<<endl;
				for(int i=0;i<10;i++){
					cout<<count[i]<<",";
				}
				up_arr=update_arr(count,up_arr,n,2);
			break;
			case 3:
				count=count_calc(arr,n,3);
				cout<<endl;
				for(int i=0;i<10;i++){
					cout<<count[i]<<",";
				}
				up_arr=update_arr(count,up_arr,n,3);
			break;
		}
		counter++;
	}
}

int main(){
	int n,digits,max, array[]={36,987,654,2,20,99,456,957,555,420,66,3};
	n=sizeof(array)/sizeof(int);
	for(int i=0;i<n;i++){
		if(array[i]>max)
			max=array[i];
	}
	digits=find_digits(max);
	Radix_sort(array,n,digits);
}

