#include<bits/stdc++.h>
using namespace std;

int pairSticks(vector<int> length, int D)
{
    // your code goes here
    sort(length.begin(), length.end());
    int n = length.size();
    int count = 0;
    
    for(int i=0; i < n-1; i++) {
        if(length[i] == -1) continue;
        for(int j=i+1; j<n; j++) {
            if(length[j] == -1) continue;
            if(length[j] - length[i] <= D) {
                count++;
                length[i] = -1;
                length[j] = -1;
                break;
            }
        }
    }
    
    return count;
    
}