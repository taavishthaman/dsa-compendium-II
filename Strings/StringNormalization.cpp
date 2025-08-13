#include<bits/stdc++.h>
using namespace std;

vector<string> tokenize(string str) {
    stringstream ss(str);
    vector<string> tokens;
    string token;
    
    while(getline(ss, token, ' ')) {
        string normalizedToken = "";
        for(int i=0; i<token.size(); i++) {
            if(i == 0) {
                normalizedToken += toupper(token[i]);
            } else {
                normalizedToken += tolower(token[i]);
            }
        }
        
        tokens.push_back(normalizedToken);
    }
    
    return tokens;
}

string normalize(const string &sentence) {
    string copy = "";
    //Make the changes in copy, and return it
    vector<string> tokens = tokenize(sentence);
    for(int i=0; i<tokens.size(); i++) {
        copy += tokens[i];
        if(i < tokens.size() - 1) {
            copy += " ";
        }
    }

    return sentence[sentence.size()-1] == ' ' ? copy + ' ' : copy;
}

int main() {
    string str = "  Abc  Def Ghi ";
    string result = normalize(str);
    cout<<"Result is "<<result<<endl;
}