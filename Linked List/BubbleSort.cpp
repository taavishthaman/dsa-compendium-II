#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
 

node* bubble_sort_LinkedList_itr(node* head)
{
    // your code goes here
    
    int n = 0;
    node * temp = head;
    
    while(temp != NULL) {
        temp = temp->next;
        n++;
    }
    
    int j = 0;
    for(int i=0; i < n-1; i++) {
        temp = head;
        j = 0;
        while(j < n-i-1) {
            if(temp->data > temp->next->data) {
                swap(temp->data, temp->next->data);
                temp = temp->next;
                j++;
            }
        }
    }
    
    return head;
}
 
