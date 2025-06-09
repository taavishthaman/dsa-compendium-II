#include <bits/stdc++.h>
using namespace std;

void printArray(int * arr, int n) {
    arr[0] = 100; //This will update in main too, since array is being passed by reference
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

int main() {
   int arr[6] = {1,2,3,4,5,6};
   
   cout<<"Size in Main "<<sizeof(arr)<<endl;
   int n = sizeof(arr) / sizeof(int);
   
   printArray(arr, n);
   
   for(int i = 0; i < n; i++) {
       cout<<arr[i]<<", ";
   }
}