#include <bits/stdc++.h>
using namespace std;

void subsets(vector<int> & nums, vector<int> v, int i, vector<vector<int>> & op) {
    if(i == nums.size()) {
        op.push_back(v);
        return;
    }
    
    int first_element = nums[i];
    v.push_back(first_element);
    subsets(nums, v, i+1, op);
    v.pop_back();
    subsets(nums, v, i+1, op);
}

vector<vector<int>> uniqueSubsets(vector<int> nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> op;
    vector<int> v;
    subsets(nums, v, 0, op);
    
    set<vector<int>> collection;
    
    for(auto vec : op) {
        collection.insert(vec);
    }
    
    vector<vector<int>> res;
    for(auto vec : collection) {
        res.push_back(vec);
    }
    
    return res;
}

int main() {
    vector<int> arr = {1,2,2};
    
    vector<vector<int>> res = uniqueSubsets(arr);
    
    for(auto v : res) {
        for(int num : v) {
            cout<<num<<", ";
        }
        cout<<endl;
    }
}