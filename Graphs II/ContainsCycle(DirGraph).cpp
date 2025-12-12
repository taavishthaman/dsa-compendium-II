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
    
    void addEdge(int i, int j, bool undir = false) {
        l[i].push_back(j);
        
        if(undir) {
            l[j].push_back(i);
        }
    }
    
    bool dfs(int node, vector<bool> & visited, vector<bool> & s) {
        visited[node] = true;
        s[node] = true;
        
        for(int nbr : l[node]) {
            if(!visited[nbr]) {
                bool cycleFound = dfs(nbr, visited, s);
                if(cycleFound) {
                    return true;
                }
            } else if(s[nbr]) {
                return true;
            }
        }
        
        s[node] = false;
        return false;
    }
    
    bool backEdgeDetection(int source) {
        vector<bool> visited(V, false);
        vector<bool> s(V, false);
        
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                bool cycleFound = dfs(source, visited, s);
                if(cycleFound) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,2);
    g.addEdge(3,4);
    bool cycleFound = g.backEdgeDetection(0);
    if(cycleFound) {
        cout<<"Graph contains a cycle"<<endl;
    } else {
        cout<<"Graph does not contain a cycle"<<endl;
    }
    return 0;
}