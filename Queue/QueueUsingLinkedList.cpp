#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node * next;
    
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
    Node * head;
    Node * tail;
public:
    Queue() {
        head = tail = NULL;
    }
    
    void push(int data) {
        Node * n = new Node(data);
        if(head == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }
    
    void pop() {
        Node * temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    
    int front() {
        return head->data;
    }
    
    bool empty() {
        return head == NULL;
    }
};

int main() {
    Queue q;
    
    for(int i=1; i<=5; i++) {
        q.push(i);
    }
    
    while(!q.empty()) {
        cout<<q.front()<<", ";
        q.pop();
    }
}