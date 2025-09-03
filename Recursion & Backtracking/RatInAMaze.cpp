#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>> & c, vector<vector<int>> & numGrid, vector<vector<bool>> & visited, int i, int j, vector<int> & path, int n) {
    if(i == n-1 && j== n-1) {
        path.push_back(numGrid[i][j]);
        return true;
    }
    
    if(i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || c[i][j] == 'X') {
        return false;
    }
    
    visited[i][j] = true;
    path.push_back(numGrid[i][j]);
    
    bool left = dfs(c, numGrid, visited, i, j-1, path, n);
    bool right = dfs(c, numGrid, visited, i, j+1, path, n);
    bool up = dfs(c, numGrid, visited, i-1, j, path, n);
    bool down = dfs(c, numGrid, visited, i+1, j, path, n);
    
    if(left || right || up || down) {
        return true;
    }
    
    visited[i][j] = false;
    path.pop_back();
    return false;
}

vector<int> findPath(int n, vector<vector<char>> c) {
    vector<vector<int>> numGrid(n, vector<int>(n, 0));
    
    int count = 1;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            numGrid[i][j] = count;
            count += 1;
        }
    }
    
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    vector<int> path;
    
    dfs(c, numGrid, visited, 0, 0, path, n);
    
    return path;
}

int main()
{
    int n = 4;
    vector<vector<char>> v = {
        {'O', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O'},
        {'O', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'O'}
    };
    
    vector<int> path = findPath(n, v);
    for(int num : path) {
        cout<<num<<", ";
    }
    
    return 0;
}