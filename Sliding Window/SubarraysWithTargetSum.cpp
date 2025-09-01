#include <bits/stdc++.h>
using namespace std;

int cntSubarrays(vector<int> arr,int k){
    int n = arr.size();
    unordered_map<int, int> m;
    vector<int> prefix(n, 0);
    prefix[0] = arr[0];
    m[arr[0]] = 1;
    
    int cnt = 0;
    
    for(int i=1; i<n; i++) {
        prefix[i] = prefix[i-1] + arr[i];
        if(prefix[i] == k) {
            cnt++;
        }
        
        int target = prefix[i] - k;
        
        if(m.count(target)) {
            cnt += m[target];
        }
        
        m[prefix[i]]++;
    }
    
    return cnt;
    
}

int main()
{
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;
    cout<<cntSubarrays(arr, k)<<endl;
}