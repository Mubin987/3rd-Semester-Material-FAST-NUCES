#include<iostream>
using namespace std;

int Func(int n,int seq){
	if (n >=seq){
		return 1;}
	else
	cout <<(n+1)*0.5*n<<",";
	return Func (n+1,seq);
}
int main(){
    int a;
    cout <<"Enter sequence size:"<<endl;
	cin>>a;
	Func(1,a+1);
}

