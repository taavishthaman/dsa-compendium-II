#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;
   Node *parent;
};

Node* findInOrderSuccessor( Node *inputNode ){
    //Complete this Method, return the pointer to the inorder successor
    // HINT : Since the parent pointer is given, you can traverse upwards in the tree
    
    //Case 1: Right subtree exists
    if(inputNode->right != NULL) {
        Node * temp = inputNode->right;
        
        while(temp->left != NULL) {
            temp = temp->left;
        }
        
        return temp;
    }
    
    //Case 2: Right subtree does not exist
    Node * res = NULL;
    Node * temp = inputNode->parent;
    while(temp != NULL) {
        if(temp->key > inputNode->key) {
            return temp;
        }
        temp = temp->parent;
    }
    
    return res;
}