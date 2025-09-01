#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> & arr, int s, int e) {
    int m = (s + e) / 2;
    int i = s, j = m+1;
    vector<int> temp;
    int inversions = 0;
    
    while(i <= m && j <= e) {
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            inversions += (m-i+1);
        }
    }
    
    while(i <= m) {
        temp.push_back(arr[i]);
        i++;
    }
    
    while(j <= e) {
        temp.push_back(arr[j]);
        j++;
    }
    
    int k = 0;
    
    for(int i=s; i<=e; i++) {
        arr[i] = temp[k];
        k++;
    }
    
    return inversions;
}

int merge_sort(vector<int> & arr, int s, int e) {
    if(s >= e) return 0;
    
    int m = (s + e) / 2;
    int C1 = merge_sort(arr, s, m);
    int C2 = merge_sort(arr, m+1, e);
    int CI = merge(arr, s, e);
    return C1 + C2 + CI;
}

int main()
{
    vector<int> arr = {0,5,2,3,1};
    int inversions = merge_sort(arr, 0, arr.size()-1);
    
    cout<<"Inversions are "<<inversions<<endl;

    return 0;
}