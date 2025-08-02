#include<bits/stdc++.h>
using namespace std;

int xoring(vector<int> v)
{
    // your code goes here
    int n = v.size();
    int num = v[0];
    
    for(int i=1; i< n; i++) {
        num = num ^ v[i];
    }
    
    return num;
    
}