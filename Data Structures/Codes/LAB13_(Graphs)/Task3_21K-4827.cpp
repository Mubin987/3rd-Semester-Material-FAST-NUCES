#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Graph {
public:
    map<int, bool> visited;
    map<int, vector<int> > adj;
 
    void addEdge(int s ,int d){
        adj[s].push_back(d); 
    }
 
    void DFS(int v){
        visited[v] = true;
        cout << v << " ";
     
        vector<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                DFS(*i);
    }
};
 
int main()
{
    Graph g;
	g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(7,8);
    g.addEdge(8,9);
    g.DFS(0);
}
