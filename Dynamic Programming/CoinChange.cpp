#include<bits/stdc++.h>
using namespace std;

int coinChangeTd(vector<int> denoms, int amount, vector<int> & dp) {
    if(amount == 0) {
        return 0;
    }
    
    if(amount < 0) {
        return INT_MAX;
    }
    
    if(dp[amount] != 0) {
        return dp[amount];
    }
    
    int ans = INT_MAX;
    
    for(int c : denoms) {
        if(amount - c >= 0) {
            int res = coinChangeTd(denoms, amount - c, dp);
            if(res != INT_MAX) {
                ans = min(ans, res + 1);
            }
        }
    }
    
    return dp[amount] = ans;
}

int coinChangeBu(vector<int> denoms, int amount) {
    vector<int> dp(amount + 1, 0);
    
    for(int i=1; i <= amount; i++) {
        dp[i] = INT_MAX;
        
        for(int c : denoms) {
            if(i - c >= 0 && dp[i-c] != INT_MAX) {
                dp[i] = min(dp[i], dp[i-c] + 1);
            }
        }
    }
    
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> denoms = {1,5,7,10};
    int amount = 16;
    vector<int> dp(amount + 1, 0);
    int result = coinChangeBu(denoms, amount);
    cout<<"Result "<<result<<endl;
    result = coinChangeTd(denoms, amount, dp);
    cout<<"Result "<<result<<endl;
}