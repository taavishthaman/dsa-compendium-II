#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> & arr) {
    int n = arr.size();
    
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void merge(vector<int> & arr, int s, int e) {
    int m = (s + e) / 2;
    
    vector<int> temp;
    
    int i = s;
    int j = m + 1;
    
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
    
    j = 0;
    for(i = s; i <= e; i++) {
        arr[i] = temp[j];
        j++;
    }
}

void merge_sort(vector<int> & arr, int s, int e) {
    if(s >= e) return;
    
    int m = (s + e) / 2;
    
    merge_sort(arr, s, m);
    merge_sort(arr, m+1, e);
    merge(arr, s, e);
}

vector<int> generate_array(int n) {
    vector<int> arr;
    
    for(int i=n; i >= 1; i--) {
        arr.push_back(i);
    }
    
    return arr;
}

int main()
{
    int n;
    cin>>n;
    
    vector<int> arr = generate_array(n);
    
    auto start_time = clock();
    merge_sort(arr, 0, arr.size() - 1);
    auto end_time = clock();
    
    cout<<"Total time for merge sort "<<(end_time - start_time)<<endl;
    
    arr = generate_array(n);
    
    start_time = clock();
    bubble_sort(arr);
    end_time = clock();
    
    cout<<"Total time for bubble sort "<<(end_time - start_time)<<endl;

    return 0;
}