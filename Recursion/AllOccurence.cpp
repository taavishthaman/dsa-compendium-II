#include <bits/stdc++.h>
using namespace std;

void findOccurences(vector<int> & indices, vector<int> v,int k, int i) {
    if(i == v.size()) {
        return;
    }
    
    if(v[i] == k) {
        indices.push_back(i);
    }
    
    findOccurences(indices, v, k, i + 1);
}

vector<int> findAllOccurences(int k, vector<int> v){
    vector<int> indices;
    
    findOccurences(indices, v, k, 0);
    
    return indices;
}