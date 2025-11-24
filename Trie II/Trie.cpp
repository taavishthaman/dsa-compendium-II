#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    char ch;
    unordered_map<char, Node*> m;
    bool isTerminal;
    
    Node(char ch) {
        this->ch = ch;
        isTerminal = false;
    }
};

class Trie {
    Node * root;
    
public:
    Trie() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node * temp = root;
        
        for(char ch : word) {
            if(temp->m.count(ch) == 0) {
                Node * n = new Node(ch);
                temp->m[ch] = n;
            }
            
            temp = temp->m[ch];
        }
        
        temp->isTerminal = true;
    }
    
    bool search(string word) {
        Node * temp = root;
        
        for(char ch : word) {
            if(temp->m.count(ch) == 0) {
                return false;
            }
            
            temp = temp->m[ch];
        }
        
        return temp->isTerminal;
    }
};

int main() {
    vector<string> words = {"apple", "ape", "no", "news", "not", "never"};
    
    Trie t;
    
    for(string w : words) {
        t.insert(w);
    }
    
    string word;
    cin>>word;
    
    bool found = t.search(word);
    if(found) {
        cout<<word<<" was found"<<endl;
    } else {
        cout<<word<<" was not found"<<endl;
    }
}
