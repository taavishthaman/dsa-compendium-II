#include <bits/stdc++.h>
using namespace std;

int linear_search(int * arr, int n, int target) {
    for(int i=0; i<n; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    int arr[] = {10,15,12,9,6,4,3,10,8};
    int n = sizeof(arr) / sizeof(int);
    int target;
    cout<<"Enter the value of target"<<endl;
    cin>>target;
    int result_ls = linear_search(arr, n, target);
    if(result_ls == -1) {
        cout<<"Target not found"<<endl;
    } else {
        cout<<"Target found at index "<<result_ls<<endl;
    }
}