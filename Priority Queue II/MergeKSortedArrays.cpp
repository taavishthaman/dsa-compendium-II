#include <bits/stdc++.h>
using namespace std;

class Compare {
public:
    bool operator()(vector<int> v1, vector<int> v2) {
        return v1[0] > v2[0];
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> arr) {
    int n = arr.size();
    
    priority_queue<vector<int>, vector<vector<int>>, Compare> heap;
    
    for(int i=0; i<n; i++) {
        heap.push({arr[i][0], i, 0});
    }
    
    vector<int> op;
    
    while(!heap.empty()) {
        vector<int> top = heap.top();
        heap.pop();
        
        int element = top[0];
        int a_idx = top[1];
        int e_idx = top[2];
        
        op.push_back(element);
        
        if(e_idx + 1 < arr[a_idx].size()) {
            heap.push({arr[a_idx][e_idx + 1], a_idx, e_idx + 1});
        }
    }
    
    return op;
}

int main()
{
    vector<vector<int>> arr = {
        {10,15,20,30},
        {2,5,8,14,24},
        {0,11,60,90}
    };
    
    vector<int> op = mergeKSortedArrays(arr);
    
    for(int num : op) {
        cout<<num<<" ";
    }

    return 0;
}