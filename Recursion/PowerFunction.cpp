#include <bits/stdc++.h>
using namespace std;

int powerFun(int a, int n) {
    if(n == 0) return 1;
    
    return a * powerFun(a, n-1);
}

int fastPower(int a, int n) {
    if(n == 0) return 1;
    
    int subProb = fastPower(a, n/2);
    if(n & 1) {
        return a * subProb * subProb;
    }
    
    return subProb * subProb;
}

int main() {
    int a, n;
    cin>>a>>n;
    int result = powerFun(a, n);
    cout<<"Result is "<<result<<endl;
    int fast_result = fastPower(a, n);
    cout<<"Result is "<<fast_result<<endl;
}