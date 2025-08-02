#include <bits/stdc++.h>
using namespace std;

int mangoTrees(vector<vector<char>> & farm) {
    int n = farm.size();
    int m = farm[0].size();
    
    vector<vector<int>> prefix(n, vector<int>(m, 0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            if(i == 0 && j == 0) {
                if(farm[i][j] == '#') {
                    prefix[i][j] = 1;
                }
            } else if (i == 0) {
                prefix[i][j] = prefix[i][j-1] + (farm[i][j] == '#' ? 1 : 0);
            } else if (j == 0) {
                prefix[i][j] = prefix[i-1][j] + (farm[i][j] == '#' ? 1 : 0);
            } else {
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + (farm[i][j] == '#' ? 1 : 0);
            }
        }
    }
    
    int max_trees = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int S1 = prefix[i][j];
            int S2 = prefix[i][m-1] - S1;
            int S3 = prefix[n-1][j] - S1;
            int S4 = prefix[n-1][m-1] - S1 - S2 - S3;
            
            int min_trees = min({S1, S2, S3, S4});
            max_trees = max(max_trees, min_trees);
        }
    }
    
    return max_trees;
}

int main()
{
    vector<vector<char>> farm = {
        {'.','#','#','.','.','.'},
        {'#','.','.','#','#','.'},
        {'.','#','.','.','.','.'},
        {'.','#','#','.','.','#'},
        {'#','.','.','#','#','.'},
        {'.','#','.','.','.','.'}
    };
    
    int result = mangoTrees(farm);
    cout<<"Result "<<result<<endl;
    return 0;
}