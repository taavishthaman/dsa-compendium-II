#include<bits/stdc++.h>
using namespace std;

int longestSubarrayKSum(vector<int> arr,int k){
    //Complete this function and return the length of longest subarray
    int n = arr.size();
    vector<int> prefix(n, 0);
    unordered_map<int, int> m;
    
    prefix[0] = arr[0];
    int max_len = 0;
    m[arr[0]] = 0;
    
    for(int i=1; i<n; i++) {
        int curr_sum = prefix[i-1] + arr[i];
        
        if(m.find(curr_sum - k) != m.end()) {
            int subarray_size = (i - m[curr_sum - k]);
            if(subarray_size > max_len) {
                max_len = subarray_size;
            }
        }
        
        if(curr_sum == k) {
            int subarray_size = i + 1;
            if(subarray_size > max_len) {
                max_len = subarray_size;
            }
        }
        
        m[curr_sum] = i;
        prefix[i] = curr_sum;
    }
    
    return max_len;
}

int main() {
    vector<int> arr = { 0,-2,1,2,3,4,5,15,10,5 };
    int k = 15;
    
    int result = longestSubarrayKSum(arr, k);
    cout<<"Result is "<<result<<endl;
}
