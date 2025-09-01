#include <bits/stdc++.h>
using namespace std;

bool outOfOrder(vector<int> a, int i) {
    int n = a.size();
    
    if(i == 0) {
        return a[i] > a[i+1];
    } else if (i == n-1) {
        return a[i] < a[i-1];
    } else {
        return (a[i] < a[i-1]) || (a[i] > a[i+1]);
    }
}

pair<int, int> subarraySorting(vector<int> a) {
    /*
        Algorithm
        First find the smallest and the largest value that is out of order
        left and right pointers
        Increment left unitl <= smallest
        Decrement right until >= largest
    */
    
    int n = a.size();
    int smallest = INT_MAX;
    int largest = INT_MIN;
    
    for(int i=0; i<n; i++) {
        if(outOfOrder(a, i)) {
            smallest = min(smallest, a[i]);
            largest = max(largest, a[i]);
        }
    }
    
    if(smallest == INT_MAX) {
        return {-1,-1};
    }
    
    int left = 0, right = n-1;
    
    while(left < n && a[left] <= smallest) {
        left++;
    }
    
    while(right >= 0 && a[right] >= largest) {
        right--;
    }
    
    return {left, right};
}

int main() {
    vector<int> a = {0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29};
    pair<int, int> result = subarraySorting(a);
    cout<<result.first<<", "<<result.second<<endl;
    return 0;
}