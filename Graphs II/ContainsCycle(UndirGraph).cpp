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
    
    bool dfsHelper(int node, vector<bool> & visited, int parent) {
        visited[node] = true;
        
        for(int nbr : l[node]) {
            if(!visited[nbr]) {
                bool containsCycle = dfsHelper(nbr, visited, node);
                if(containsCycle) {
                    return true;
                }
            } else if(parent != nbr) {
                return true;
            }
        }
        
        return false;
    }
    
    bool containsCycle(int source) {
        vector<bool> visited(V, false);
        
        return dfsHelper(source, visited, -1);
    }
};

int main()
{
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    bool cycleFound = g.containsCycle(0);
    if(cycleFound) {
        cout<<"Graph contains a cycle"<<endl;
    } else {
        cout<<"Graph does not contain a cycle"<<endl;
    }
    return 0;
}