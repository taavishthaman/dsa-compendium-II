#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> & grid, vector<vector<bool>> & visited, int i, int j, int N, int M) {
    visited[i][j] = true;
    int cs = 1;
    
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    for(int k=0; k<4; k++) {
        int nx = j + dx[k];
        int ny = i + dy[k];
        
        if(nx >= 0 && ny >= 0 && nx < M && ny < N && !visited[ny][nx] && grid[ny][nx] == 1) {
            cs += dfs(grid, visited, ny, nx, N, M);
        }
    }
    
    return cs;
}

int largest_island(vector<vector<int> > grid){
    //return the size of largest island in grid
    int N = grid.size();
    int M = grid[0].size();
    
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int largest = 0;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(grid[i][j] == 1 && !visited[i][j]) {
                int cs = dfs(grid, visited, i, j, N, M);
                largest = max(largest, cs);
            }
        }
    }
    
    return largest;
}

int main() {
    vector<vector<int>> grid = {
        {1, 0, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 0, 1, 1, 0}
    };
    
    cout<<largest_island(grid)<<endl;
}