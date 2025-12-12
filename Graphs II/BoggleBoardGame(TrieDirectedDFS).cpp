#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char ch;
    unordered_map<char, Node*> m;
    bool isTerminal;
    string word = "";
    
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
    
    void addWord(string word) {
        Node * temp = root;
        
        for(char ch : word) {
            if(temp->m.count(ch) == 0) {
                Node * n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        
        temp->isTerminal = true;
        temp->word = word;
    }
};

void dfs(vector<vector<char>> & board, vector<vector<bool>> & visited, Node * node, unordered_set<string> & s, int i, int j, int N, int M) {
    char ch = board[i][j];
    
    if(node->m.count(ch) == 0) {
        return;
    }
    
    node = node->m[ch];
    
    if(node->isTerminal) {
        s.insert(node->word);
    }
    
    visited[i][j] = true;
    
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    for(int k=0; k<8; k++) {
        int ni = i + dy[k];
        int nj = j + dx[k];
        
        if(ni >= 0 && nj >= 0 && ni < N && nj < M && !visited[ni][nj]) {
            dfs(board, visited, node, s, ni, nj, N, M);
        }
    }
    
    visited[i][j] = false;
    return;
}

int main() {
    vector<string> words = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "SENS", "TUNES", "CAT"};
    vector<vector<char>> board = {
        {'S', 'E', 'R', 'T'},
        {'U', 'N', 'K', 'S'},
        {'T', 'C', 'A', 'T'}
    };
    
    int N = board.size();
    int M = board[0].size();
    
    Trie t;
    for(string w : words) {
        t.addWord(w);
    }
    
    unordered_set<string> s;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            dfs(board, visited, t.root, s, i, j, N, M);
        }
    }
    
    for(string w : s) {
        cout<<w<<", ";
    }
}