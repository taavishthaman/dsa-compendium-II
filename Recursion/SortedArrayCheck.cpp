#include <bits/stdc++.h>
using namespace std;

bool isSorted(int * arr, int n) {
    if(n == 0 || n == 1) {
        return true;
    }
    
    if(arr[0] < arr[1] && isSorted(arr + 1, n-1)) {
        return true;
    }
    
    return false;
}

int main()
{
   int arr[5] = {1, 2, 4, 8, 5};
   int n = sizeof(arr) / sizeof(int);
   
   bool result = isSorted(arr, n);
   if(result == true) {
        cout<<"Array is sorted!"<<endl;
   } else {
       cout<<"Array is not sorted"<<endl;
   }

    return 0;
}