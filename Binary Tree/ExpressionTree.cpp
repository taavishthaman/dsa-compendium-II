#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    string key;
    Node* left, *right;
};

int evalTree(Node* root){
    if(root == NULL) return 0;
    
    string curr = root->key;
    int leftComputation = evalTree(root->left);
    int rightComputation = evalTree(root->right);
    if(curr == "+" || curr == "-" || curr == "/" || curr == "*") {
        if(curr == "+") {
            return leftComputation + rightComputation;
        } else if(curr == "-") {
            return leftComputation - rightComputation;
        } else if(curr == "*") {
            return leftComputation * rightComputation;
        } else {
            return leftComputation / rightComputation;
        }
    }
    
    return stoi(curr);
}