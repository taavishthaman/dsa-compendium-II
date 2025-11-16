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

Node * minHeightBST(vector<int> & arr, int s, int e) {
    if(s > e) {
        return NULL;
    }
    
    int m = (s + e) / 2;
    Node * n = new Node(arr[m]);
    
    n->left = minHeightBST(arr, s, m - 1);
    n->right = minHeightBST(arr, m+1, e);
    
    return n;
}

void inorder(Node * root) {
    if(root == NULL) {
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7};
    Node * root = minHeightBST(arr, 0, arr.size() - 1);
    inorder(root);
    return 0;
}