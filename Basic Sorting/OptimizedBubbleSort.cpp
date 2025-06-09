#include<bits/stdc++.h>
using namespace std;

vector<int> optimizedBubbleSort(vector<int> v){
    bool is_sorted = true;
    int n = v.size();
    
    for(int i=0; i < n - 1; i++) {
        if(v[i] > v[i+1]) {
            is_sorted = false;
            break;
        }
    }
    
    if(is_sorted == true) return v;
    
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-1-i; j++) {
            if(v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
            }
        }
    }
    
    return v;
}