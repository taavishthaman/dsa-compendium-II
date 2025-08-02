#include<bits/stdc++.h>
using namespace std;


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
    // your code goes here
    unordered_map<int, int> m;
    
    for(int num : nums1) {
        m[num] += 1;
    }
    
    vector<int> op;
    
    for(int num : nums2) {
        if(m.find(num) != m.end()) {
            op.push_back(num);
            m.erase(num);
        }
    }
    
    sort(op.begin(), op.end());
    
    return op;
}

