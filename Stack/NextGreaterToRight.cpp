#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> v){
    vector<int> op;
    stack<int> s;
    
    op.push_back(-1);
    s.push(v.size() - 1);
    int n = v.size();
    
    for(int i = n-2; i >= 0; i--) {
        int curr = v[i];
        
        while(!s.empty() && curr >= v[s.top()]) {
            s.pop();
        }
        
        if(s.empty()) {
            op.insert(op.begin(), -1);
        } else {
            op.insert(op.begin(), v[s.top()]);
        }
        
        s.push(i);
    }
    
    return op;
}