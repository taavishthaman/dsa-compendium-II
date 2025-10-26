#include <bits/stdc++.h>
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

class LinkedList {
public:
    Node * head;
    Node * tail;
    
    LinkedList() {
        head = tail = NULL;
    }
    
    void insertAtHead(int key) {
        Node * n = new Node(key);
        if(head == NULL) {
            head = tail = n;
        } else {
            n->next = head;
            head = n;
        }
    }
    
    void insertAtTail(int key) {
        Node * n = new Node(key);
        
        if(head == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    } 
    
    void insertInMiddle(int key, int pos) {
        if(pos == 0) {
            insertAtHead(key);
            return;
        }
        
        Node * temp = head;
        for(int jump=1; jump<=pos-1; jump++) {
            temp = temp->next;
        }
        
        Node * n = new Node(key);
        n->next = temp->next;
        temp->next = n;
    }
    
    void print() {
        Node * temp = head;
        
        while(temp != NULL) {
            cout<<temp->data<<"-->";
            temp = temp->next;
        }
        cout<<endl;
    }
};

Node * merge(Node * head1, Node * head2) {
    if(head1 == NULL) {
        return head2;
    }
    if(head2 == NULL) {
        return head1;
    }
    
    Node * nHead;
    
    if(head1->data < head2->data) {
        nHead = head1;
        nHead->next = merge(head1->next, head2);
    } else {
        nHead = head2;
        nHead->next = merge(head1, head2->next);
    }
    
    return nHead;
}

int main()
{
    LinkedList ll1, ll2;
    
    ll1.insertAtTail(1);
    ll1.insertAtTail(5);
    ll1.insertAtTail(7);
    ll1.insertAtTail(10);
    
    ll2.insertAtTail(2);
    ll2.insertAtTail(3);
    ll2.insertAtTail(6);
    
    Node * nHead = merge(ll1.head, ll2.head);
    
    Node * temp = nHead;
    
    while(temp != NULL) {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
}