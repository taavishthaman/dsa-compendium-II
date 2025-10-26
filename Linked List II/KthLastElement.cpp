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

int kthLastElement(node *head, int k){
    //Complete this function to return kth last element
    int steps = 1;
    
    node * ptr1 = head;
    node * ptr2 = head;
    
    
    while(steps <= k) {
        ptr1 = ptr1->next;
        steps++;
    }
    
    while(ptr1 != NULL) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return ptr2->data;
}