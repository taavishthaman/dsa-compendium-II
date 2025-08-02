#include<bits/stdc++.h>
using namespace std;

int fibTd(int n, vector<int> & dp) {
    if(n == 0 || n == 1) {
        return n;
    }
    
    if(dp[n] != 0) {
        return dp[n];
    }
    
    return dp[n] = fibTd(n-1, dp) + fibTd(n-2, dp);
}

int fibBu(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

int main() {
    int n;
    cin>>n;
    vector<int> dp(n+1, 0);
    cout<<fibTd(n, dp)<<endl;
    cout<<fibBu(n)<<endl;
}