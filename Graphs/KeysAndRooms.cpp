#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    list<int> * l;
    int V;
    
    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }
    
    void addEdge(int i, int j) {
        l[i].push_back(j);
        l[j].push_back(i);
    }
    
    bool bfs(int src) {
        vector<bool> visited(V, false);
        queue<int> q;
        
        visited[src] = true;
        q.push(src);
        
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            
            for(int nbr : l[f]) {
                if(!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        
        for(bool visit : visited) {
            if(visit == false) return false;
        }
        
        return true;
    }
};

bool canVisitAllRooms(vector<vector<int>>& rooms) {
     // your code goes here
    int n = rooms.size();
    Graph g(n);
    
    for(int i=0; i<n; i++) {
        for(int num : rooms[i]) {
            g.addEdge(i, num);
        }
    }
    
    return g.bfs(0);
    
}