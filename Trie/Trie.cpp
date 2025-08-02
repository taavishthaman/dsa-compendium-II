#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char data;
    unordered_map<char, Node*> m;
    bool isTerminal;
    Node(char data) {
        this->data = data;
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

int main()
{
    Trie t;
    
    vector<string> words = {"hello", "he", "apple", "news", "aple"};
    
    string key;
    cin>>key;
    
    for(string w : words) {
        t.insert(w);
    }
    
    bool found = t.search(key);
    if(found) {
        cout<<key<<" was found!"<<endl;
    } else {
        cout<<key<<" was not found!"<<endl;
    }

    return 0;
}