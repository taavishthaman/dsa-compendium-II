#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> & arr, int s, int e) {
    int m = (s + e) / 2;
    int i = s, j = m+1;
    
    vector<int> temp;
    
    while(i <= m && j <= e) {
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    
    while(i <= m) {
        temp.push_back(arr[i]);
        i++;
    }
    
    while(j <= e) {
        temp.push_back(arr[j]);
        j++;
    }
    
    int k = 0;
    
    for(int i=s; i<=e; i++) {
        arr[i] = temp[k];
        k++;
    }
}

void merge_sort(vector<int> & arr, int s, int e) {
    if(s >= e) return;
    
    int m = (s + e) / 2;
    
    merge_sort(arr, s, m);
    merge_sort(arr, m+1, e);
    merge(arr, s, e);
}

int main()
{
    vector<int> arr = {8,7,6,5,4,3,2,1};
    
    merge_sort(arr, 0, arr.size() - 1);
    
    for(int num : arr) {
        cout<<num<<", ";
    }
}