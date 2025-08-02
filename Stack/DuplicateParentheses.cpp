#include<bits/stdc++.h>
using namespace std;

bool duplicateParentheses(string str){
    int n = str.size();
    stack<char> s;
    
    for(int i=0; i<n; i++) {
        char ch = str[i];
        
        if(ch != ')') {
            s.push(ch);
        } else {
            if(s.top() == '(') return true;
            while(s.top() != '(') {
                s.pop();
            }
            
            s.pop();
        }
    }
    
    return false;
}