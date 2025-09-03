#include <bits/stdc++.h>
using namespace std;

void findSubsets(string s, string op) {
    if(s.size() == 0) {
        cout<<op<<", ";
        return;
    }
    
    char ch = s[0];
    string rs = s.substr(1);
    findSubsets(rs, op+ch);
    findSubsets(rs, op);
}

int main()
{
    string s = "abc";
    findSubsets(s, "");
    return 0;
}