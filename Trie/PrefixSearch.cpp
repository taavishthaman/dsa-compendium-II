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
    
    vector<string> prefixSearch(string prefix) {
        Node * temp = root;
        vector<string> words;
        
        for(char ch : prefix) {
            temp = temp->m[ch];
        }
        
        searchStrings(temp, prefix, words);
        
        return words;
    }
    
    void searchStrings(Node * curr, string prefix, vector<string> & words) {
        if(curr->isTerminal == true) {
            words.push_back(prefix);
        }
        
        for(auto pair : curr->m) {
            char ch = pair.first;
            searchStrings(curr->m[ch], prefix + ch, words);
        }
    }
};

vector<string> findPrefixStrings(vector<string> words, string prefix){
    Trie t;
    for(string word : words) {
        t.insert(word);
    }
    
    vector<string> result = t.prefixSearch(prefix);
    sort(result.begin(), result.end());
    return result;
}
