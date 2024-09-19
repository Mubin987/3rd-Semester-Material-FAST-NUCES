#include<iostream>
using namespace std;

int Fib(int n1,int n2,int n,int orgn){
	if (n <=1){
		return 1;}
	else
	if(n==orgn)
		cout<<n1<<","<<n2<<",";
	if(n!=orgn)
		cout<<n2<<",";
	return Fib (n2,n1+n2,n-1,n);
}
int main(){
    int a;
    cout <<"Enter sequence size:"<<endl;
	cin>>a;
	Fib(0,1,a,a);
}
