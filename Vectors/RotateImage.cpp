#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
     int n = matrix.size();
      
      //1. Transpose
      for(int i=0; i<n; i++) {
          for(int j=0; j<n; j++) {
            if(i >= j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
      }
      
      //2. Columnwise swapping
      for(int i=0; i<n; i++) {
          for(int j=0; j<n/2; j++) {
              swap(matrix[i][j], matrix[i][n-1-j]);
          }
      }
}
