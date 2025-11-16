#include <bits/stdc++.h>
using namespace std;

class Node {
    
public:
    int data;
    Node * left;
    Node * right;
    
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};


Node * buildTree() {
    int d;
    cin>>d;
    
    if(d == -1) {
        return NULL;
    }
    
    Node * n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void preorder(Node * root) {
    if(root == NULL) return;
    
    cout<<root->data<<", ";
    preorder(root->left);
    preorder(root->right);
}

void levelOrderPrint(Node * root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        Node * n = q.front();
        if(n == NULL) {
            q.pop();
            if(!q.empty()) {
                cout<<endl;
                q.push(NULL);
            }
        } else {
            q.pop();
            cout<<n->data<<", ";
            if(n->left != NULL) {
                q.push(n->left);
            }
            if(n->right != NULL) {
                q.push(n->right);
            }
        }
    }
}

Node * levelOrderBuild() {
    int d;
    cin>>d;
    
    queue<Node*> q;
    Node * root = new Node(d);
    
    q.push(root);
    
    while(!q.empty()) {
        Node * f = q.front();
        q.pop();
        
        int d1, d2;
        cin>>d1>>d2;
        
        if(d1 != -1) {
            f->left = new Node(d1);
            q.push(f->left);
        }
        if(d2 != -1) {
            f->right = new Node(d2);
            q.push(f->right);
        }
    }
    
    return root;
}

int height(Node * root) {
    if(root == NULL) {
        return 0;
    }
    
    int left = height(root->left);
    int right = height(root->right);
    
    return 1 + max(left, right);
}

int diameter(Node * root) {
    if(root == NULL) {
        return 0;
    }
    
    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);
    
    return max({D1, D2, D3});
}

/* Diameter Optimised */
class HDPair {
public:
    int height;
    int diameter;
};

HDPair diameterOpt(Node * root) {
    HDPair p;
    if(root == NULL) {
        p.height = p.diameter = 0;
        return p;
    }
    
    HDPair left = diameterOpt(root->left);
    HDPair right = diameterOpt(root->right);
    
    p.height = 1 + max(left.height, right.height);
    p.diameter = max({left.diameter, right.diameter, left.height + right.height});
    
    return p;
}

int replaceWithDescSum(Node * root) {
    if(root == NULL) {
        return 0;
    }
    if(root->left == NULL && root->right == NULL) {
        return root->data;
    }
    
    int LS = replaceWithDescSum(root->left);
    int RS = replaceWithDescSum(root->right);
    
    int temp = root->data;
    root->data = LS + RS;
    return root->data + temp;
}

pair<int, bool> heightBalancedTree(Node * root) {
    pair<int, int> p;
    if(root == NULL) {
        p.first = 0;
        p.second = true;
        return p;
    }
    
    pair<int, int> LP = heightBalancedTree(root->left);
    pair<int, int> RP = heightBalancedTree(root->right);
    
    int height = max(LP.first, RP.first) + 1;
    
    if(abs(LP.first - RP.first) <= 1 && LP.second == true && RP.second == true) {
        return {height, true};
    }
    
    return {height, false};
}

pair<int, int> maxSubsetSumTree(Node * root) {
    pair<int, int> p;
    
    if(root == NULL) {
        p.first = p.second = 0;
        return p;
    }
    
    pair<int, int> LP = maxSubsetSumTree(root->left);
    pair<int, int> RP = maxSubsetSumTree(root->right);
    
    int inc = root->data + LP.second + RP.second;
    int exc = max(LP.first, LP.second) + max(RP.first, RP.second);
    
    return {inc, exc};
}

void printAtLevelK(Node * root, int level) {
    if(root == NULL) {
        return;
    }
    
    printAtLevelK(root->left, level-1);
    if(level == 0) {
        cout<<root->data<<", ";
    }
    printAtLevelK(root->right, level-1);
}

int printNodesAtDistanceK(Node * root, Node * target, int k) {
    if(root == NULL) {
        return -1;
    }
    
    if(root == target) {
        return 0;
    }
    
    int DL = printNodesAtDistanceK(root->left, target, k);
    if(DL != -1) {
        if(DL + 1 == k) {
            cout<<root->data<<", ";
        } else {
            printAtLevelK(root->right, k - 2 - DL);
        }
        
        return DL + 1;
    }
    
    int DR = printNodesAtDistanceK(root->right, target, k);
    if(DR != -1) {
        if(DR + 1 == k) {
            cout<<root->data<<" ";
        } else {
            printAtLevelK(root->left, k - 2 - DR);
        }
        
        return DR + 1;
    }
    
    return -1;
}

void fillMap(Node * root, map<int, vector<int>> & m, int d) {
    if(root == NULL) return;
    
    m[d].push_back(root->data);
    fillMap(root->left, m, d - 1);
    fillMap(root->right, m, d + 1);
}

void verticalOrderPrint(Node * root) {
    map<int, vector<int>> m;
    int d = 0;
    
    fillMap(root, m, d);
    
    for(auto p : m) {
        for(int num : m[p.first]) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    //Input Preorder : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    //Input Levelorder : 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
    Node * root = buildTree();
    preorder(root);
    cout<<endl;
    levelOrderPrint(root);
    cout<<endl;
    Node * root2 = levelOrderBuild();
    levelOrderPrint(root2);
    cout<<endl;
    int d = diameter(root);
    cout<<"Diameter is "<<d<<endl;
    HDPair p = diameterOpt(root);
    cout<<"Optimized Diameter is "<<p.diameter<<endl;
    //replaceWithDescSum(root);
    levelOrderPrint(root);
    cout<<endl;
    cout<<heightBalancedTree(root).second<<endl;
    
    pair<int, int> pMaxSub = maxSubsetSumTree(root);
    cout<<"Max subset sum is "<<max(pMaxSub.first, pMaxSub.second)<<endl;
    printAtLevelK(root, 2);
    cout<<endl;
    cout<<"Nodes at distance "<<endl;
    printNodesAtDistanceK(root, root->left->right, 2);
    cout<<endl;
    verticalOrderPrint(root);
    return 0;
}