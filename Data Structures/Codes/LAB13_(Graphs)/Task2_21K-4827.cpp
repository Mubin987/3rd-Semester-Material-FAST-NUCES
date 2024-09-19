#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class Graph{
public:
    map<T, vector<T> > v1;
    
    void addEdge(T x, T y){
        v1[x].push_back(y);
        v1[y].push_back(x);
    }
    
    void BFS(T sNode){
        map<T, int> visited;
        queue<T> q;
        
        q.push(sNode);
        visited[sNode] = 1;
        
        while(!q.empty()){
        T node = q.front();
        q.pop();
        cout << node << "->";
        
        for(int nbr:v1[node]){
            if(visited[nbr]==0){
                q.push(nbr);
                visited[nbr] = 1;
            }
        }
    }
}
};

int main() {
    Graph<char> g;
    g.addEdge('A','B');
    g.addEdge('B','C');
    g.addEdge('C','D');
    g.addEdge('D','E');
    g.addEdge('E','F');
    g.addEdge('F','G');
    g.addEdge('G','H');
    g.addEdge('H','I');
    g.addEdge('I','J');
    g.BFS('A');
}
