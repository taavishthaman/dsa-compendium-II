#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> arr, int target) {
    int n = arr.size();
    
    int s = 0, e = n-1;
    int result = -1;
    
    while(s <= e) {
        int m = (s + e) / 2;
        
        if(arr[m] == target) {
            result = m;
            e = m - 1;
        } else if(target < arr[m]) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    
    return result;
}

int upper_bound(vector<int> arr, int target) {
    int n = arr.size();
    
    int s = 0, e = n-1;
    int result = -1;
    
    while(s <= e) {
        int m = (s + e) / 2;
        
        if(arr[m] == target) {
            result = m;
            s = m + 1;
        } else if(target < arr[m]) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    
    return result;
}

int main() {
    vector<int> arr = {0, 1, 1, 1, 1, 2, 2, 2, 3, 4, 4, 5, 10};
    int target;
    cin>>target;
    cout<<"Frequency Count is "<<(upper_bound(arr, target) - lower_bound(arr, target) + 1)<<endl;
    //STL - upper_bound STL gives the iterator to the element just larger than target, that's why we don't need to do +1
    cout<<"Frequency Count is "<<(upper_bound(arr.begin(), arr.end(), target) - lower_bound(arr.begin(), arr.end(), target))<<endl;
    return 0;
}