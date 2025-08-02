#include<bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>>& v) {
    // your code goes here
    int largest = 0;
    
    int n = v.size();
    unordered_map<int, int> m;
    
    for(int i=0; i<n; i++) {
        for(int num : v[i]) {
            m[num]++;
            largest = max(largest, num);
        }
    }
    
    for(auto p : m) {
        if(p.second == largest - 1) {
            return p.first;
        }
    }
    
    return -1;
}
