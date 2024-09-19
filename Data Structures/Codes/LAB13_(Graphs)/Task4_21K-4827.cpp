#include <iostream>
#include <map>
#include <list>
using namespace std;
#define V 7
void printMST(int [], int [][V]);
int minKey(int key[], bool mstSet[]){
   
    int min = 1000, min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}
void primMST(int graph[V][V]){
    
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;
    key[0] = 0;
    parent[0] = -1; 
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == 0&& graph[u][v] < key[v]){
                parent[v] = u;
				key[v] = graph[u][v];
			}
    }
 
    printMST(parent, graph);
}
void printMST(int parent[], int graph[V][V]){
    cout << "Edge \tWeight"<<endl<<endl;
    for (int i = 1; i < V; i++)
        cout << char(parent[i]+97)<<" - "<< char(i+97)<<" \t"<< graph[i][parent[i]]<<endl;
}
int main()
{
    int graph[V][V] = { { 0, 1, 5, 0, 0, 0, 0},
                        { 1, 0, 4, 8, 7, 0, 0},
                        { 5, 4, 0, 6, 0, 2, 0},
                        { 0, 8, 6, 0,11, 9, 0},
                        { 0, 7, 0,11, 0, 3,10},
                        { 0, 0, 2, 9, 3, 0,12},
                        { 0, 0, 0, 0,10,12, 0} };
 
    primMST(graph);
}
