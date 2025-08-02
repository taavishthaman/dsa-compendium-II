#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int * arr, int n, int key) {
    if(n == 0) {
        return -1;
    }
    
    if(arr[0] == key) {
        return 0;
    }
    
    int index = firstOccurence(arr + 1, n - 1, key);
    if(index == -1) {
        return -1;
    }
    
    return index + 1;
}

int lastOccurence(int * arr, int n, int key) {
    if(n == 0) {
        return -1;
    }
    
    int subIndex = lastOccurence(arr + 1, n - 1, key);
    
    if(subIndex == -1) {
        if(arr[0] == key) {
            return 0;
        } else {
            return -1;
        }
    } else {
        return subIndex + 1;
    }
}

int main()
{
    int arr[] = {1,3,5,7,6,2,11,21,7,5,6,7,1};
    int key;
    cin>>key;
    int n = sizeof(arr) / sizeof(int);
    int result = firstOccurence(arr, n, key);
    cout<<"Result is..."<<result<<endl;
    int lastIndex = lastOccurence(arr, n, key);
    cout<<"Result is..."<<lastIndex<<endl;
    return 0;
}