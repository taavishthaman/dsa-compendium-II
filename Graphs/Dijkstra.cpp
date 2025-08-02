#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    list<pair<int, int>> * l;
    int V;
    
    Graph(int v) {
        V = v;
        l = new list<pair<int, int>>[V];
    }
    
    void addEdge(int src, int dest, int wt, bool undir = true) {
        l[src].push_back({wt, dest});
        if(undir) {
            l[dest].push_back({wt, src});
        }
    }
    
    int dijkstra(int src, int dest) {
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> s;
        
        dist[src] = 0;
        s.insert({0, src});
        
        while(!s.empty()) {
            auto it = s.begin();
            int node = it->second;
            int distTillNow = it->first;
            
            s.erase(s.begin());
            
            for(auto nbrPair : l[node]) {
                
                int nbr = nbrPair.second;
                int edgeLength = nbrPair.first;
                
                if(distTillNow + edgeLength < dist[nbr]) {
                    //Delete entry from the set if it exists
                    auto it = s.find({dist[nbr], nbr});
                    if(it != s.end()) {
                        s.erase(it);
                    }
                    
                    dist[nbr] = distTillNow + edgeLength;
                    s.insert({dist[nbr], nbr});
                }
            }
        }
        
        for(int i=0; i<dist.size(); i++) {
            cout<<"Node "<<i<<"=>"<<dist[i]<<endl;
        }
        
        return dist[dest];
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(3, 2, 2);
    g.addEdge(3, 4, 3);
    int result = g.dijkstra(0,4);
    cout<<"Dist to dest "<<result<<endl;
}




