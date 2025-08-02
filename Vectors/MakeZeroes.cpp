#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> makeZeroes(vector<vector<int>> arr){
    // your code goes here
    int n = arr.size();
    int m = arr[0].size();
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j] == 0) {
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }
    
    //Process Rows
    for(int i=0; i<n; i++) {
        if(arr[i][0] == 0) {
            for(int j=0; j < m; j++) {
                arr[i][j] = 0;
            }
        }
    }
    
    //Process cols
    for(int i=0; i<m; i++) {
        if(arr[0][i] == 0) {
            for(int j=0; j<n; j++) {
                arr[j][i] = 0;
            }
        }
    }
    
    return arr;
    
}