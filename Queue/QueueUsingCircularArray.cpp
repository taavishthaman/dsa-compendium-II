#include<bits/stdc++.h>
using namespace std;

class Queue {
    int * arr;
    int cs;
    int ms;
    int front;
    int rear;
    
public:

    Queue(int default_size = 5) {
        ms = default_size;
        cs = 0;
        arr = new int[ms];
        front = 0;
        rear = ms - 1;
    }
    
    bool full() {
        return cs == ms;
    }
    
    bool empty() {
        return cs == 0;
    }
    
    void push(int data) {
        if(!full()) {
            rear = (rear + 1) % ms;
            arr[rear] = data;
            cs++;
        }
    }
    
    void pop() {
        if(!empty()) {
            front = (front + 1) % ms;
            cs--;
        }
    }
    
    int getFront() {
        return arr[front];
    }
    
};

int main() {
    Queue q(7);
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    
    q.pop();
    q.pop();
    q.push(9);
    
    while(!q.empty()) {
        cout<<q.getFront()<<", ";
        q.pop();
    }
}