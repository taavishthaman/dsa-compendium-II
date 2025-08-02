#include <bits/stdc++.h>
using namespace std;

void findCombinationsArray(vector<int> coins, int amount, int i, vector<int> v, vector<vector<int>> & res) {
    if(i == coins.size()) {
        return;
    }
    
    if(amount == 0) {
        res.push_back(v);
        return;
    }
    
    for(int j=i; j<coins.size(); j++) {
        if(amount - coins[j] >= 0) {
            v.push_back(coins[j]);
            findCombinationsArray(coins, amount - coins[j], j, v, res);
            v.pop_back();
        } else {
            findCombinationsArray(coins, amount, j+1, v, res);
        }
    }
}

long long int findCombinationsAmount(vector<int> coins, int amount, int i, vector<vector<long long int>> & dp) {
    if(i == coins.size()) {
        return 0;
    }
    
    if(amount == 0) {
        return 1;
    }
    
    if(dp[i][amount] != 0) {
        return dp[i][amount];
    }
    
    long long int ans = 0;
    for(int j=i; j<coins.size(); j++) {
        if(amount - coins[j] >= 0) {
            ans += findCombinationsAmount(coins, amount - coins[j], j, dp);
        } else {
            ans += findCombinationsAmount(coins, amount, j+1, dp);
        }
    }
    
    return dp[i][amount] = ans;
}

long long int findCombinationsBU(int n, vector<int> coins) {
    sort(coins.begin(), coins.end());
    vector<vector<int>> dp(coins.size() + 1, vector<long long int>(n+1, 0));
    
    for(int c=1; c<=coins.size(); c++) {
        for(int m=n; m >= 1; m--) {
            
        }
    }
}

long long findCombinations(int n, vector<int> coins) {
    sort(coins.begin(), coins.end());
    vector<vector<long long int>> dp(coins.size() + 1, vector<long long int>(n+1, 0));
    return findCombinationsAmount(coins, n, 0, dp);
}

int main()
{
    vector<int> coins = {5, 37, 8, 39, 33, 17, 22, 32, 13, 7, 10, 35, 40, 2, 43, 49, 46, 19, 41, 1, 12, 11, 28};
    int amount = 166;
    int combinations = findCombinations(amount, coins);
    cout<<"Combinations "<<combinations<<endl;
    return 0;
}