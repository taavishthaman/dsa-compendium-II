#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};

bool isBST(Node * root, int min_value, int max_value) {
    if(root == NULL) {
        return true;
    }
    
    if(root->key < min_value || root->key > max_value) {
        return false;
    }
    
    return isBST(root->left, min_value, root->key) && isBST(root->right, root->key, max_value);
}

bool isBST(Node * root){
    //complete this method
    return isBST(root, INT_MIN, INT_MAX);
}
