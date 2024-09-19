#include<iostream>
using namespace std;
#define V 6
void print(int dist[]){
	for(int i=0;i<V;i++){
		cout<<i<<"\t"<<dist[i]<<endl;
	}
}
int minDist(int dist[],bool visited[]){
	int min=INT_MAX,minIndex;
	for(int i=0;i<V;i++){
		if(visited[i]==false && dist[i]<min)
			minIndex=i,min=dist[i];
	}
	return minIndex;
}
void dijkstra(int graph[][V],int s){
	int dist[V];
	bool visited[V];
	for(int i=0;i<V;i++){
		dist[i]=INT_MAX;
		visited[i]=false;
	}
	dist[s]=0;
	for(int i=0;i<V-1;i++){
		int u=minDist(dist,visited);
		visited[u]=true;
		for(int v=0;v<V;v++){
			if(graph[u][v]!=0 && visited[v]==false && graph[u][v]+dist[u]<dist[v])
				dist[v]=graph[u][v]+dist[u];
		}
	}
	print(dist);
}

int main(){
	int graph[V][V] = { { 0, 1, 5, 0, 0, 0 },
                        { 1, 0, 2, 2, 1, 0 },
                        { 5, 2, 0, 0, 2, 0 },
                        { 0, 2, 7, 0, 3, 1 },
                        { 0, 1, 2, 3, 0, 2 },
                        { 0, 0, 0, 1, 2, 0 } };
    dijkstra(graph, 0);
}

