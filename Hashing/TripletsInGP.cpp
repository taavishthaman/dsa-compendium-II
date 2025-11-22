#include <bits/stdc++.h>
using namespace std;

int countTripletsInGp(vector<int> & arr, int r) {
    int n = arr.size();
    unordered_map<long, int> left, right;
    
    for(int i=0; i<n; i++) {
        right[arr[i]] += 1;
        left[arr[i]] = 0;
    }
    
    int ans = 0;
    
    for(int i=0; i<n; i++) {
        long b = arr[i];
        right[b] -= 1;
        
        if(b % r == 0) {
            long a = b / r;
            long c = b * r;
            
            ans += left[a] * right[c];
        }
        
        left[b] += 1;
    }
    
    return ans;
}

int main()
{
    vector<int> arr = {1, 16, 4, 16, 64, 16};
    int r = 4;
    
    cout<<"Total triplets in GP are "<<countTripletsInGp(arr, r)<<endl;
    return 0;
}