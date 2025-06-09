#include<bits/stdc++.h>
using namespace std;

pair<int, int> closestSum(vector<int> arr, int x){
    int n = arr.size();
    
    int i = 0;
    int j = n - 1;
    int min_diff = INT_MAX;
    pair<int, int> p = {arr[i], arr[j]};
    
    while(i < j) {
        int curr_sum = arr[i] + arr[j];
        
        if(curr_sum == x) {
            p.first = arr[i];
            p.second = arr[j];
            return p;
        }
        
        int diff = abs(curr_sum - x);
        if(diff < min_diff) {
            min_diff = diff;
            p.first = arr[i];
            p.second = arr[j];
        }
        if(curr_sum < x) {
            i++;
        } else {
            j--;
        }
    }
    
    return p;
}