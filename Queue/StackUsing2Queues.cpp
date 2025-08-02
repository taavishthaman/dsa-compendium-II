#include <bits/stdc++.h>
using namespace std;

//Stack using 2 queues
class Stack{
public:
    queue<int> q1, q2;
    
    void push(int data) {
        if(q1.empty()) {
            q2.push(data);
        } else {
            q1.push(data);
        }
    }
    
    void pop() {
        if(q1.empty()) {
            while(q2.size() != 1) {
                int data = q2.front();
                q2.pop();
                q1.push(data);
            }
            q2.pop();
        } else {
            while(q1.size() != 1) {
                int data = q1.front();
                q1.pop();
                q2.push(data);
            }
            q1.pop();
        }
    }
    
    int top() {
        if(q1.empty()) {
            while(q2.size() != 1) {
                int data = q2.front();
                q2.pop();
                q1.push(data);
            }
            int front = q2.front();
            q2.pop();
            q1.push(front);
            return front;
        } else {
            while(q1.size() != 1) {
                int data = q1.front();
                q1.pop();
                q2.push(data);
            }
            int front = q1.front();
            q1.pop();
            q2.push(front);
            return front;
        }
    }
    
    bool empty() {
        return q1.size() == 0 && q2.size() == 0;
    }
};

int main() {
    Stack s;
    
    for(int i=0; i<=5; i++) {
        s.push(i);
    }
    
    while(!s.empty()) {
        int t = s.top();
        s.pop();
        cout<<t<<", ";
    }
}