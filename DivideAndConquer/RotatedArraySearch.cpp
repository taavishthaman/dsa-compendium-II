#include <bits/stdc++.h>
using namespace std;

int rotatedArraySearch(vector<int> & arr, int s, int e, int target) {
    
    while(s <= e) {
        int mid = (s + e) / 2;
        
        if(arr[mid] == target) {
            return mid;
        }
        
        if(arr[s] <= arr[mid]) {
            if(target >= arr[s] && target <= arr[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        } else {
            if(target >= arr[mid] && target <= arr[e]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
    }
    
    return -1;
}

int main()
{
    vector<int> arr = {4,5,6,7,0,1,2,3};
    int target;
    cin>>target;
    int result = rotatedArraySearch(arr, 0, arr.size() - 1, target);
    cout<<"Result is "<<result<<endl;
    return 0;
}