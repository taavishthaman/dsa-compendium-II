#include <bits/stdc++.h>
using namespace std;

int rodCuttingTd(vector<int> & prices, int n, vector<int> & dp) {
    if(n <= 0) {
        return 0;
    }
    
    if(dp[n] != 0) {
        return dp[n];
    }
    
    int ans = INT_MIN;
    
    for(int i=0; i<n; i++) {
        int cut = i + 1;
        int current_ans = prices[i] + rodCuttingTd(prices, n-cut, dp);
        ans = max(ans, current_ans);
    }
    
    return dp[n] = ans;
}

int rodCuttingBu(vector<int> & prices, int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    
    for(int len=1; len<=n; len++) {
        dp[len] = INT_MIN;
        for(int i=0; i<len; i++) {
            int cut = i+1;
            //Make a cut of length (i+1) and add prices[i] which would be the price of the cut, and compute rest of the ans from dp[len-cut]
            int current_profit = prices[i] + dp[len-cut]; 
            dp[len] = max(dp[len], current_profit);
        }
    }
    
    return dp[n];
}

int main()
{
    vector<int> prices = {1,5,8,9,10,17,17,20};
    int n = 8;
    vector<int> dp(n+1, 0);
    int resTd = rodCuttingTd(prices, n, dp);
    cout<<"Res Td "<<resTd<<endl;
    int resBu = rodCuttingBu(prices, n);
    cout<<"Res Bu "<<resBu<<endl;
    return 0;
}