#include <bits/stdc++.h>
using namespace std;
//5,7,8   6 (Insert 6 at the correct position, similar to playing cards)

void insertionSort(vector<int> & v) {
    int n = v.size();
    
    for(int i=1; i<n; i++) {
        int curr = v[i];
        int prev = i - 1;
        
        while(prev >= 0 && v[prev] > curr) {
            v[prev + 1] = v[prev];
            prev--;
        }
        
        v[prev + 1] = curr;
    }
}

int main()
{
    vector<int> v = {-2,3,4,-1,5,-12,6,1,3};
    
    insertionSort(v);
    
    for(int num : v) {
        cout<<num<<", ";
    }

    return 0;
}