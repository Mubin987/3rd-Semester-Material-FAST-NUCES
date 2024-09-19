#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template <typename T>
class Graph{
	public:
		map<T,list<T>> adj;
		
//		void add_edge(T s,T d){
//				adj[s].push_back(d);
//				adj[d].push_back(s);
//		}
		void addedge(vector<vector<int>> edges){
			for(int i=0;i<edges.size();i++){
				int s=edges[i][0];
				int d=edges[i][1];
				adj[s].push_back(d);
				adj[d].push_back(s);
			}
		}
		void print(){
			for(auto x:adj){
				cout<<x.first<<" -> ";
				for(auto y:x.second){
					cout<<y<<" ";
				}
				cout<<endl;
			}
		}
		void BFS(T snode){
			queue<T> q;
			map<T,bool> visited;
			q.push(snode);
			visited[snode]=1;
			while(!q.empty()){
				T frontnode=q.front();
				q.pop();
				cout<<frontnode<<"->";
				for(auto i:adj[frontnode]){
					if(visited[i]==0){
						q.push(i);
						visited[i]=1;
					}	
				}
			}	
		}
};
int main(){
//	Graph <int>g1;
	vector<vector<int>> edges= {{0,1},
					 			{1,2},
					 			{2,3},	
					 			{3,4},
					 			{4,1}};
	Graph <int>G;
	G.addedge(edges);
	G.print();
	cout<<endl;
	G.BFS(0);
//	int n,m;int s,d;
//	cout<<"Enter number of vertices:";cin>>n;
//	cout<<"Enter number of edges:";cin>>m;
//	for(int i=0;i<m;i++){
//		cin>>s>>d;
//		g1.add_edge(s,d);
//	}
//	g1.print();
//	cout<<endl;
//	g1.BFS(0);
}

