#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> arr = {
        {1,2,3},
        {4,5,6,7},
        {8,9,10},
        {11,12}
    };
    
    int rows = arr.size();
    
    for(int i=0; i<rows; i++) {
        for(int j=0; j<arr[i].size(); j++) {
            cout<<arr[i][j]<<", ";
        }
        cout<<endl;
    }

    return 0;
}