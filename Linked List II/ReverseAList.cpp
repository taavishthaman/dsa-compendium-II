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
    
    ~Node() {
        if(next != NULL) {
            delete next;
        }
    }
};

class LinkedList {
    Node * head;
    Node * tail;
    
public:
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
    
    Node * recursiveReverse(Node * head) {
        if(head->next == NULL || head == NULL) {
            return head;
        }
        
        Node * nHead = recursiveReverse(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return nHead;
    }
    
    void recursiveReverse() {
        Node * newHead = recursiveReverse(head);
        tail = head;
        head = newHead;
    }
    
    void reverse() {
        tail = head;
        Node * prev = NULL;
        Node * curr = head;
        Node * next = NULL;
        
        while(curr != NULL) {
            next = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
    }
    
    void print() {
        Node * temp = head;
        
        while(temp != NULL) {
            cout<<temp->data<<"-->";
            temp = temp->next;
        }
        cout<<endl;
    }
    
    ~LinkedList() {
        if(head != NULL) {
            delete head;
            head = NULL;
        }
    }
};

int main()
{
    LinkedList ll;
    
    for(int i=1; i<=5; i++) {
        ll.insertAtTail(i);
    }
    
    for(int i=6; i<=7; i++) {
        ll.insertAtHead(i);
    }
    
    ll.print();
    
    ll.insertInMiddle(100,3);
    ll.print();
    
    ll.recursiveReverse();
    ll.print();
    
    ll.reverse();
    ll.print();
    return 0;
}