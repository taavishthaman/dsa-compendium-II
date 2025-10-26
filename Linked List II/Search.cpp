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


bool isPresent(node * head, int key){
    //Complete this function 
    if(head == NULL) {
        return false;
    }
    
    bool found = isPresent(head->next, key);
    
    if(found == true) {
        return true;
    } else {
        if(head->data == key) {
            return true;
        } 
        
        return false;
    }
    
}