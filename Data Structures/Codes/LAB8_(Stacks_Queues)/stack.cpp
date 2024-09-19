#include<iostream>
#include<stack>
using namespace std;

int main(){
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	int size=s.size();
	for(int i=0;i<size;i++){
		cout<<s.top()<<endl;
		s.pop();
	}
}

