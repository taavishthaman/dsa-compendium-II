#include <bits/stdc++.h>
using namespace std;

int convertToBinary(int n) {
    int ans = 0;
    int power = 1;
    
    while(n > 0) {
        int last_bit = n & 1;
        ans += power * last_bit;
        power = power * 10;
        n = n >> 1;
    }
    
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int result = convertToBinary(n);
    cout<<"Result "<<result<<endl;
    return 0;
}