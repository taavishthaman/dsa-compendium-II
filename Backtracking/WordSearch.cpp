#include <bits/stdc++.h>
using namespace std;

bool findWord(vector<vector<char>> & board, string word, vector<vector<int>> & visited, int i, int j, int n, int m, int k) {
    if(k == word.size() - 1 && word[k] == board[i][j]) {
        return true;
    }
    
    visited[i][j] = true;
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    for(int dir = 0; dir < 4; dir++) {
        int nr = i + dy[dir];
        int nc = j + dx[dir];
        
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && board[nr][nc] == word[k+1]) {
            bool success = findWord(board, word, visited, nr, nc, n, m, k + 1);
            if(success) return true;
        }
    }
    
    visited[i][j] = false;
    return false;
}

bool wordSearch(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == word[0]) {
                bool success = findWord(board, word, visited, i, j, n, m, 0);
                if(success) return true;
            }
        }
    }
    
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    
    string word = "SEE";
    
    bool result = wordSearch(board, word);
    cout<<"Result is "<<result;
}