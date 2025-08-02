#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> & s, int data) {
    if(s.size() == 0) {
        s.push(data);
        return;
    }
    
    int curr = s.top();
    s.pop();
    insertAtBottom(s, data);
    s.push(curr);
}

int main() {
    stack<int> s;
    
    for(int i=1; i<=6; i++) {
        s.push(i);
    }
    
    insertAtBottom(s, 10);
    
    while(!s.empty()) {
        cout<<s.top()<<", ";
        s.pop();
    }
    
}