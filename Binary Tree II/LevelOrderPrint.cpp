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

void levelOrderPrint(Node * root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        Node * n = q.front();
        if(n == NULL) {
            q.pop();
            if(!q.empty()) {
                cout<<endl;
                q.push(NULL);
            }
        } else {
            q.pop();
            cout<<n->data<<", ";
            if(n->left != NULL) {
                q.push(n->left);
            }
            if(n->right != NULL) {
                q.push(n->right);
            }
        }
    }
}

int main()
{
    //Input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    Node * root = buildTree();
    preorder(root);
    cout<<endl;
    levelOrderPrint(root);
    return 0;
}