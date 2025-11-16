#include <bits/stdc++.h>
using namespace std;

string firstNonRepeating(string str) {
    queue<char> q;
    unordered_map<char, int> m;
    string res = "";
    
    for(int i=0; i<str.size(); i++) {
        char ch = str[i];
        
        q.push(ch);
        m[ch] += 1;
        
        while(!q.empty() && m[q.front()] > 1) {
            q.pop();
        }
        
        if(q.empty()) {
            res += "-1";
        } else {
            res += q.front();
        }
    }
    
    return res;
}

int main()
{
    string str = "aabccbcd";
    string res = firstNonRepeating(str);
    
    cout<<"Result is "<<res<<endl;
    return 0;
}