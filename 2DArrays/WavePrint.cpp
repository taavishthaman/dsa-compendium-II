#include <bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
 
vector<int> WavePrint(int m, int n, vector<vector<int>> arr)
{
    // your code goes here
    string dir = "down";
    vector<int> op;
    
    for(int i = n-1; i >= 0; i--) {
        if(dir == "down") {
            for(int j=0; j < m; j++) {
                op.push_back(arr[j][i]);
            }
            dir = "up";
        } else {
            for(int j=m-1; j>=0; j--) {
                op.push_back(arr[j][i]);
            }
            dir = "down";
        }
    }
    
    return op;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {12, 13, 14, 5},
        {11, 16, 15, 6},
        {10, 9, 8, 7}
    };
    
    int n = 4, m = 4;
    
    vector<int> op = WavePrint(n, m, arr);
    
    for(int num : op) {
        cout<<num<<", ";
    }
    
    return 0;
}