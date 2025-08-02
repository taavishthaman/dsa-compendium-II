#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {10,5,7,11,12,15,21};
    
    int key = 12;
    
    vector<int>::iterator it = find(arr.begin(), arr.end(), key);
    if(it == arr.end()) {
        cout<<"Element is not found!"<<endl;
    } else {
        cout<<"Index of target "<<(it-arr.begin())<<endl;
    }
}