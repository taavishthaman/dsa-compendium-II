#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "Hello World";
    cout<<s<<endl;
    string s2;
    getline(cin, s2, '.');
    cout<<s2<<endl;
    
    vector<string> sarr;
    int n = 5;
    
    while(n >= 0) {
        getline(cin, s);
        sarr.push_back(s);
        n--;
    }
    
    for(string str : sarr) {
        cout<<str<<", ";
    }
}