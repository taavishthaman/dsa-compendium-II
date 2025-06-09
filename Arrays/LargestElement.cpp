#include<bits/stdc++.h>
using namespace std;

int largestElement(vector<int> arr) {
    int largest = INT_MIN;
    
    for(int num : arr) {
        largest = max(largest, num);
    }
    
    return largest;
}