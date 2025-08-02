#include <bits/stdc++.h>
using namespace std;

int getIthBit(int num, int pos) {
    int mask = 1 << pos;
    return num & mask > 0 ? 1 : 0;
}

void setIthBit(int & x, int pos) {
    int mask = 1 << pos;
    x = x | mask;
}

void clearIthBit(int & x, int pos) {
    int mask = ~(1 << pos);
    x = x & mask;
}

void updateIthBit(int & x, int pos, int v) {
    clearIthBit(x, pos);
    int mask = v << pos;
    x = x | mask;
}

void clearLastIBits(int & x, int pos) {
    int mask = ~(0) << pos;
    x = x & mask;
}

void clearRangeOfBits(int & x, int i, int j) {
    int a = -1 << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    x = x & mask;
}

void replaceBitsInRange(int & x, int i, int j, int m) {
    clearRangeOfBits(x, i, j);
    int mask = m << i;
    x = x | mask;
}

int main()
{
    // int x;
    // cin>>x;
    // int pos;
    // cin>>pos;
    // int res = getIthBit(x, pos);
    // cout<<"Result is..."<<res<<endl;
    // setIthBit(x, pos);
    // cout<<"Result is..."<<x<<endl;
    // clearIthBit(x, pos);
    // cout<<"Result is..."<<x<<endl;
    // updateIthBit(x, pos, 1);
    // cout<<"Result is..."<<x<<endl;
    // clearLastIBits(x, pos);
    // cout<<"Result is..."<<x<<endl;
    int x;
    cin>>x;
    int i, j, m;
    cin>>i;
    cin>>j;
    cin>>m;
    clearRangeOfBits(x, i, j);
    replaceBitsInRange(x, i, j, m);
    cout<<"Result is "<<x<<endl;
    return 0;
}