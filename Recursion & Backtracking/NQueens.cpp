#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int>> & board, int N) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool canPlace(vector<vector<int>> & board, int row, int col, int N) {
    //Check the column
    int r = row - 1;
    int c = col;
    
    while(r >= 0) {
        if(board[r][c] == 1) {
            return false;
        }
        r--;
    }
    
    //Check left diagonal
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
    
    while(r >= 0 && c < N) {
        if(board[r][c] == 1) {
            return false;
        }
        r--;
        c++;
    }
    
    return true;
}

bool solveNQueen(vector<vector<int>> & board, int i, int N) {
    if(i == N) {
        printBoard(board, N);
        return true;
    }
    
    for(int j=0; j<N; j++) {
        if(canPlace(board, i, j, N)) {
            board[i][j] = 1;
            bool success = solveNQueen(board, i+1, N);
            if(success) {
                return true;
            }
            board[i][j] = 0;
        } 
    }
    
    return false;
}

int main()
{
    int N;
    cin>>N;
    
    vector<vector<int>> board(N, vector<int>(N, 0));
    
    solveNQueen(board, 0, N);
    return 0;
}