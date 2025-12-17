#include <bits/stdc++.h>
using namespace std;

int NKLaddersTd(int n, int k, vector<int> & dp) {
    if(n < 0) {
        return 0;
    }
    if(n == 0) {
        return 1;
    }
    
    if(dp[n] != 0) {
        return dp[n];
    }
    
    int ans = 0;
    
    for(int jump=1; jump<=k; jump++) {
        ans += NKLaddersTd(n-jump, k, dp);
    }
    
    return dp[n] = ans;
}

int NKLaddersBu(int N, int K) {
    vector<int> dp(N+1, 0);
    dp[0] = 1;
    
    for(int i=1; i<=N; i++) {
        for(int k=1; k<=K; k++) {
            if(i - k >= 0) {
                dp[i] += dp[i-k];
            }
        }
    }
    
    return dp[N];
}

int NKLaddersBuOpt(int N, int K) {
    vector<int> dp(N+1, 0);
    dp[0] = dp[1] = 1;
    
    for(int i=2; i<=N; i++) {
        dp[i] += 2 * dp[i-1];
        if(i-1-K >= 0) {
            dp[i] -= dp[i-1-K];
        }
    }
    
    return dp[N];
}

int main()
{
    int n, k;
    cin>>n>>k;
    
    vector<int> dp(n+1, 0);

    int resTd = NKLaddersTd(n, k, dp);
    cout<<resTd<<endl;
    int resBu = NKLaddersBu(n, k);
    cout<<resBu<<endl;
    int resOpt = NKLaddersBuOpt(n, k);
    cout<<resOpt<<endl;
    return 0;
}