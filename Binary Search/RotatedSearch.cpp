#include <bits/stdc++.h>
using namespace std;

int rotated_search(vector<int> & arr, int target) {
    int s = 0;
    int e = arr.size() - 1;
    
    while(s <= e) {
        int m = (s + e) / 2;
        
        if(arr[m] == target) {
            return m;
        }
        
        //Mid lies on the left line
        if(arr[s] <= arr[m]) {
            if(target >= arr[s] && target <= arr[m]) {
                e = m - 1;
            } else {
                s = m + 1;
            }
        } else {
            if(target >= arr[m] && target <= arr[e]) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
    }
    
    return -1;
}

int main() {
    vector<int> arr = {4,5,6,7,0,1,2,3};
    int target;
    cin>>target;
    int result = rotated_search(arr, target);
    cout<<target<<" lies at index "<<result<<endl;
    return 0;
}