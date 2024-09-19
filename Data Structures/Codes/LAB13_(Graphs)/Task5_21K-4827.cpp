#include <iostream>
using namespace std;
#include <limits.h>
#define V 6
void printSolution(int []);
int minDist(int dist[], bool sptSet[]){
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
void dijkstra(int graph[V][V], int s){
    int dist[V]; 
    bool sptSet[V]; 
    for (int i = 0; i < V; i++)
    	dist[i] = INT_MAX, sptSet[i] = 0;
    dist[s] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDist(dist, sptSet);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v]&& dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);
}

void printSolution(int dist[]){
    cout << "Vertex \t Distance from Source" << endl<<endl;
    cout << 's' << " \t\t" << dist[0] << endl;
    for (int i = 1; i < V; i++){
        cout << char(i+96) << " \t\t" << dist[i] << endl;
	}
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
