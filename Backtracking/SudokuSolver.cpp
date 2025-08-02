#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<vector<int>> & board, int row, int col, int num, int n) {
    for(int k=0; k<n; k++) {
        if(board[row][k] == num || board[k][col] == num) {
            return false;
        }
    }
    
    //Check Subgrid
    int r = (row / 3) * 3;
    int c = (col / 3) * 3;
    
    for(int i=r; i<r+3; i++) {
        for(int j=c; j < c+3; j++) {
            if(board[i][j] == num) {
                return false;
            }
        }
    }
    
    return true;
}

void printBoard(vector<vector<int>> & board, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<board[i][j]<<",";
        }
        cout<<endl;
    }
}

bool sudokuSolver(vector<vector<int>> & board, int row, int col, int n) {
    if(row == n) {
        printBoard(board, n);
        return true;
    }
    
    if(col == n) {
        return sudokuSolver(board, row+1, 0, n);
    }
    
    if(board[row][col] != 0) {
        return sudokuSolver(board, row, col+1, n);
    }
    
    for(int num = 1; num <= 9; num++) {
        if(canPlace(board, row, col, num, n)) {
            board[row][col] = num;
            bool success = sudokuSolver(board, row, col+1, n);
            if(success) {
                return true;
            }
        }
    }
    
    board[row][col] = 0;
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
    
    sudokuSolver(board, 0, 0, board.size());

    return 0;
}