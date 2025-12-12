#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int V;
    list<int> * l;
    
public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }
    
    void addEdge(int u, int v) {
        l[u].push_back(v);
    }
    
    int bfsShortestPath(int src, int dest) {
        vector<bool> visited(V, false);
        vector<int> dist(V, 0);
        queue<int> q;
        
        q.push(src);
        visited[src] = true;
        
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            
            for(int nbr : l[f]) {
                if(!visited[nbr]) {
                    visited[nbr] = true;
                    dist[nbr] = dist[f] + 1;
                    q.push(nbr);
                }
            }
        }
        
        return dist[dest];
    }
};

int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders) {
    vector<int> delta_map(n+1, 0);
    
    for(auto p : ladders) {
        int f = p.first;
        int s = p.second;
        
        delta_map[f] = (s - f);
    }
    
    for(auto p : snakes) {
        int f = p.first;
        int s = p.second;
        delta_map[f] = (s - f);
    }
    
    //Construct the graph
    Graph g(n+1);
    for(int u=1; u<=n; u++) {
        for(int dice=1; dice<=6; dice++) {
            int v = u + dice;
            if(v <= n) {
                v += delta_map[v];
                g.addEdge(u, v);
            }
        }
    }
    
    return g.bfsShortestPath(1, n);
}

int main() {
    int n = 36;
    vector<pair<int, int>> snakes = {{17, 4}, {20, 6}, {24, 16}, {32, 30}, {34, 12}};
    vector<pair<int, int>> ladders = {{2, 15}, {5, 7}, {9, 27}, {18, 29}, {25, 35}};
    
    int result = min_dice_throws(n, snakes, ladders);
    cout<<"Min throws requiured are "<<result<<endl;
}
