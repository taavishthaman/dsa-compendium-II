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

void inorder(Node * root, vector<int> & nodes) {
    if(root == NULL) {
        return;
    }
    
    inorder(root->left, nodes);
    nodes.push_back(root->key);
    inorder(root->right, nodes);
}

bool isBST(Node * root){
    //complete this method
    
    vector<int> nodes;
    
    inorder(root, nodes);
    
    int n = nodes.size();
    
    for(int i=0; i < n-1; i++) {
        if(nodes[i] > nodes[i+1]) {
            return false;
        }
    }
    
    return true;
    
}
