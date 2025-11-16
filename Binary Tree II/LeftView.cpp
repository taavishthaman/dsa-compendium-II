#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};

void levelOrderTraversal(Node * root, vector<int> & res) {
    
    map<int, vector<int>> m;
    queue<Node*> q;
    
    int level = 0;
    q.push(root);
    q.push(NULL);
    
    
    while(!q.empty()) {
        Node * f = q.front();
        q.pop();
        if(f == NULL) {
            if(!q.empty()) {
                q.push(NULL);
                level += 1;
            }
        } else {
            m[level].push_back(f->key);
            
            if(f->left != NULL) {
                q.push(f->left);
            }
            
            if(f->right != NULL) {
                q.push(f->right);
            }
        }
    }
    
    for(auto p : m) {
        res.push_back(p.second[0]);
    }
}

vector<int> leftView(Node * root){
    //Complete the function
    vector<int> res;
    
    levelOrderTraversal(root, res);
    
    return res;
    
}