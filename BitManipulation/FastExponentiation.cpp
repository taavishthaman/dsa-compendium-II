#include<bits/stdc++.h>
using namespace std;

int fastExponentiation(int a, int n) {
    int ans = 1;
    
    while(n > 0) {
        int last_bit = n & 1;
        if(last_bit == 1) {
            ans = ans * a;
        }
        n = n >> 1;
        a = a * a;
    }
    
    return ans;
}

int main() {
    int a = 3;
    int b = 5;
    int res = fastExponentiation(a, b);
    cout<<"Result is "<<res<<endl;
}