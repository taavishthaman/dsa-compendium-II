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

Node * preorderBuild() {
    int d;
    cin>>d;
    
    if(d == -1) {
        return NULL;
    }
    
    Node * n = new Node(d);
    n->left = preorderBuild();
    n->right = preorderBuild();
    return n;
}

void preorder(Node * root) {
    if(root == NULL) {
        return;
    }
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node * root) {
    if(root == NULL) {
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node * root) {
    if(root == NULL) {
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node * root) {
    queue<Node*> q;
    
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        Node * f = q.front();
        q.pop();
        
        if(f == NULL) {
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout<<f->data<<" ";
            if(f->left != NULL) {
                q.push(f->left);
            }
            if(f->right != NULL) {
                q.push(f->right);
            }
        }
    }
}

Node * levelOrderBuild() {
    queue<Node*> q;
    int d;
    cin>>d;
    
    Node * root = new Node(d);
    q.push(root);
    
    while(!q.empty()) {
        Node * f = q.front();
        q.pop();
        
        int c1, c2;
        cin>>c1>>c2;
        
        if(c1 != -1) {
            Node * n = new Node(c1);
            q.push(n);
            f->left = n;
        }
        
        if(c2 != -1) {
            Node * n = new Node(c2);
            q.push(n);
            f->right = n;
        }
    }
    
    return root;
}

int height(Node * root) {
    if(root == NULL) {
        return 0;
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return 1 + max(leftHeight, rightHeight);
}

void printKthLevel(Node * root, int k, vector<int> & arr) {
    if(root == NULL) return;
    
    if(k == 0) {
        arr.push_back(root->data);
    }
    printKthLevel(root->left, k-1, arr);
    printKthLevel(root->right, k-1, arr);
}

//Returns a list of nodes at the Kth level
vector<int> printKthLevel(Node* root, int k){
   vector<int> arr;
   
   printKthLevel(root, k, arr);
   
   return arr;
}

//Sum of all nodes in BT
int sumBT(Node* root)
{
    if(root == NULL) {
        return 0;
    }
    
    return root->data + sumBT(root->left) + sumBT(root->right);
}

//Diameter of a tree: Diameter of a tree is defined as the largest disatnce between two nodes in a tree
//Time complexity is O(N^2) time because at every node we are traversing every other node
int diameter(Node * root) {
    if(root == NULL) {
        return 0;
    }
    
    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);
    
    return max({D1, D2, D3});
}

class HDPair {
public:
    int height;
    int diameter;
};

HDPair optDiameter(Node * root) {
    HDPair p;
    if(root == NULL) {
        p.height = p.diameter = 0;
        return p;
    }
    
    HDPair Left = optDiameter(root->left);
    HDPair Right = optDiameter(root->right);
    
    p.height = max(Left.height, Right.height) + 1;
    
    int D1 = Left.height + Right.height;
    int D2 = Left.diameter;
    int D3 = Right.diameter;
    
    p.diameter = max({D1, D2, D3});
    
    return p;
}

int main()
{
    //Input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    //Input: 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
    
    Node * root = preorderBuild();
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelOrder(root);
    
    Node * root2 = levelOrderBuild();
    levelOrder(root2);
    
    int h = height(root2);
    cout<<"Height of the tree is "<<h<<endl;
    int d = diameter(root2);
    cout<<"Diameter of the tree is "<<d<<endl;
    HDPair p = optDiameter(root2);
    cout<<"Opt diameter is "<<p.diameter<<endl;

    return 0;
}