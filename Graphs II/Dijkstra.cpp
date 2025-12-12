#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>> * l;
    
public:
    Graph(int V) {
        this->V = V;
        l = new list<pair<int, int>>[V];
    }
    
    void addEdge(int u, int v, int wt, bool undir = true) {
        l[u].push_back({wt, v});
        
        if(undir) {
            l[v].push_back({wt, u});
        }
    }
    
    int dijkstra(int src, int dest) {
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> s;
        
        s.insert({0, src});
        dist[src] = 0;
        
        while(!s.empty()) {
            auto f = s.begin();
            
            int node = f->second;
            int distTillNow = f->first;
            
            s.erase(f);
            
            for(auto nbrPair : l[node]) {
                int nbr = nbrPair.second;
                int edgeLength = nbrPair.first;
                
                auto it = s.find({dist[nbr], nbr});
                
                if(it != s.end()) {
                    s.erase(it);
                }
                
                if(distTillNow + edgeLength < dist[nbr]) {
                    dist[nbr] = distTillNow + edgeLength;
                    s.insert({dist[nbr], nbr});
                }
            }
        }
        
        for(int num : dist) {
            cout<<num<<" ";
        }
        cout<<endl;
        
        return dist[dest];
    }
};

int main() {
    Graph g(5);
    
    g.addEdge(0,1,1);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(1,2,1);
    g.addEdge(2,3,2);
    g.addEdge(3,4,3);
    
    cout<<g.dijkstra(0, 4)<<endl;
}