#include<bits/stdc++.h>
using namespace std;


int lowerBound(vector<int> A, int Val) {
    // your code goes here
    int n = A.size();
    int lo = 0;
    int hi = n - 1;
    int lb = -1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        
        if(A[mid] == Val) {
            return Val;
        } else if(A[mid] < Val) {
            lb = A[mid];
            lo++;
        } else {
            hi--;
        }
    }
    
    return lb;
}