#include<bits/stdc++.h>
using namespace std;

vector<int> kRotate(vector<int> a, int k){
    // your code  goes here
    int n = a.size();
    k = k % n;
    
    reverse(a.begin(), a.end());
    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());
    
    return a;
}