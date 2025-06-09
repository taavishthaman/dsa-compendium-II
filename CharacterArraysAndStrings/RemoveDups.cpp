#include <bits/stdc++.h>
using namespace std;

string removeDuplicate(string s){
    // your code goes here
    string res = "";
    sort(s.begin(), s.end());
    int i = 0;
    int j = 0;
    int n = s.size();
    
    for(i=0; i<n-1; i++) {
        if(s[i] != s[i+1]) {
            res += s[i];
        }
    }
    
    res += s[i];
    return res;
}