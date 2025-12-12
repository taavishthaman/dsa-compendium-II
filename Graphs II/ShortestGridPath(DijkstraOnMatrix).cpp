#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int x, y, dist;
    
    Node(int x, int y, int dist) {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};

class Compare {
public:
    bool operator()(const Node & a, const Node & b) {
        return a.dist <= b.dist;
    }
};

int shortestGridPath(vector<vector<int>> & grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    set<Node, Compare> s;
    
    dist[0][0] = 0;
    s.insert(Node(0, 0, grid[0][0]));
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    while(!s.empty()) {
        auto f = s.begin();
        int cx = f->x;
        int cy = f->y;
        int cd = f->dist;
        
        s.erase(f);
        
        for(int k=0; k<4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && cd + grid[ny][nx] < dist[ny][nx]) {
                Node n(nx, ny, dist[ny][nx]);
                auto it = s.find(n);                
                if(it != s.end()) {
                    s.erase(it);
                }
                
                dist[ny][nx] = cd + grid[ny][nx];
                s.insert(Node(nx, ny, dist[ny][nx]));
            }
        }
    }
    
    return dist[n-1][m-1];
}

int main() {
    vector<vector<int>> grid = {
        {31, 100, 65, 12, 18},
        {10, 13, 47, 157, 6},
        {100, 113, 174, 11, 33},
        {88, 124, 41, 20, 140},
        {99, 32, 111, 41, 20}
    };
    
    int result = shortestGridPath(grid);
    cout<<"Shortest Grid Path is "<<result<<endl;
}