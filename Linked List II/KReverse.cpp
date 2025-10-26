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

class LinkedList {
public:
    Node * head;
    Node * tail;
    
    LinkedList() {
        head = tail = NULL;
    }
    
    void insertAtHead(int data) {
        Node * n = new Node(data);
        if(head == NULL) {
            head = tail = n;
        } else {
            n->next = head;
            head = n;
        }
    }
    
    void insertAtTail(int data) {
        Node * n = new Node(data);
        if(head == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = tail->next;
        }
    }
    
    void insert(int data, int pos) {
        if(pos == 0) {
            insertAtHead(data);
            return;
        } 
        
        Node * temp = head;
        
        for(int jump = 1; jump <= pos-1; jump++) {
            temp = temp->next;
        }
        
        Node * n = new Node(data);
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
    
    Node * recursiveReverse(Node * head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        Node * sHead = recursiveReverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return sHead;
    }
    
    void recursiveReverse() {
        Node * newHead = recursiveReverse(head);
        head = newHead;
    }
    
    void reverse() {
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
    
    Node * kReverse(Node * head, int k) {
        if(head == NULL) {
            return NULL;
        }
        
        Node * prev = NULL;
        Node * curr = head;
        Node * next = NULL;
        
        int cnt = 1;
        
        while(curr != NULL && cnt <= k) {
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
            cnt++;
        }
        
        if(curr != NULL) {
            head->next = kReverse(curr, k);
        }
        
        return prev;
    }
    
    void kReverse(int k) {
        Node * newHead = kReverse(head, k);
        head = newHead;
    }
};

int main()
{
    LinkedList ll;
    
    ll.insertAtHead(5);
    ll.insertAtHead(6);
    
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    
    ll.insert(100, 3);
    
    ll.insertAtTail(30);
    
    ll.recursiveReverse();
    
    ll.print();
    
    ll.reverse();
    ll.print();
    
    ll.kReverse(3);
    ll.print();
    return 0;
}