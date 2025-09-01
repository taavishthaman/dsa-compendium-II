#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> & arr, int s, int e) {
    int pivot = arr[e];
    
    int i = s-1;
    
    for(int j=s; j<e; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i+1], arr[e]);
    return i+1;
}

void quick_sort(vector<int> & arr, int s, int e) {
    if(s >= e) {
        return;
    }
    
    int p = partition(arr, s, e);
    quick_sort(arr, s, p-1);
    quick_sort(arr, p+1, e);
}

int main()
{
    vector<int> arr = {10,5,2,0,7,6,4};
    int n = arr.size();
    
    quick_sort(arr, 0, n-1);
    
    for(int num : arr) {
        cout<<num<<", ";
    }
    
    return 0;
}