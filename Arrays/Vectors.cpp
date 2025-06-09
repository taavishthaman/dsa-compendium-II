#include <bits/stdc++.h>
using namespace std;

int main() {
    //vector<int> arr = {1,2,10,12,15};
    vector<int> arr(10, 7); //Fill constructor initialization
    arr.pop_back();
    arr.push_back(16);
    
    cout<<"Size of vector "<<arr.size()<<endl;
    
    cout<<"Capacity of vector "<<arr.capacity()<<endl;
    
    for(int num : arr) {
        cout<<num<<", ";
    }
}