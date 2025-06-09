#include<bits/stdc++.h>
using namespace std;

int maxSumSubarray(vector<int> A) {
    bool allNeg = true;
    int largest = INT_MIN;
    
    for(int num : A) {
        if(num >= 0) {
            allNeg = false;
            break;
        }
        largest = max(largest, num);
    }
    
    if(allNeg == true) {
        return largest;
    }
    
    largest = 0;
    int curr_sum = 0;
    int n = A.size();
    
    for(int i=0; i<n; i++) {
        curr_sum += A[i];
        if(curr_sum < 0) {
            curr_sum = 0;
        }
        
        largest = max(largest, curr_sum);
    }
    
    return largest;
}