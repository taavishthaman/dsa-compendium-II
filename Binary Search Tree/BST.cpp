#include<bits/stdc++.h>
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

Node * buildTree(Node * root, int data) {
    if(root == NULL) {
        Node * n = new Node(data);
        return n;
    }
    
    if(data < root->data) {
        root->left = buildTree(root->left, data);
    } else {
        root->right = buildTree(root->right, data);
    }
    
    return root;
}

void inorder(Node * root) {
    if(root == NULL) return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool search(Node * root, int data) {
    if(root == NULL) return false;
    
    if(data == root->data) {
        return true;
    } else if(data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
    
    return false;
}

Node * findMinimum(Node * root) {
    while(root->left != NULL) {
        root = root->left;
    }
    
    return root;
}

Node * remove(Node * root, int key) {
    if(root == NULL) {
        return NULL;
    }
    
    else if(key < root->data) {
        root->left = remove(root->left, key);
    } else if(key > root->data) {
        root->right = remove(root->right, key);
    } else {
        //Case I: Deleting a leaf Node
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        } 
        //Case II: If left subtree exists, rewire root->left to root
        else if(root->left == NULL) {
            Node * temp = root;
            root = root->right;
            delete temp;
        } 
        //Case III: If right subtree exists, rewire root->right to root
        else if(root->right == NULL) {
            Node * temp = root;
            root = root->left;
            delete temp;
        } 
        //Case IV: If a node has both children, find the minimum in the right subtree and replace it with root
        else {
            Node * temp = findMinimum(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
    }
    
    return root;
}

void printRange(Node * root, int k1, int k2) {
    if(root == NULL) {
        return;
    }
    
    if(root->data >= k1 && root->data <= k2) {
        //call on both sides, if root data lies in the range
        printRange(root->left, k1, k2);
        cout<<root->data<<" ";
        printRange(root->right, k1, k2);
    }
    else if(root->data > k2) {
        //Call only on left if root data is greater than the range
        printRange(root->left, k1, k2);
    }
    else {
        //Call only on right if root data is lesser than the range
        printRange(root->right, k1, k2);
    }
}

void printRootToLeafPaths(Node * root, vector<int> path) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        for(int num : path) {
            cout<<num<<"->";
        }
        cout<<root->data<<endl;
        return;
    }
    
    path.push_back(root->data);
    printRootToLeafPaths(root->left, path);
    printRootToLeafPaths(root->right, path);
}

int main() {
    Node * root = NULL;
    vector<int> arr = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    
    for(int num : arr) {
        root = buildTree(root, num);
    }
    
    inorder(root);
    cout<<endl;
    int target;
    cout<<"Enter the target value to be searched "<<endl;
    cin>>target;
    bool found = search(root, target);
    if(found) {
        cout<<target<<" was found!"<<endl;
    } else {
        cout<<target<<" was not found!"<<endl;
    }
    
    cout<<"Enter the target value to be removed "<<endl;
    cin>>target;
    Node * newRoot = remove(root, target);
    inorder(newRoot);
    int k1, k2;
    cin>>k1>>k2;
    printRange(root, k1, k2);
    vector<int> path;
    printRootToLeafPaths(root, path);
}