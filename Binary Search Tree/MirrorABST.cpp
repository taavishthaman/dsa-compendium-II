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

Node* mirrorBST(Node * root){
    //complete this method
    if(root == NULL) {
        return NULL;
    }
    
    Node * temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    return root;
    
}
