#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node * next;
    
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Stack{
public:
    Node * head;
    Stack() {
        head = NULL;
    }
    
    void push(int data) {
        Node * n = new Node(data);
        n->next = head;
        head = n;
    }
    
    bool empty() {
        return head == NULL;
    }
    
    int top() {
        return head->data;
    }
    
    void pop() {
        if(head != NULL) {
            Node * temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }
};

int main()
{
    Stack s;
    
    for(int i=1; i<=5; i++) {
        s.push(i);
    }
    
    while(!s.empty()) {
        cout<<s.top()<<", ";
        s.pop();
    }
    return 0;
}