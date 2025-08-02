#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    list<int> * l;
    int V;
    
    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }
    
    void addEdge(int i, int j, bool undir = true) {
        l[i].push_back(j);
        l[j].push_back(i);
    }
    
    void dfsHelper(int node, vector<bool> & visited) {
        visited[node] = true;
        cout<<node<<", ";
        
        for(int nbr : l[node]) {
            if(!visited[nbr]) {
                dfsHelper(nbr, visited);
            }
        }
    }
    
    void dfs(int source) {
        vector<bool> visited(V, false);
        dfsHelper(source, visited);
    }
};

int main() {
    Graph g(7);
    
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.dfs(1);
}