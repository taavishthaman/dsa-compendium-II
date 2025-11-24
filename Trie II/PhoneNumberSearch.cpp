#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    char ch;
    unordered_map<char, Node*> m;
    bool isTerminal;
    string word;
    
    Node(char ch) {
        this->ch = ch;
        isTerminal = false;
        word = "";
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
            if(temp->m.count(ch) == 0) {
                Node * n = new Node(ch);
                temp->m[ch] = n;
                n->word = temp->word + ch;
            }
            temp = temp->m[ch];
        }
        
        temp->isTerminal = true;
    }
};

void findWords(Node * root, vector<string> & keypad, string & phoneNumber, int idx, unordered_set<string> & s) {
    if(root->isTerminal) {
        s.insert(root->word);
    }
    
    if(idx == phoneNumber.size() || root == NULL) {
        return;
    }
    
    int number = phoneNumber[idx] - '0';
    string chars = keypad[number];
    
    for(int i=0; i<chars.size(); i++) {
        char ch = chars[i];
        if(root->m.count(ch) == 0) {
            continue;
        }
        
        findWords(root->m[ch], keypad, phoneNumber, idx + 1, s);
        findWords(root, keypad, phoneNumber, idx + 1, s);
    }
}

vector<string> filterNames(string phoneNumber, vector<string> words){
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    Trie t;
    for(string w : words) {
        t.insert(w);
    }
    
    unordered_set<string> s;
    
    findWords(t.root, keypad, phoneNumber, 0, s);
    
    vector<string> op;
    
    for(string w : s) {
        op.push_back(w);
    }
    
    return op;
}

int main() {
    string phoneNumber = "7728335";
    vector<string> words = {"prat","prateek","codingminutes","code","prat335", "teek"};
    
    vector<string> result = filterNames(phoneNumber, words);
    
    for(string str : result) {
        cout<<str<<", ";
    }
}