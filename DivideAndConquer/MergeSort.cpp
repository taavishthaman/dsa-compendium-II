#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> & arr, int s, int e) {
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    
    vector<int> temp;
    
    while(i <= mid && j <= e) {
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    
    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    
    while(j <= e) {
        temp.push_back(arr[j]);
        j++;
    }
    
    int k = 0;
    for(i = s; i <= e; i++) {
        arr[i] = temp[k];
        k++;
    }
}

void mergeSort(vector<int> & arr, int s, int e) {
    if(s >= e) return;
    
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, e);
}

int main()
{
    vector<int> arr = {10,9,8,7,6,5,4,3,2,1};
    mergeSort(arr, 0, arr.size() - 1);
    
    for(int num : arr) {
        cout<<num<<", ";
    }
    return 0;
}