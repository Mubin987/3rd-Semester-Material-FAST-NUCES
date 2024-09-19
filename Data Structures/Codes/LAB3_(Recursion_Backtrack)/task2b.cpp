#include<iostream>
using namespace std;
int Fib1(int,int,int,int);
int Fib(int n1,int n2,int n,int orgn){
	if (n <=1){
		return 1;}
	else
	if(n==orgn)
		cout<<n1<<","<<n2<<",";
	return Fib1 (n2,n1+n2,n-1,n);

}
int Fib1(int n1,int n2,int n,int orgn){
	
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
