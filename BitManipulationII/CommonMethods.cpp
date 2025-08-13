#include <bits/stdc++.h>
using namespace std;

int getIthBit(int x, int i) {
    int mask = (1 << i);
    return (x & mask) > 0 ? 1 : 0;
}

int setIthBit(int x, int i) {
    int mask = (1 << i);
    return x | mask;
}

int clearIthBit(int x, int i) {
    int mask = ~(1 << i);
    return x & mask;
}

int updateIthBit(int x, int i, int v) {
    int aux = clearIthBit(x, i);
    int mask = (v << i);
    return aux | mask;
}

int clearLastIBits(int n, int i) {
    int mask = (-1 << i);
    return (n & mask);
}

int clearBitsInRange(int n, int i, int j) {
    int a = -1 << (j+1);
    int b = (1 << i) - 1;
    
    int mask = a | b;
    return n & mask;
}

int replaceBits(int n, int i, int j, int m) {
    int aux = clearBitsInRange(n, i, j);
    int mask = (m << i);
    return aux & mask;
}

int main()
{
    int n, i, v;
    cin>>n>>i>>v;
    int result = getIthBit(n, i);
    cout<<"Result is "<<result<<endl;
    int setResult = setIthBit(n, i);
    cout<<"Result after setting bit "<<setResult<<endl;
    int clearResult = clearIthBit(n, i);
    cout<<"Result after clearing bit "<<clearResult<<endl;
    int updateResult = updateIthBit(n, i, v);
    cout<<"Result after updating bit "<<updateResult<<endl;
    int clearLastResult = clearLastIBits(n, i);
    cout<<"Result after clearing last i bits "<<clearLastResult<<endl;
    return 0;
}