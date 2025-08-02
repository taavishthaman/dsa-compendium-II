#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node* left, *right;
};

void removeNodes(Node * root, vector<int> & arr) {
    if(root == NULL) {
        return;
    }
    
    removeNodes(root->left, arr);
    if((root->left && root->right) || (root->left == NULL && root->right == NULL)) {
        arr.push_back(root->key);
    }
    removeNodes(root->right, arr);
}

vector<int> removeHalfNodes(Node *root)
{
   //add code here.
   vector<int> res;
   removeNodes(root, res);
   
   return res;
}