#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node* left, *right;
};

int minDepth(Node *root) {
    // Your code here
    if(root == NULL) {
        return 0;
    }
    
    int h1 = minDepth(root->left);
    int h2 = minDepth(root->right);
    
    return min(h1, h2) + 1;
}