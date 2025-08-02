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
    
    ~Node() {
        if(next != NULL) {
            delete next;
        }
        cout<<"Deleting node with data "<<data<<endl;
    }
};

class LinkedList {
    Node * head;
    Node * tail;
    
    bool searchRecursive(Node * node, int data) {
        if(node == NULL) {
            return false;
        }
        
        if(data == node->data) return true;
        
        return searchRecursive(node->next, data);
    }
    
    int findIndex(Node * node, int data) {
        if(node == NULL) {
            return -1;
        }
        
        int subIndex = findIndex(node->next, data);
        
        if(subIndex == -1) {
            if(node->data == data) {
                return 0;
            } else {
                return -1;
            }
        }
        
        return subIndex + 1;
    }
    
    Node * reverseList(Node * head) {
        Node * prev = NULL;
        Node * curr = head;
        Node * next = NULL;
        
        while(curr != NULL) {
            next = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    } 
    
public:
    LinkedList() {
        head = tail = NULL;
    }
    
    void push_front(int data) {
        Node * n = new Node(data);
        if(head == NULL) {
            head = tail = n;
        } else {
            n->next = head;
            head = n;
        }
    }
    
    void push_back(int data) {
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
            push_front(data);
        } else {
            Node * temp = head;
            
            for(int i=0; i<pos-1; i++) {
                temp = temp->next;
            }
            
            Node * n = new Node(data);
            n->next = temp->next;
            temp->next = n;
        }
    }
    
    int search(int data) {
        Node * temp = head;
        int index = 0;
        
        while(temp != NULL) {
            if(temp->data == data) return index;
            
            index++;
            temp = temp->next;
        }
        
        return -1;
    }
    
    bool searchRecursive(int data) {
        return searchRecursive(head, data);
    }
    
    int findIndex(int data) {
        return findIndex(head, data);
    }
    
    void pop_front() {
        Node * temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    
    void pop_back() {
        Node * temp = head;
        
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        
        Node * n = temp->next;
        temp->next = NULL;
        delete n;
    }
    
    void remove(int pos) {
        Node * temp = head;
        
        for(int i=0; i<pos-1; i++) {
            temp = temp->next;
        }
        
        Node * n = temp->next;
        temp->next = temp->next->next;
        n->next = NULL;
        delete n;
    }
    
    void print() {
        Node * temp = head;
        
        while(temp != NULL) {
            cout<<temp->data<<"=>";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
    
    void reverseList() {
        Node * newHead = reverseList(head);
        head = newHead;
    }
    
    ~LinkedList() {
        if(head != NULL) {
            delete head;
            head = NULL;
        }
    }
};

int main() {
    LinkedList ll;
    
    for(int i = 1; i <= 5; i++) {
        ll.push_back(i);
    }
    
    for(int i=6; i<=7; i++) {
        ll.push_front(i);
    }
    
    ll.insert(69, 2);
    
    int index = ll.search(8);
    cout<<"Index is "<<index<<endl;
    
    bool found = ll.searchRecursive(3);
    if(found) {
        cout<<"Node was found"<<endl;
    } else {
        cout<<"Node was not found"<<endl;
    }
    
    index = ll.findIndex(1);
    if(index == -1) {
        cout<<"Target was not found!"<<endl;
    } else {
        cout<<"Target was found at index "<<index<<endl;
    }
    
    ll.pop_front();
    ll.pop_back();
    ll.remove(2);
    ll.print();
    ll.reverseList();
    
    ll.print();
}