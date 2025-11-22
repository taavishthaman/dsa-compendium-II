#include<bits/stdc++.h>
using namespace std;

class node{
public:  
  int data;
  node * next;
  
  node(int data){
      this->data = data;
  }
};


 node * breakChain(node * head){
     //Complete this method
     set<node*> s;
     
     node * temp = head;
     
     while(temp != NULL) {
         if(s.find(temp->next) != s.end()) {
             temp->next = NULL;
             return head;
         }
         s.insert(temp);
         temp = temp->next;
     }
     
     return head;
 }


