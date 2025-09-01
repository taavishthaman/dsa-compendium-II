#include <bits/stdc++.h>
using namespace std;

pair<int,int> search(int m, int n, vector<vector<int>> v, int k){
    //write your code here.
    pair<int, int> result = {-1,-1};
    
    int i = 0, j = n-1;
    
    while(i < m && j >= 0) {
        if(v[i][j] == k) {
            result.first = i;
            result.second = j;
            return result;
        } else if(k < v[i][j]) {
            j--;
        } else {
            i++;
        }
    }
    
    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1,4,9},
        {2,5,10},
        {6,7,11}
    };
    int m = matrix.size();
    int n = matrix[0].size();
    int k = 10;
    
    pair<int, int> result = search(m, n, matrix, k);
    cout<<result.first<<" - "<<result.second<<endl;
    return 0;
}