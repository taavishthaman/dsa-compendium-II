#include<bits/stdc++.h>
using namespace std;

int rainwaterTrapping(vector<int> heights) {
    int n = heights.size();
    vector<int> left(n, 0), right(n, 0);
    
    left[0] = heights[0];
    right[n-1] = heights[n-1];
    
    for(int i=1; i<n; i++) {
        left[i] = max(left[i-1], heights[i]);
        right[n-1-i] = max(right[n-i], heights[n-1-i]);
    }
    
    int total_water = 0;
    
    for(int i=0; i<n; i++) {
        total_water += min(left[i], right[i]) - heights[i];
    }
    
    return total_water;
}

int main() {
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = rainwaterTrapping(v);
    cout<<"Result is "<<result<<endl;
}