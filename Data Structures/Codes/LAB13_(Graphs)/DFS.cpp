#include<iostream>
#include<map>
#include<vector>
using namespace std;
class graph{
	public:
		map<int,vector<int>> adj;
		map<int,bool> visited;
		void addedge(vector<vector<int>> edges){
			for(int i=0;i<edges.size();i++){
				int s=edges[i][0];
				int d=edges[i][1];
				adj[s].push_back(d);
				adj[d].push_back(s);
			}
		}
		void DFS(int v){
			visited[v]=1;
			cout<<v<<"->";
			for(auto x:adj[v]){
				if(!visited[x])
					DFS(x);
			}
		}
};
int main(){
	vector<vector<int>> edges= {{0,1},
					 			{1,2},
					 			{2,3},	
					 			{3,4},
					 			{4,1}};
	graph G;
	G.addedge(edges);
	G.DFS(0);
}

