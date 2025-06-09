#include <bits/stdc++.h>
using namespace std;

void reverse_array_1(int * arr, int n) {
    int s = 0;
    int e = n - 1;
    
    while(s < e) {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

void reverse_array_2(int * arr, int n) {
    int s = 0;
    int m = n / 2;
    
    while(s < m) {
        swap(arr[s], arr[n-1-s]);
        s++;
    }
}

void printArray(int * arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

int main() {
    int arr[] = {10,20,30,40,50,60,70};
    int n = sizeof(arr) / sizeof(int);
    reverse_array_1(arr, n);
    
    printArray(arr, n);
    
    reverse_array_2(arr, n);
    printArray(arr, n);
    cout<<endl;
}