#include <bits/stdc++.h>
using namespace std;

void binaryStrings(int n, string s, vector<string> & op) {
    if(n == 0) {
        op.push_back(s);
        return;
    }
    
    if(n == 1) {
        op.push_back(s+'0');
        op.push_back(s+'1');
        return;
    }
    
    binaryStrings(n-1, s + "0", op);
    binaryStrings(n-2, s + "10", op);
}

vector<string> binaryStrings(int n) {
   vector<string> op;
   
   binaryStrings(n, "", op);
   
   return op;
}

int main() {
    int n;
    cin>>n;
    
    vector<string> op = binaryStrings(n);
    
    for(string str : op) {
        cout<<str<<", ";
    }
}