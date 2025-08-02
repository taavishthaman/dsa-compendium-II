#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int val;
    Node* left, *right;
};

void pathSum(Node * root, int targetSum, vector<int> v, vector<vector<int>> & res) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) {
        if(targetSum - root->val == 0) {
            v.push_back(root->val);
            res.push_back(v);
        }
        return;
    }
    v.push_back(root->val);
    pathSum(root->left, targetSum - root->val, v, res);
    pathSum(root->right, targetSum - root->val, v, res);
    
}

vector<vector<int>> pathSum(Node* root, int targetSum){
    // your code goes here
    vector<vector<int>> res;
    vector<int> v;
    
    pathSum(root, targetSum, v, res);
    
    return res;
}