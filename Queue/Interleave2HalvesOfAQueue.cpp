#include <bits/stdc++.h>
using namespace std;

queue<int> interLeave(queue<int> q){
    int n = q.size();
    queue<int> q2;
    
    while(q2.size() != n / 2) {
        q2.push(q.front());
        q.pop();
    }
    
    queue<int> op;
    
    while(!q.empty() && !q2.empty()) {
        op.push(q2.front());
        q2.pop();
        op.push(q.front());
        q.pop();
    }
    
    while(!q.empty()) {
        op.push(q.front());
        q.pop();
    }
    
    while(!q2.empty()) {
        op.push(q2.front());
        q2.pop();
    }
    
    return op;
}