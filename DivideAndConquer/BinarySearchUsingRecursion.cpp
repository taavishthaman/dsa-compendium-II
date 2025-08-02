#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> & v, int s, int e, int target) {
    if(s > e) return -1;
    
    int mid = (s + e) / 2;
    if(v[mid] == target) return mid;
    else if(target < v[mid]) {
        return binarySearch(v, s, mid-1, target);
    } else {
        return binarySearch(v, mid+1, e, target);
    }
}
  
int binarySearch(vector<int> v, int x)
{
    // your code goes here
    int index = binarySearch(v, 0, v.size() - 1, x);
    return index;
}