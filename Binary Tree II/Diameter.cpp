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

Node * levelOrderBuild() {
    int d;
    cin>>d;
    
    queue<Node*> q;
    Node * root = new Node(d);
    
    q.push(root);
    
    while(!q.empty()) {
        Node * f = q.front();
        q.pop();
        
        int d1, d2;
        cin>>d1>>d2;
        
        if(d1 != -1) {
            f->left = new Node(d1);
            q.push(f->left);
        }
        if(d2 != -1) {
            f->right = new Node(d2);
            q.push(f->right);
        }
    }
    
    return root;
}

int height(Node * root) {
    if(root == NULL) {
        return 0;
    }
    
    int left = height(root->left);
    int right = height(root->right);
    
    return 1 + max(left, right);
}

int diameter(Node * root) {
    if(root == NULL) {
        return 0;
    }
    
    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);
    
    return max({D1, D2, D3});
}

int main()
{
    //Input Preorder : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    //Input Levelorder : 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
    Node * root = buildTree();
    preorder(root);
    cout<<endl;
    levelOrderPrint(root);
    cout<<endl;
    Node * root2 = levelOrderBuild();
    levelOrderPrint(root2);
    cout<<endl;
    int d = diameter(root);
    cout<<"Diameter is "<<d<<endl;
    return 0;
}