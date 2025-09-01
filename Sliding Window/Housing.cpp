#include <bits/stdc++.h>
using namespace std;

void housing(vector<int> plots, int k) {
    int i = 0, j = 0, cs = 0;
    int n = plots.size();
    
    while(j < n) {
        cs += plots[j];
        j++;
        
        while(cs > k && i < j) {
            cs -= plots[i];
            i++;
        }
        
        if(cs == k) {
            cout<<i<<" - "<<j-1<<endl;
        }
    }
}

int main()
{
    vector<int> plots = {1,3,2,1,4,1,3,2,1,1};
    int k = 8;
    
    housing(plots, k);
    return 0;
}