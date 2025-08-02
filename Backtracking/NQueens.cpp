#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<vector<int>> & board, int row, int col, int n) {
    //Check column
    int r = row - 1;
    
    while(r >= 0) {
        if(board[r][col] == 1) return false;
        r--;
    }
    
    r = row - 1;
    int c = col - 1;
    
    while(r >= 0 && c >= 0) {
        if(board[r][c] == 1) return false;
        r--; c--;
    }
    
    r = row - 1;
    c = col + 1;
    
    while(r >= 0 && c < n) {
        if(board[r][c] == 1) return false;
        r--; c++;
    }
    
    return true;
}

void printBoard(vector<vector<int>> & board, int n) {
    for(int i=0; i< n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] == 0) {
                cout<<"[ ]";
            } else {
                cout<<"[Q]";
            }
        }
        cout<<endl;
    }
}

bool solveNQueen(vector<vector<int>> & board, int row, int n) {
    if(row == n) {
        printBoard(board, n);
        return true;
    }
    
    for(int col=0; col<n; col++) {
        if(canPlace(board, row, col, n)) {
            board[row][col] = 1;
            bool success = solveNQueen(board, row+1, n);
            if(success) {
                return true;
            }
            //backtracking step
            board[row][col] = 0;
        }
    }
    
    //If we can't place the queen anywhere in the current column, we'll return false
    return false;
}

int countNQueens(vector<vector<int>> & board, int row, int n) {
    if(row == n) {
        printBoard(board, n);
        cout<<endl;
        return 1;
    }
    
    int ways = 0;
    
    for(int col = 0; col < n; col++) {
        if(canPlace(board, row, col, n)) {
            board[row][col] = 1;
            ways += countNQueens(board, row + 1, n);
            board[row][col] = 0;
        }
    }
    
    return ways;
}

int main()
{
    vector<vector<int>> board(20, vector<int>(20, 0));
    
    int n;
    cin>>n;
    // solveNQueen(board, 0, n);
    int result = countNQueens(board, 0, n);
    cout<<"Number of ways are "<<result<<endl;
    return 0;
}