#include <bits/stdc++.h>
using namespace std;

pair<int, int> staircaseSearch(int arr[][10], int n, int m, int target) {
    
    if(target < arr[0][0] || target > arr[n-1][m-1]) {
        return {-1, -1};
    }
    
    int i = 0;
    int j = n-1;
    
    while(i < n && j >= 0) {
        if(arr[i][j] == target) {
            return {i, j};
        }
        else if(target < arr[i][j]) {
            j--;
        } else {
            i++;
        }
    }
    
    return {-1, -1};
}

int main()
{
    int arr[][10] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };
    
    int n = 4, m = 4;
    
    int target;
    cin>>target;
    
    pair<int, int> res = staircaseSearch(arr, n, m, target);
    
    cout<<"Coords ("<<res.first<<", "<<res.second<<")"<<endl;

    return 0;
}