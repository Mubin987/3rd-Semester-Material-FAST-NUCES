#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template <typename T>
class Graph{
	public:
		map<T,list<T>> g;
		
		void add_edge(T s,T d,bool direction){
			if(direction){
				g[s].push_back(d);
			}
			else{
				g[s].push_back(d);
				g[d].push_back(s);
			}
		}
		void print(){
		//	cout<<g[0].first<<endl<<endl;
			for(auto x:g){
				cout<<x.first<<" -> ";
				for(auto y:x.second){
					cout<<y<<" ";
				}
				cout<<endl;
			}
		}
		
};
int main(){
	Graph <char>g1;
	int n,m;char s,d;bool dir;
	cout<<"Enter number of vertices:";cin>>n;
	cout<<"Enter number of edges:";cin>>m;
	cout<<"Enter 1 for directed or 0 for undirected graph:";cin>>dir;
	for(int i=0;i<m;i++){
		cin>>s>>d;
		g1.add_edge(s,d,dir);
	}
	g1.print();
}

