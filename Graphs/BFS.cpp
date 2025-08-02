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
    
    void bfs(int source) {
        queue<int> q;
        vector<bool> visited(V, false);
        
        q.push(source);
        visited[source] = true;
        
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            cout<<f<<", ";
            
            for(auto nbr : l[f]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
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
    g.bfs(1);
}