#include <bits/stdc++.h>
using namespace std;

bool checkBalancedParentheses(string str) {
    stack<char> s;
    
    for(char ch : str) {
        if(ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } else if(ch ==')' || ch == ']' || ch == '}') {
            if(!s.empty() && ((ch == ')' && s.top() =='(') || (ch == ']' && s.top() == '[') || (ch == '}' && s.top() == '{'))) {
                s.pop();
            } else {
                return false;
            }
        }
    }
    
    return s.empty();
}

int main()
{
    string s = "((a+b+c)+[d])";
    bool balanced = checkBalancedParentheses(s);
    
    if(balanced) {
        cout<<"Expression is balanced"<<endl;
    } else {
        cout<<"Expression is not balanced"<<endl;
    }
    
    return 0;
}