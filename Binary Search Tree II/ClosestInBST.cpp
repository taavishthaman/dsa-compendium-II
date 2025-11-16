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

int closestElementToTarget(Node * root, int target) {
    int min_diff = INT_MAX;
    int res = root->data;
    
    Node * temp = root;
    
    while(temp != NULL) {
        int curr_diff = abs(temp->data - target);
        if(curr_diff == 0) {
            return temp->data;
        }
        if(curr_diff < min_diff) {
            min_diff = curr_diff;
            res = temp->data;
        }
        
        if(target < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    
    return res;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,70};
    Node * root = minHeightBST(arr, 0, arr.size() - 1);
    inorder(root);
    cout<<endl;
    int closest = closestElementToTarget(root, 9);
    cout<<"Closest Element to target is "<<closest<<endl;
    return 0;
}