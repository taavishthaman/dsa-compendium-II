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

class SuffixTrie {
public:
    Node * root;
    
    SuffixTrie() {
        root = new Node('\0');
    }
    
    void insertHelper(string word) {
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
    
    void insert(string word) {
        for(int i=0; word[i] != '\0'; i++) {
            insertHelper(word.substr(i));
        }
    }
};

int main() {
    string input = "hello";
    
    vector<string> suffixes = {"lo", "ell", "hello"};
    
    SuffixTrie t;
    t.insert(input);
    
    for(string word : suffixes) {
        bool found = t.search(word);
        if(found) {
            cout<<word<<" found"<<endl;
        } else {
            cout<<word<<" not found"<<endl;
        }
    }
}
