#include<bits/stdc++.h>
using namespace std;

bool outOfOrder(vector<int> v, int i) {
    int n = v.size();
    if(i == 0) {
        return v[i] > v[1];
    }
    if(i == n-1) {
        return v[i] < v[i-1];
    }
    
    return (v[i] < v[i-1]) || (v[i] > v[i+1]);
}

pair<int, int> subarraySort(vector<int> v) {
    int n = v.size();
    int smallest = INT_MAX;
    int largest = INT_MIN;
    
    for(int i=0; i<n; i++) {
        if(outOfOrder(v, i)) {
            smallest = min(smallest, v[i]);
            largest = max(largest, v[i]);
        }
    }
    
    if(smallest == INT_MAX) {
        return {-1, -1};
    }
    
    int left = 0, right = n-1;
    
    while(v[left] <= smallest) {
        left++;
    }
    
    while(v[right] >= largest) {
        right--;
    }
    
    return {left, right};
}

int main() {
    vector<int> v = {1,2,3,4,5,8,6,7,9,10,11};
    pair<int, int> result = subarraySort(v);
    cout<<"Result is "<<result.first<<", "<<result.second<<endl;
}