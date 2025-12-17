#include <bits/stdc++.h>
using namespace std;

int minCoinChangeTd(vector<int> denoms, int m, vector<int> & dp) {
    if(m < 0) {
        return INT_MAX;
    }
    if(m == 0) {
        return 0;
    }
    
    if(dp[m] != 0) {
        return dp[m];
    }
    
    int ans = INT_MAX;
    
    for(int c : denoms) {
        int res = minCoinChangeTd(denoms, m-c, dp);
        if(res != INT_MAX) {
            ans = min(ans, 1 + res);
        }
    }
    
    return dp[m] = ans;
}

int minCoinChangeBu(vector<int> denoms, int m) {
    vector<int> dp(m+1, INT_MAX);
    dp[0] = 0;
    
    for(int i=1; i<=m; i++) {
        for(int c : denoms) {
            if(i - c >= 0 && dp[i-c] != INT_MAX) {
                dp[i] = min(dp[i], dp[i-c] + 1);
            }
        }
    }
    
    return dp[m] == INT_MAX ? -1 : dp[m];
}

int main()
{
    vector<int> denoms = {1,3,5,7};
    int m;
    cin>>m;
    vector<int> dp(m+1, 0);
    int resBu = minCoinChangeBu(denoms, m);
    cout<<"Res Bu "<<resBu<<endl;
    int resTd = minCoinChangeTd(denoms, m, dp);
    cout<<"Res Td "<<resTd<<endl;
    return 0;
}