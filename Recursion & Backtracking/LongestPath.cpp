#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> & v, vector<vector<bool>> & visited, int i, int j, int m, int n, int count, int * max_count) {
    if(i == m-1 && j == n-1) {
        *max_count = max(*max_count, count);
        return;
    }
    
    if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || v[i][j] == 0) {
        return;
    }
    
    visited[i][j] = true;
    
    dfs(v, visited, i, j-1, m, n, count+1, max_count);
    dfs(v, visited, i, j+1, m, n, count+1, max_count);
    dfs(v, visited, i-1, j, m, n, count+1, max_count);
    dfs(v, visited, i+1, j, m, n, count+1, max_count);
    
    visited[i][j] = false;
    return;
}

int findLongestPath(int m, int n, vector<vector<int>> v){
    //Complete this function. Do not modify the name or parameters. You can make a helper function if needed.
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int max_count = 0;
    dfs(v, visited, 0, 0, m, n, 0, &max_count);
    return max_count;
}

int main()
{
    vector<vector<int>> v = {
        {1,1,1},
        {1,1,1},
        {0,0,1}
    };
    
    int m = v.size();
    int n = v[0].size();
    
    int result = findLongestPath(m, n, v);
    cout<<result<<endl;
    
    return 0;
}