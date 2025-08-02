#include <bits/stdc++.h>
using namespace std;

bool findPath(vector<string> arr, vector<vector<int>> & visited, int i, int j, int n, int m) {
    if(i == n-1 && j == m-1) {
        visited[i][j] = 1;
        return true;
    }
    
    if(i < 0 || i >= n || j < 0 || j >= m || arr[i][j] == 'X' || visited[i][j]) {
        return false;
    }
    
    visited[i][j] = 1;
    
    bool up = findPath(arr, visited, i-1, j, n, m);
    bool down = findPath(arr, visited, i+1, j, n, m);
    bool left = findPath(arr, visited, i, j-1, n, m);
    bool right = findPath(arr, visited, i, j+1, n, m);
    
    if(up || down || left || right) return true;
    
    visited[i][j] = 0;
    
    return false;
}

vector<vector<int>> ratAndMice(vector<string> arr) {
    int n = arr.size();
    int m = arr[0].size();
    
    vector<vector<int>> visited(n, vector<int>(m, 0));
    
    bool res = findPath(arr, visited, 0, 0, n, m);
    
    return visited;
}

int main()
{
    vector<string> arr = {
        "OXOO",
        "OOOX",
        "XOXO",
        "XOOX",
        "XXOO"
    };
    
    vector<vector<int>> path = ratAndMice(arr);
    for(int i=0; i<path.size(); i++) {
        for(int j=0; j<path[0].size(); j++) {
            cout<<path[i][j]<<", ";
        }
        cout<<endl;
    }
    

    return 0;
}