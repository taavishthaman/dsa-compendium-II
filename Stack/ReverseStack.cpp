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


//1. Pop the top element
//2. Reverse the rest of stack
//3. Insert the top element at bottom
void reverse(stack<int> & s) {
    if(s.empty()) {
        return;
    }
    
    int curr = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, curr);
}

int main() {
    stack<int> s;
    
    for(int i=1; i<=6; i++) {
        s.push(i);
    }
    
    insertAtBottom(s, 10);
    
    reverse(s);
    
    while(!s.empty()) {
        cout<<s.top()<<", ";
        s.pop();
    }
    
}