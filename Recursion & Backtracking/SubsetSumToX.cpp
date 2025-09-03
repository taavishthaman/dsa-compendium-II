#include <bits/stdc++.h>
using namespace std;

int countSubsets(vector<int> & arr, int target, int i) {
    if(i == arr.size()) {
        if(target == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    
    int inc = countSubsets(arr, target - arr[i], i+1);
    int exc = countSubsets(arr, target, i+1);
    return inc + exc;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    int target;
    cin>>target;
    int count = countSubsets(arr, target, 0);
    cout<<"Total subsets that sum to target "<<count<<endl;
    return 0;
}