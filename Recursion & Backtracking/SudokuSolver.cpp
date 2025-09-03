#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int>> & board, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool canPlace(vector<vector<int>> & board, int row, int col, int num, int n) {
    //Check of row and col
    for(int i=0; i<n; i++) {
        if(board[i][col] == num || board[row][i] == num) {
            return false;
        }
    }
    
    //Check 3X3 subgrid
    int r = (row / 3) * 3;
    int c = (col / 3) * 3;
    
    for(int i=r; i<r+3; i++) {
        for(int j=c; j <c+3; j++) {
            if(board[i][j] == num) {
                return false;
            }
        }
    }
    
    return true;
}

bool solveSudoku(vector<vector<int>> & board, int i, int j, int n) {
    if(i == n) {
        printBoard(board, n);
        return true;
    }
    
    if(j == n) {
        return solveSudoku(board, i+1, 0, n);
    }
    
    if(board[i][j] != 0) {
        return solveSudoku(board, i, j+1, n);
    }
    
    for(int num = 1; num <= 9; num++) {
        if(canPlace(board, i, j, num, n)) {
            board[i][j] = num;
            bool success = solveSudoku(board, i, j+1, n);
            
            if(success) {
                return true;
            }
        }
    }
    
    board[i][j] = 0;
    return false;
}

int main()
{
    vector<vector<int>> board = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    
    int n = board.size();
    
    solveSudoku(board, 0, 0, n);
    return 0;
}