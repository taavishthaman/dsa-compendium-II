#include<bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int> v1, vector<int> v2){
    //Write your code here. Do not modify the function or the parameters. You can use helper function if needed.
    unordered_set<int> s;
    vector<int> op;
    
    for(int num : v1) {
        s.insert(num);
    }
    
    for(int num : v2) {
        if(s.find(num) != s.end()) {
            op.push_back(num);
        }
    }
    
    sort(op.begin(), op.end());
    return op;
}