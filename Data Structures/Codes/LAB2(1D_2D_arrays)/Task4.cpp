#include<iostream>
using namespace std;
int main(){
	bool arr[5][5] = {{0,1,0,1,1},{1,0,1,0,1},{0,1,0,0,0},{1,0,0,0,1},{1,1,0,1,0}};
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(*(*(arr + i) + j)==1 && *(*(arr + j) + i)==1){
				cout<<i<<" and "<<j<<" are both friends"<<endl;
			}
		}
	}
}
