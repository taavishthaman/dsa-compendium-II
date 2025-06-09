#include<bits/stdc++.h>
using namespace std;

bool checkIfVowel(char ch) {
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        return true;
    }
    
    return false;
}

string vowel(string S){
    // your code goes here
    string res = "";
    
    for(char ch : S) {
        if(checkIfVowel(ch)) {
            res += ch;
        }
    }
    
    return res;
} 