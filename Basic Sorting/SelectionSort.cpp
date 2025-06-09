#include <bits/stdc++.h>
using namespace std;
//Pick the first element, find the minimum element in the rest of array, replace with the current element

void selectionSort(vector<int> & v) {
    int n = v.size();
    
    for(int i=0; i<n-1; i++) {
        int min_element = v[i];
        int min_index = i;
        for(int j=i+1; j<n; j++) {
            if(v[j] < min_element) {
                min_element = v[j];
                min_index = j;
            }
        }
        
        swap(v[min_index], v[i]);
    }
}

int main()
{
    vector<int> v = {-2,3,4,-1,5,-12,6,1,3};
    
    selectionSort(v);
    
    for(int num : v) {
        cout<<num<<", ";
    }

    return 0;
}