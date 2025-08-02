#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int * arr = new int[n];
    
    for(int i=1; i<=n; i++) {
        arr[i-1] = i;
    }
    
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<", ";
    }
    
    delete [] arr; //Always delete dynamically allocated memory to avoid memory leaks
    
    cout<<arr<<endl; //The base address of the array will still be there because its statically allocated
    
    cout<<arr[5]<<endl; //The correct data may or may not be present, this behaviour is not predictable
}