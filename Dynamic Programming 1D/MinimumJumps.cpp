#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int> & arr, int i, vector<int> & dp) {
    if(i == arr.size() - 1) {
        return 0;
    }
    if(i >= arr.size()) {
        return INT_MAX;
    }
    
    if(dp[i] != 0) {
        return dp[i];
    }
    
    int ans = INT_MAX;
    int maxJump = arr[i];
    
    for(int jump=1; jump<=maxJump; jump++) {
        int res = minJumps(arr, i+jump, dp);
        if(res != INT_MAX) {
            ans = min(ans, res+1);
        }
    }
    
    return dp[i] = ans;
}

int main()
{
    vector<int> arr = {3,4,2,1,2,3,7,1,1,1,2,5};
    int n = arr.size();
    vector<int> dp(n+1, 0);
    int resTd = minJumps(arr, 0, dp);
    cout<<"Res TD "<<resTd<<endl;
    return 0;
}