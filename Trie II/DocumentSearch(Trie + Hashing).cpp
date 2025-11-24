#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char ch;
    unordered_map<char, Node*> children;
    bool isTerminal;
    
    Node(char ch) {
        this->ch = ch;
        isTerminal = false;
    }
};

class Trie {
public:
    Node * root;
    
    Trie() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node * temp = root;
        
        for(char ch : word) {
            if(temp->children.count(ch) == 0) {
                Node * n = new Node(ch);
                temp->children[ch] = n;
            }
            
            temp = temp->children[ch];
        }
        
        temp->isTerminal = true;
    }
};

void searchHelper(Trie t, string document, int idx, unordered_set<string> & s) {
    Node * temp = t.root;
    
    for(int j=idx; j < document.size(); j++) {
        char ch = document[j];
        if(temp->children.count(ch) == 0) {
            return;
        }
        temp = temp->children[ch];
        
        if(temp->isTerminal) {
            string op = document.substr(idx, j - idx + 1);
            s.insert(op);
        }
    }
}

void search(vector<string> & words, string document) {
    Trie t;
    for(string w : words) {
        t.insert(w);
    }
    
    unordered_set<string> s;
    for(int i=0; i<document.size(); i++) {
        searchHelper(t, document, i, s);
    }
    
    for(string w : words) {
        if(s.find(w) != s.end()) {
            cout<<w<<" exists in the document"<<endl;
        } else {
            cout<<w<<" does not exist in the document"<<endl;
        }
    }
}

int main()
{
    vector<string> words = {"cute cat", "ttle", "cat", "quick", "big"};
    string document = "little cute cat loves to code in c++, java & python.";
    
    search(words, document);
    return 0;
}