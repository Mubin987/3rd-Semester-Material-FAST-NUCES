#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pi;
int main(){
	
	priority_queue<pi,vector<pi>,greater<pi>> pq;
	pq.push(make_pair(2,10));
	pq.push(make_pair(3,20));
	pq.push(make_pair(1,30));
	cout<<pq.top().first<<" "<<pq.top().second<<endl<<endl;
	
	priority_queue<pair<int,int>> pq2;
	pq2.push(make_pair(2,10));
	pq2.push(make_pair(3,20));
	pq2.push(make_pair(1,30));
	cout<<pq2.top().first<<" "<<pq2.top().second<<endl<<endl;
	
}

