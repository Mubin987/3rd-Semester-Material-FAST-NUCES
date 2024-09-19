#include<iostream>
#define V 7
using namespace std;
	void print(int key[],int parent[]){
		for(int v=1;v<V;v++){
			int u=parent[v];
			cout<<u<<"-"<<v<<"\t"<<key[v]<<endl;
		}	
	}
	int minkey(int key[],bool visited[]){
		int minIndex,min=INT_MAX;
			for(int i=0;i<V;i++){
				if(key[i]<min&&visited[i]==false)
					minIndex=i,min=key[i];
			}
		return minIndex;	
	}
	void prims(int graph[V][V]){
		bool visited[V];
		int key[V];
		int parent[V];
		for(int i=0;i<V;i++){
			key[i]=INT_MAX;
			visited[i]=false;
		}
		parent[0]=-1;
		key[0]=0;
		for(int i=0;i<V-1;i++){
			int u=minkey(key,visited);
			visited[u]=true;
			for(int v=0;v<V;v++){
				if(graph[u][v]&&visited[v]==false&&graph[u][v]<key[v]){
					key[v]=graph[u][v];
					parent[v]=u;
				}
			}
		}
		print(key,parent);
	}
	
int main(){
	int graph[V][V] = { { 0, 1, 5, 0, 0, 0, 0},
                        { 1, 0, 4, 8, 7, 0, 0},
                        { 5, 4, 0, 6, 0, 2, 0},
                        { 0, 8, 6, 0,11, 9, 0},
                        { 0, 7, 0,11, 0, 3,10},
                        { 0, 0, 2, 9, 3, 0,12},
                        { 0, 0, 0, 0,10,12, 0} };
 
    prims(graph);
}

