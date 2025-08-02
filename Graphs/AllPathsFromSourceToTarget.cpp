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
    
    void addEdge(int src, int dest) {
        l[src].push_back(dest);
    }
    
    void dfs(int node, int dest, vector<int> path, vector<vector<int>> & paths) {
        if(node == dest) {
            path.push_back(dest);
            paths.push_back(path);
            return;
        }
        path.push_back(node);
        for(int nbr : l[node]) {
            dfs(nbr, dest, path, paths);
        }
    }
    
    vector<vector<int>> dfs() {
        vector<vector<int>> paths;
        vector<int> path;
        
        dfs(0, V-1, path, paths);
        return paths;
    }
};

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    // your code goes here
    int n = graph.size();
    Graph g(n);
    for(int i=0; i<n; i++) {
        for(int node : graph[i]) {
            g.addEdge(i, node);
        }
    }
    vector<vector<int>> paths = g.dfs();
    return paths;
}

