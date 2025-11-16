#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node * left;
    Node * right;
    
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node * insertInBST(Node * root, int data) {
    if(root == NULL) {
        Node * n = new Node(data);
        return n;
    }
    
    if(data < root->data) {
        root->left = insertInBST(root->left, data);
    } else {
        root->right = insertInBST(root->right, data);
    }
    
    return root;
}

void inorder(Node * root) {
    if(root == NULL) {
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node * buildTree() {
    vector<int> arr = {8,3,10,1,6,14,4,7,13};
    Node * root = NULL;
    for(int data : arr) {
        root = insertInBST(root, data);
    }
    return root;
}

int main()
{
    Node * root = buildTree();
    inorder(root);
    return 0;
}