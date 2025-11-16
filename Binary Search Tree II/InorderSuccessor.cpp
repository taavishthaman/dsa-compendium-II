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

Node * inorderSuccessor(Node * root, Node * target) {
    
    //Case I: If right subtree exists for the target
    
    if(target->right != NULL) {
        Node * temp = target->right;
        
        while(temp->left != NULL) {
            temp = temp->left;
        }
        
        return temp;
    }
    
    //Case II: Target is a leaf node
    Node * curr = NULL;
    Node * temp = root;
    
    while(temp != NULL) {
        if(temp->data > target->data) {
            curr = temp;
            temp = temp->left;
        } else if(temp->data < target->data) {
            temp = temp->right;
        } else {
            break;
        }
    }
    
    return curr;
}

int main()
{
    vector<int> arr = {8,3,10,1,6,14,4,7,13};
    Node * root = NULL;
    
    for(int num : arr) {
        root = insertInBST(root, num);
    }
    
    Node * succ = inorderSuccessor(root, root->left->right->right);
    cout<<"Inorder Successor of 7 is "<<succ->data<<endl;
    succ = inorderSuccessor(root, root->right);
    cout<<"Inorder Successor of 10 is "<<succ->data<<endl;
    
    return 0;
}