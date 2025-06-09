#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> & v) {
    int n = v.size();
    
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-1-i; j++) {
            if(v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
            }
        }
    }
}

int main()
{
    vector<int> v = {-2,3,4,-1,5,-12,6,1,3};
    
    bubbleSort(v);
    
    for(int num : v) {
        cout<<num<<", ";
    }
    return 0;
}