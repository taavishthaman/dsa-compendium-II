#include <bits/stdc++.h>
using namespace std;

int binary_search(int * arr, int n, int target) {
    int start = 0;
    int end = n - 1;
    
    while(start <= end) {
        int mid = (start + end) / 2;
        
        if(arr[mid] == target) {
            return mid;
        } else if(target < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    
    return -1;
}

int main() {
    int arr[] = {8,10,14,20,25,28,32};
    int n = sizeof(arr) / sizeof(n);
    int target;
    cin>>target;
    int result = binary_search(arr, n, target);
    cout<<"Result is..."<<result<<endl;
}