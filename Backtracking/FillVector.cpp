#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> & arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<", ";
    }
}

void fillArray(vector<int> & arr, int i, int n, int val) {
    if(i == n) {
        printArray(arr, n);
        cout<<endl;
        return;
    }
    
    arr[i] = val;
    fillArray(arr, i+1, n, val+1);
    arr[i] = -1 * arr[i];
}

int main()
{
    vector<int> arr(100, 0);
    int n;
    int val;
    cin>>n>>val;
    
    fillArray(arr, 0, n, val);
    printArray(arr, n);

    return 0;
}