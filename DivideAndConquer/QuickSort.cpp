#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> & arr, int s, int e) {
    int pivot = arr[e];
    int i = s - 1;
    for(int j=s; j<e; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    i++;
    swap(arr[i], arr[e]);
    return i;
}

void quick_sort(vector<int> & arr, int s, int e) {
    if(s >= e) return;
    
    int pIndex = partition(arr, s, e);
    quick_sort(arr, s, pIndex-1);
    quick_sort(arr, pIndex+1, e);
}

int main()
{
    vector<int> arr = {10,9,8,7,6,5,4,3,2,1};
    quick_sort(arr, 0, arr.size() - 1);
    
    for(int num : arr) {
        cout<<num<<", ";
    }
    return 0;
}