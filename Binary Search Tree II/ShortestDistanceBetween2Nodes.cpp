#include<bits/stdc++.h>
using namespace std;

class node
{
  public:
   int key;
   node *left;
   node *right;

   node(int key){
       this->key = key;
       left = right  = NULL;
   }
};

node * findLCA(node * root, int a, int b) {
    if(root == NULL) {
        return NULL;
    }
    
    if(a <= root->key && b >= root->key) {
        return root;
    } else if(a < root->key && b < root->key) {
        return findLCA(root->left, a, b);
    } else {
        return findLCA(root->right, a, b);
    }
}

int distance(node * root, int target) {
    int dist = 0;
    node * temp = root;
    
    while(temp->key != target) {
        if(target < temp->key) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
        dist += 1;
    }
    
    return dist;
}

//here nodes a and b are the inputs
int shortestDist(node * root,int a,int b){
    //Complete this method
    if(a > b) {
        swap(a, b);
    }
    node * lca = findLCA(root, a, b);
    
    return distance(lca, a) + distance(lca, b);
}