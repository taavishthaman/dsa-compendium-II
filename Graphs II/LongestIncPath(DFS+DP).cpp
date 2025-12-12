#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> & matrix, vector<vector<bool>> & visited, vector<vector<int>> & cache, int i, int j, int N, int M) {
    
    visited[i][j] = true;
    int ans = 0;
    
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    for(int k=0; k<4; k++) {
        int nx = j + dx[k];
        int ny = i + dy[k];
        
        if(nx >= 0 && ny >= 0 && nx < M && ny < N && matrix[ny][nx] > matrix[i][j]) {
            if(visited[ny][nx]) {
                ans = max(ans, 1 + cache[ny][nx]);
            } else {
                dfs(matrix, visited, cache, ny, nx, N, M);
                ans = max(ans, 1 + cache[ny][nx]);
            }
        }
    }
    
    cache[i][j] = ans;
    
    return ans;
}

int longestPathSequence(vector<vector<int> > matrix){
    //Complete this function
    // Hint : You may need to use DP, to store the longestPath length for already visited 'states'
    int N = matrix.size();
    int M = matrix[0].size();
    
    vector<vector<int>> cache(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    
    int max_length = 0;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            int curr_length = dfs(matrix, visited, cache, i, j, N, M);
            max_length = max(max_length, curr_length);
        }
    }
    
    return 1 + max_length;
}

int main() {
    vector<vector<int>> grid = {
        {0, 2, 4, 3, 2},
        {7, 6, 5, 5, 1},
        {8, 9, 7, 18, 14},
        {5, 10, 11, 12, 13}
    };
    
    cout<<longestPathSequence(grid)<<endl;
}