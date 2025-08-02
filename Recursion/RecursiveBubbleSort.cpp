#include <bits/stdc++.h>
using namespace std;

void bubbleSortRec(int * arr, int n) {
    if(n == 1) {
        return;
    }
    
    for(int i=0; i<n-1; i++) {
        if(arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }
    
    bubbleSortRec(arr, n-1);
}

//Fully recursive solution
void bubbleSortFullRec(int * arr, int n, int i) {
    if(n == 1) {
        return;
    }
    
    if(i == n-1) {
        bubbleSortFullRec(arr, n-1, 0);
        return;
    }
    
    if(arr[i] > arr[i+1]) {
        swap(arr[i], arr[i+1]);
    }
    
    bubbleSortFullRec(arr, n, i+1);
}

int main() {
    int arr[8] = {-10, 7, -11, 2, 3, 1, -3, 5};
    
    int n = sizeof(arr) / sizeof(int);
    
    //bubbleSortRec(arr, n);
    bubbleSortFullRec(arr, n, 0);
    
    for(int num : arr) {
        cout<<num<<", ";
    }
}