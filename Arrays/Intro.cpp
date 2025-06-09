#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[100] = {1,2,3};
    int n = sizeof(arr) / sizeof(int);
    
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<", ";
    }

    return 0;
}