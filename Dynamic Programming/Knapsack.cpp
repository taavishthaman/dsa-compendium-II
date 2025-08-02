#include<bits/stdc++.h>
using namespace std;

int knapsackTd(int wts[], int prices[], int N, int W, vector<vector<int>> & dp) {
    if(N == 0 || W == 0) {
        return 0;
    }
    
    if(dp[N-1][W] != 0) {
        return dp[N-1][W];
    }
    
    int inc = 0, exc = 0;
    
    if(W - wts[N-1] > 0) {
        inc = knapsackTd(wts, prices, N-1, W - wts[N-1], dp) + prices[N-1];
    }
    exc = knapsackTd(wts, prices, N-1, W, dp);
    
    return dp[N-1][W] = max(inc, exc);
}

int knapsackBU(int wts[], int prices[], int W, int N) {
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
    
    //0th row and 0th column would be 0 because if weight is 0 then we can't really make any profit and we are staring the indexing at 1
    
    for(int n=1; n <= N; n++) {
        for(int w=1; w <= W; w++) {
            int inc = 0, exc = 0;
            
            if(w >= wts[n-1]) {
                inc = prices[n-1] + dp[n-1][w - wts[n-1]];
            }
            exc = dp[n-1][w];
            
            dp[n][w] = max(inc, exc);
        }
    }
    
    return dp[N][W];
}

int main() {
    int wts[] = {2, 7, 3, 4};
    int prices[] = {5, 20, 20, 10};
    int N = sizeof(wts) / sizeof(int);
    int W = 11;
    
    vector<vector<int>> dp(N, vector<int>(W, 0));
    
    int result = knapsackTd(wts, prices, N, W, dp);
    cout<<"Result is "<<result<<endl;
    int resultBu = knapsackBU(wts, prices, W, N);
    cout<<"Result is "<<resultBu<<endl;
    
}