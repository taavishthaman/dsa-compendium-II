#include <bits/stdc++.h>
using namespace std;

vector<int> maxSubarraySizeK(vector<int> arr, int k) {
    int n = arr.size();
    deque<int> q(k);
    vector<int> result;
    //Process the first k elements
    
    for(int i=0; i<k; i++) {
        while(!q.empty() && arr[i] >= arr[q.back()]) {
            q.pop_back();
        }
        
        q.push_back(i);
    }
    
    //Process the rest of elements
    for(int i=k; i<n; i++) {
        result.push_back(arr[q.front()]);
        
        while(!q.empty() && q.front() <= i-k) {
            q.pop_front();
        }
        
        while(!q.empty() && arr[i] >= arr[q.back()]) {
            q.pop_back();
        }
        
        q.push_back(i);
    }
    
    result.push_back(arr[q.front()]);
    
    return result;
}

int main()
{
    vector<int> arr = {1,2,3,1,4,5,2,3,5};
    int k = 3;
    vector<int> result = maxSubarraySizeK(arr, k);
    
    for(int num : result) {
        cout<<num<<", ";
    }

    return 0;
}