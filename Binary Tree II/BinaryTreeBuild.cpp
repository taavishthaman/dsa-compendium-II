#include <bits/stdc++.h>
using namespace std;

class Node {
    
public:
    int data;
    Node * left;
    Node * right;
    
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};


Node * buildTree() {
    int d;
    cin>>d;
    
    if(d == -1) {
        return NULL;
    }
    
    Node * n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void preorder(Node * root) {
    if(root == NULL) return;
    
    cout<<root->data<<", ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    //Input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    Node * root = buildTree();
    preorder(root);
    return 0;
}