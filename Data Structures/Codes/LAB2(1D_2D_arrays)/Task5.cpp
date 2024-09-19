#include<iostream>
using namespace std;
int main(){
	double **arr = new double*[5];
	int Size[5];
	int i,j;
	double sum;
	for(i=0;i<5;i++){
		cout<<"Student "<<i+1<< " number of courses: ";
		cin>>Size[i];
		arr[i] =new double[Size[i]];
	}
	for(i=0;i<5;i++){
		for(j=0;j<Size[i];j++){
			cout<<"Enter student " <<i+1<<" gpa: ";
			cin>>*(*(arr + i) + j);
		}
	}
	for(i=0;i<5;i++){
		sum=0;
		for(j=0;j<Size[i];j++){
			sum = sum + *(*(arr + i) + j);
		}
		cout<<"Student " <<i+1<<" cgpa: "<<sum/Size[i]<<endl;
	}
}
