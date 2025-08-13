#include <bits/stdc++.h>
using namespace std;

bool compare(string s1, string s2) {
    if(s1.size() == s2.size()) {
        return s1 < s2;
    }
    return s1.size() < s2.size();
}

void subsequences(string s, string o, vector<string> & v) {
    if(s.size() == 0) {
        v.push_back(o);
        return;
    }
    
    char ch = s[0];
    string reduced_input = s.substr(1);
    subsequences(reduced_input, o+ch, v);
    subsequences(reduced_input, o, v);
}

int main() {
    string s;
    cin>>s;
    vector<string> v;
    subsequences(s, "", v);
    
    sort(v.begin(), v.end(), compare);
    for(string str : v) {
        cout<<str<<", ";
    }
}