#include<bits/stdc++.h>
using namespace std;


char firstRepeatChar(string input){
    unordered_set<char> s;
    
    for(char ch : input) {
        if(s.find(ch) != s.end()) {
            return ch;
        }
        s.insert(ch);
    }
    
    return '\0';
}