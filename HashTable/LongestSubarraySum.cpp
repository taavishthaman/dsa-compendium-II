#include<bits/stdc++.h>
using namespace std;


int longestSubarrayKSum(vector<int> arr,int k){
    // your code goes here
    int n = arr.size();
    vector<int> prefix(n, 0);
    unordered_map<int, int> m;
    
    prefix[0] = arr[0];
    m[prefix[0]] = 0;
    
    int max_length = 0;
    
    for(int i=1; i<n; i++) {
        prefix[i] = prefix[i-1] + arr[i];
        
        if(m.find(prefix[i] - k) != m.end()) {
            int length = i - m[prefix[i]-k];
            max_length = max(length, max_length);
        }
        
        if(prefix[i] == k) {
            int length = i + 1;
            max_length = max(max_length, length);
        }
        
        m[prefix[i]] = i;
    }
    
    return max_length;
}
