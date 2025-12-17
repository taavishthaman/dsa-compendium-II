#include <bits/stdc++.h>
using namespace std;

long long minFrogCost(vector<int> stones, int k) {
    int n = stones.size();
    vector<long long> dp(n, INT_MAX);
    dp[0] = 0;
    
    for(int i=1; i<n; i++) {
        for(int j=i-1; j>=i-k; j--) {
            if(j >= 0) {
                dp[i] = min(dp[i], dp[j] + abs(stones[i] - stones[j]));
            }
        }
    }
    
    return dp[n-1];
}

int main()
{
    vector<int> stones = {10, 30, 40, 50, 20};
    int K = 3;
    long long result = minFrogCost(stones, K);
    cout<<result<<endl;
    return 0;
}