#include <bits/stdc++.h>
using namespace std;

int countBST(int n) {
    if(n ==0 || n == 1) {
        return 1;
    }
    
    int ans = 0;
    for(int i=1; i<=n; i++) {
        int left = countBST(i-1);
        int right = countBST(n-i);
        ans += left * right;
    }
    
    return ans;
}

int countBSTTd(int n, vector<int> & dp) {
    if(n == 0 || n == 1) {
        return 1;
    }
    
    if(dp[n] != 0) {
        return dp[n];
    }
    
    int ans = 0;
    for(int i=1; i<=n; i++) {
        int left = countBSTTd(i-1, dp);
        int right = countBSTTd(n-i, dp);
        ans += left * right;
    }
    
    return dp[n] = ans;
}

int countBSTBu(int N) {
    vector<int> dp(N+1, 0);
    dp[0] = dp[1] = 1;
    
    for(int n=2; n<=N; n++) {
        for(int i=1; i<=n; i++) {
            dp[n] += dp[i-1] * dp[n-i];
        }
    }
    
    return dp[N];
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1, 0);
    int result = countBST(n);
    cout<<"Result "<<result<<endl;
    int resultTd = countBSTTd(n, dp);
    cout<<"Result "<<resultTd<<endl;
    int resultBu = countBSTBu(n);
    cout<<"Result "<<resultBu<<endl;
    return 0;
}