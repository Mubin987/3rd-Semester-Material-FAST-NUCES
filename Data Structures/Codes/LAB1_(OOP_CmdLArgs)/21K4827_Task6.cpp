#include<iostream>
using namespace std;
int main(){
	int s;
	cout<<"How many sections grades you want to store?";
	cin>>s;
	char **arr = new char*[s];
	int Size[s];
	int i,j;
	for(i=0;i<s;i++){
		cout<<"Section "<<i+1<< " number of students: ";
		cin>>Size[i];
		arr[i] =new char[Size[i]];
	}
	for(i=0;i<s;i++){
		for(j=0;j<Size[i];j++){
			cout<<"Enter Section " <<i+1<<" grades: ";
			cin>>*(*(arr + i) + j);
		}
	}
}

