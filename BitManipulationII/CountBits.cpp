#include <bits/stdc++.h>
using namespace std;

int countBits(int n) {
    int count = 0;
    while(n > 0) {
        int lastBit = n & 1;
        if(lastBit == 1) {
            count += 1;
        }
        n = n >> 1;
    }
    
    return count;
}

int countBitsHack(int n) {
    int ans = 0;
    
    while(n > 0) {
        //Removes last set bit from the number
        n = n & (n-1);
        ans++;
    }
    
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int result = countBits(n);
    cout<<"Result is "<<result<<endl;
    int resultFast = countBitsHack(n);
    cout<<"Result is "<<resultFast<<endl;
    
    return 0;
}