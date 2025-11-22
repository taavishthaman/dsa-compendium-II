#include<bits/stdc++.h>
using namespace std;

vector<int> getHash(string w) {
    vector<int> v(26, 0);
    
    for(char ch : w) {
        v[ch-'a'] += 1;
    }
    
    return v;
}

vector<vector<string>> groupAnagrams(vector<string> strs){
    //Write your code here. Do not modify the function or the parameters.
    map<vector<int>, vector<string>> m;
    
    for(string w : strs) {
        vector<int> hash = getHash(w);
        m[hash].push_back(w);
    }
    
    vector<vector<string>> res;
    
    for(auto p : m) {
        res.push_back(p.second);
    }
    
    return res;
}

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    
    vector<vector<string>> res = groupAnagrams(strs);
    
    for(vector<string> v : res) {
        for(string w : v) {
            cout<<w<<", ";
        }
        cout<<endl;
    }
}