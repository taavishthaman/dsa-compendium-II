#include<bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

node* alternateMerge(node * root1, node* root2){
    //Complete this function 
    node * ptr1 = root1;
    node * ptr2 = root2;
    
    node * newHead = new node(-1);
    node * dummy = newHead;
    
    while(ptr1 != NULL && ptr2 != NULL) {
        dummy->next = new node(ptr1->data);
        dummy = dummy->next;
        
        dummy->next = new node(ptr2->data);
        dummy = dummy->next;
        
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    while(ptr1 != NULL) {
        dummy->next = new node(ptr1->data);
        dummy = dummy->next;
        ptr1 = ptr1->next;
    }
    
    while(ptr2 != NULL) {
        dummy->next = new node(ptr2->data);
        dummy = dummy->next;
        ptr2 = ptr2->next;
    }
    
    return newHead->next;
}

