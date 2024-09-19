#include<iostream>
using namespace std;
int main(){
	int **arr = new int*[3];
	int i,j;
	for(i=0;i<3;i++){
		arr[i]=new int[3];
		for(j=0;j<3;j++){
			cout<<"Enter Element [" <<i<<"]"<<"["<<j<<"] : ";
			cin>>*(*(arr + i) + j);
		}
	}
	if(*(*(arr + 0) + 0)==1&&*(*(arr + 0) + 1)==0&&*(*(arr + 0) + 2)==0&&*(*(arr + 1) + 0)==0&&
	*(*(arr + 1) + 1)==1&&*(*(arr + 1) + 2)==0&&*(*(arr + 2) + 0)==0&&*(*(arr + 2) + 1)==0&&*(*(arr + 2) + 2)==1){
		cout<<"Identity matrix";
	}
	else{
		cout<<"Not Identity matrix";
	}
}
