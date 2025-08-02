#include <bits/stdc++.h>
using namespace std;

int convertToBinary(int n) {
    int res = 0;
    int power = 1;
    
    while(n > 0) {
        int x = n & 1;
        n = n >> 1;
        
        res = res + x * power;
        power = power * 10;
    }
    
    return res;
}

int main()
{
    int n;
    cin>>n;
    int result = convertToBinary(n);
    
    cout<<"Result is "<<result<<endl;

    return 0;
}