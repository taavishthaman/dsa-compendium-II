#include <bits/stdc++.h>
using namespace std;

vector<int> getHash(string str, int i, int j) {
    vector<int> hash(26, 0);
    
    for(int k=i; k<=j; k++) {
        hash[str[k] - 'a'] += 1;
    }
    
    return hash;
}

int anagramsInSubstrings(string str) {
    int n = str.size();
    map<vector<int>, int> frq_map;
    
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            vector<int> hash = getHash(str, i, j);
            frq_map[hash] += 1;
        }
    }
    
    int count = 0;
    
    for(auto p : frq_map) {
        int frq = p.second;
        
        if(frq >= 2) {
            count += ((frq) * (frq-1)) / 2;
        }
    }
    
    return count;
}

int main()
{
    string str;
    cin>>str;
    int count = anagramsInSubstrings(str);
    cout<<"Anagrams is substrings "<<count<<endl;
    return 0;
}