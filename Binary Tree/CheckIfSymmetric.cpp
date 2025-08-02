#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node* left, *right;
};

bool checkIfSymmetric(Node * left, Node * right) {
    if(left == NULL && right == NULL) {
        return true;
    }
    
    if((left == NULL && right != NULL) || (left != NULL && right == NULL)) {
        return false;
    }
    
    if((left->key == right->key) && checkIfSymmetric(left->left, right->right) && checkIfSymmetric(left->right, right->left)) {
        return true;
    }
    
    return false;
}

bool isSymmetric(Node* root) {
    //your code goes here
    return checkIfSymmetric(root->left, root->right);
}