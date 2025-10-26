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
    
    void insertAtTail(int data) {
        Node * n = new Node(data);
        
        if(head == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
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

Node * findMid(Node * head) {
    Node * slow = head;
    Node * fast = head;
    
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

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

Node * mergeSort(Node * head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    Node * mid = findMid(head);
    Node * h1 = head;
    Node * h2 = mid->next;
    mid->next = NULL;
    h1 = mergeSort(h1);
    h2 = mergeSort(h2);
    return merge(h1, h2);
    
}

int main()
{
   LinkedList ll;
   
   ll.insertAtTail(14);
   ll.insertAtTail(2);
   ll.insertAtTail(17);
   ll.insertAtTail(1);
   ll.insertAtTail(5);
   ll.insertAtTail(7);
   ll.insertAtTail(10);
   
   Node * nHead = mergeSort(ll.head);
   Node * temp = nHead;
   
   while(temp != NULL) {
       cout<<temp->data<<"-->";
       temp = temp->next;
   }
}