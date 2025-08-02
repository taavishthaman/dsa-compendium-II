#include<bits/stdc++.h>
using namespace std;

int wines(vector<int> bottles, int L, int R, vector<vector<int>> & dp) {
    if(L > R) {
        return 0;
    }
    
    int year = bottles.size() - (R - L);
    
    if(dp[L][R] != 0) {
        return dp[L][R];
    }
    
    int pickLeft = year * bottles[L] + wines(bottles, L + 1, R, dp);
    int pickRight = year * bottles[R] + wines(bottles, L, R - 1, dp);
    
    return dp[L][R] = max(pickLeft, pickRight);
}

int winesBu(vector<int> bottles) {
    int n = bottles.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<n; j++) {
            if(i == j) {
                dp[i][j] = n * bottles[i];
            } else if (i < j) {
                int year = n - (j - i);
                int pick_left = bottles[i] * year + dp[i+1][j];
                int pick_right = bottles[j] * year + dp[i][j-1];
                
                dp[i][j] = max(pick_left, pick_right);
            }
        }
    }
    
    return dp[0][n-1];
}

int main() {
    
    vector<int> bottles = {2,3,5,1,4};
    int n = bottles.size();
    
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    int result = wines(bottles, 0, n-1, dp);
    cout<<"Result is "<<result<<endl;
    int resultBu = winesBu(bottles);
    cout<<"Result is "<<resultBu<<endl;
}