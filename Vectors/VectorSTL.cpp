#include <bits/stdc++.h>
using namespace std;

int main()
{
    //vector<int> arr = {1,2,10,12,15};
    
    //Fill Constructor
    vector<int> arr(10, 7);
    
    arr.pop_back();
    arr.push_back(16);
    int n = arr.size();
    
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<", ";
    }
    cout<<endl;
    
    cout<<"Size: "<<arr.size()<<endl;
    cout<<"Capacity: "<<arr.capacity()<<endl;

    return 0;
}