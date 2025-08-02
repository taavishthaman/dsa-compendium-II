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
    }
    
    void topologicalSort() {
        vector<int> indegree(V, 0);
        queue<int> q;
        
        for(int i=0; i<V; i++) {
            for(int nbr : l[i]) {
                indegree[nbr] += 1;
            }
        }
        
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            cout<<f<<", ";
            
            for(int nbr : l[f]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }
};

int main() {
    Graph g(6);
    
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(1, 4);
    g.addEdge(1, 2);
    g.topologicalSort();
}