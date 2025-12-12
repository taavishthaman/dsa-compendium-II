#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> * l;
    
public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }
    
    void addEdge(int i, int j, bool undir = true) {
        l[i].push_back(j);
        
        if(undir) {
            l[j].push_back(i);
        }
    }
    
    void bfs_shortest_path(int src, int dest = -1) {
        vector<bool> visited(V, false);
        vector<int> dist(V, 0);
        vector<int> parent(V, -1);
        queue<int> q;
        
        q.push(src);
        visited[src] = true;
        parent[src] = src;
        
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            
            for(int nbr : l[f]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                    dist[nbr] = dist[f] + 1;
                    parent[nbr] = f;
                }
            }
        }
        
        for(int i=0; i<V; i++) {
            cout<<"Shortest dist to "<<i<<" is "<<dist[i]<<endl;
        }
        
        if(dest != -1) {
            int temp = dest;
            while(temp != src) {
                cout<<temp<<"--";
                temp = parent[temp];
            }
            cout<<src<<endl;
        }
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.bfs_shortest_path(1, 6);
    return 0;
}