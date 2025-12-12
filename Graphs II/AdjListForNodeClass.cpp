#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string name;
    list<string> nbrs;
    
    Node(string name) {
        this->name = name;
    }
};

class Graph {
    unordered_map<string, Node*> m;
public:
    Graph(vector<string> cities) {
        for(string city : cities) {
            m[city] = new Node(city);
        }
    }
    
    void addEdge(string src, string dest, bool undir = false) {
        m[src]->nbrs.push_back(dest);
        
        if(undir) {
            m[dest]->nbrs.push_back(src);
        }
    }
    
    void printAdjList() {
        for(auto p : m) {
            string city = p.first;
            list<string> nbrs = p.second->nbrs;
            
            cout<<city<<"-->";
            for(auto nbr : nbrs) {
                cout<<nbr<<",";
            }
            cout<<endl;
        }
    }
};

int main()
{
    vector<string> cities = {"Delhi", "London", "Paris", "New York"};
    Graph g(cities);
    
    g.addEdge("Delhi", "London");
    g.addEdge("New York", "London");
    g.addEdge("Delhi", "Paris");
    g.addEdge("Paris", "New York");
    
    g.printAdjList();
    return 0;
}