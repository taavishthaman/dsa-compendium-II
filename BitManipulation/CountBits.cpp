#include<bits/stdc++.h>
using namespace std;

int countBits(int num) {
    int res = 0;
    while(num > 0) {
        if(num & 1 == 1) {
            res += 1;
        }
        num = num >> 1;
    }
    
    return res;
}

int countBitsHack(int num) {
    int res = 0;
    
    while(num > 0) {
        num = num & (num - 1);
        res += 1;
    }
    
    return res;
}

int main() {
    int num;
    cin>>num;
    int result = countBits(num);
    cout<<"Result is "<<result<<endl;
    int result2 = countBitsHack(num);
    cout<<"Result is "<<result2<<endl;
}