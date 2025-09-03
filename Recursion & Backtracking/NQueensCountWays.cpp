#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<vector<int>> & board, int row, int col, int n) {
    
    int r = row - 1;
    int c = col;
    
    while(r >= 0) {
        if(board[r][col] == 1) {
            return false;
        }
        r--;
    }
    
    r = row - 1;
    c = col - 1;
    while(r >= 0 && c >= 0) {
        if(board[r][c] == 1) {
            return false;
        }
        r--;
        c--;
    }
    
    r = row - 1;
    c = col + 1;
    
    while(r >= 0 && c < n) {
        if(board[r][c] == 1) {
            return false;
        }
        r--;
        c++;
    }
    
    return true;
}

int countWays(vector<vector<int>> & board, int i, int n) {
    if(i == n) {
        return 1;
    }
    
    int ways = 0;
    
    for(int j=0; j<n; j++) {
        if(canPlace(board, i, j, n)) {
            board[i][j] = 1;
            ways += countWays(board, i+1, n);
            board[i][j] = 0;
        }
    }
    
    return ways;
}

int nQueen(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    return countWays(board, 0, n);
}

int main()
{
    int n;
    cin>>n;
    cout<<nQueen(n)<<endl;
    return 0;
}