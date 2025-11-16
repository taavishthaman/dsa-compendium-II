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

class LinkedList {
public:
    Node * head;
    Node * tail;
};

LinkedList tree2LL(Node * root) {
    LinkedList l;
    if(root == NULL) {
        l.head = l.tail = NULL;
        return l;
    }
    
    //4 cases
    if(root->left == NULL && root->right == NULL) {
        l.head = l.tail = root;
    } else if (root->left != NULL && root->right == NULL) {
        LinkedList leftLL = tree2LL(root->left);
        leftLL.tail->right = root;
        
        l.head = leftLL.head;
        l.tail = root;
    } else if(root->left == NULL && root->right != NULL) {
        LinkedList rightLL = tree2LL(root->right);
        root->right = rightLL.head;
        
        l.head = root;
        l.tail = rightLL.tail;
    } else {
        LinkedList leftLL = tree2LL(root->left);
        LinkedList rightLL = tree2LL(root->right);
        
        leftLL.tail->right = root;
        root->right = rightLL.head;
        
        l.head = leftLL.head;
        l.tail = rightLL.tail;
    }
    
    return l;
}


int main()
{
    vector<int> arr = {8,3,10,1,6,14,4,7,13};
    Node * root = NULL;
    
    for(int num : arr) {
        root = insertInBST(root, num);
    }
    
    inorder(root);
    cout<<endl;
    
    LinkedList l = tree2LL(root);
    Node * temp = l.head;
    
    while(temp != NULL) {
        cout<<temp->data<<"->";
        temp = temp->right;
    }
    cout<<endl;
    
    return 0;
}