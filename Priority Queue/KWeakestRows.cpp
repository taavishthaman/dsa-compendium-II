#include<bits/stdc++.h>
using namespace std;

class Compare {
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        if(p1.first == p2.first) {
            return p1.second > p2.second;
        }
        
        return p1.first > p2.first;
    }
};


vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    // your code goes here 
    // Create a pair of <num of soldiers, row>
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
    
    int n = mat.size();
    
    for(int i=0; i<n; i++) {
        int soldiers = 0;
        for(int num : mat[i]) {
            if(num == 1) {
                soldiers += 1;
            }
        }
        
        pair<int, int> p = {soldiers, i};
        q.push(p);
    }
    
    vector<int> res;
    
    while(k > 0) {
        pair<int, int> curr = q.top();
        q.pop();
        res.push_back(curr.second);
        k--;
    }
    
    return res;
}

