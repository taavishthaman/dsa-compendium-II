#include<bits/stdc++.h>
using namespace std;

int lis(vector<int> arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    int max_len = 1;
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                max_len = max(max_len, dp[i]);
            }
        }
    }
    
    return max_len;
}

int main() {
    vector<int> arr = {50, 4, 10, 8, 30, 100};
    cout<<lis(arr)<<endl;
}