#include <bits/stdc++.h>
using namespace std;

int fibRec(int n) {
    if(n ==0 || n == 1) {
        return n;
    }
    
    return fibRec(n-1) + fibRec(n-2);
}

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
    
    dp[1] = 1;
    
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

int fibOpt(int n) {
    int f = 0;
    int s = 1;
    
    for(int i=2; i<=n; i++) {
        int sum = f + s;
        f = s;
        s = sum;
    }
    
    return s;
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1, 0);
    
    cout<<"Fib Rec "<<fibRec(n)<<endl;
    cout<<"Fib Td "<<fibTd(n, dp)<<endl;
    cout<<"Fib Bu "<<fibBu(n)<<endl;
    cout<<"Fib Opt "<<fibOpt(n)<<endl;

    return 0;
}