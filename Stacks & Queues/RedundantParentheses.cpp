#include <bits/stdc++.h>
using namespace std;

bool checkRedundantParentheses(string str) {
    stack<char> s;
    
    for(char ch : str) {
        if(ch != ')') {
            s.push(ch);
        } else {
            bool operatorFound = false;
            
            while(!s.empty() && s.top() != '(') {
                char t = s.top();
                s.pop();
                if(t == '+' || t == '-' || t == '/' || t == '*') {
                    operatorFound = true;
                }
            }
            
            s.pop();
            if(!operatorFound) {
                return true;
            }
        }
    }
    
    return false;
}

int main()
{
    string str = "((a+b)+c) + ((d*e))";
    bool redundant = checkRedundantParentheses(str);
    
    if(redundant) {
        cout<<"Expression contains redundant parentheses"<<endl;
    } else {
        cout<<"Expression does not contain redundant parentheses"<<endl;
    }
    return 0;
}