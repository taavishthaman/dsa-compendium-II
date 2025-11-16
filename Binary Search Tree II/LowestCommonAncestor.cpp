#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node*left;
	node*right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node * lcaOrder(node * root, int a, int b) {
    if(root == NULL) {
        return NULL;
    }
    
    if(a <= root->data && b >= root->data) {
        return root;
    }
    else if(a < root->data && b < root->data) {
        return lcaOrder(root->left, a, b);
    } else {
        return lcaOrder(root->right, a, b);   
    }
}

node* lca(node*root, int a, int b){
    //Complete this function and return address of the node
    if(a > b) {
        swap(a, b);
    }
    
    return lcaOrder(root, a, b);
}