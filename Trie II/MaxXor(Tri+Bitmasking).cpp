#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node * left;
    Node * right;
    
    Node() {
        left = right = NULL;
    }
};

class Trie {
public:
    Node * root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(int n) {
        Node * temp = root;
        
        for(int i=31; i>=0; i--) {
            int bit = (n>>i) & 1;
            
            if(bit == 0) {
                if(temp->left == NULL) {
                    Node * n = new Node();
                    temp->left = n;
                }
                temp = temp->left;
            } else {
                if(temp->right == NULL) {
                    Node * n = new Node();
                    temp->right = n;
                }
                temp = temp->right;
            }
        }
    }
    
    int max_xor_helper(int n) {
        int xor_value = 0;
        
        Node * temp = root;
        
        for(int i=31; i>=0; i--) {
            int bit = (n >> i) & 1;
            
            if(bit == 0) {
                if(temp->right != NULL) {
                    xor_value += (1 << i);
                    temp = temp->right;
                } else {
                    temp = temp->left;
                }
            } else {
                if(temp->left != NULL) {
                    xor_value += (1 << i);
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            }
        }
        
        return xor_value;
    }
    
    int max_xor(vector<int> & nums) {
        int max_xor_value = 0;
        
        for(int i=0; i<nums[i]; i++) {
            int num = nums[i];
            insert(num);
            int curr_xor = max_xor_helper(num);
            max_xor_value = max(max_xor_value, curr_xor);
        }
        
        return max_xor_value;
    }
};

int main()
{
    vector<int> arr = {3,10,5,25,9,2};
    Trie t;
    int result = t.max_xor(arr);
    cout<<"Maximum XOR is "<<result<<endl;
    return 0;
}