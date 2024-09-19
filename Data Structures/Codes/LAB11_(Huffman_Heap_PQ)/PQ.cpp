#include<iostream>
#include<queue>
//#include <bits/stdc++.h>
using namespace std;

int main(){
//	PQ
//	priority_queue<int> q;
//	reverse PQ
	priority_queue<int,vector<int>,greater<int>> q;
	q.push(4);
	q.push(6);
	q.push(5);
	q.push(2);
	q.push(7);
	q.push(4);
	while(!q.empty()){
		cout<<q.top()<<"\n";
		q.pop();
	}
}
