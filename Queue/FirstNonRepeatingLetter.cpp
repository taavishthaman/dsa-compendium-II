#include <bits/stdc++.h>
using namespace std;

vector<char> firstnonrepeating(vector<char> str){
    int n = str.size();
    
    unordered_map<char, int> frq_map;
    vector<char> op;
    queue<char> q;
    
    for(int i=0; i < n; i++) {
        char ch = str[i];
        frq_map[ch]++;
        q.push(ch);
        
        while(!q.empty() && frq_map[ch] != 1) {
            q.pop();
        }
        
        if(q.empty()) {
            op.push_back('0');
        } else {
            op.push_back(q.front());
        }
    }
    
    return op;
}