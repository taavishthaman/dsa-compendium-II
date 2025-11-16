#include <bits/stdc++.h>
using namespace std;

vector<string> extractTokens(string path) {
    stringstream ss(path);
    vector<string> tokens;
    string token;
    
    while(getline(ss, token, '/')) {
        if(token == "." || token == "") continue;
        tokens.push_back(token);
    }
    
    return tokens;
}

string simplifyPath(string path) {
    vector<string> tokens = extractTokens(path);
    
    vector<string> stack;
    if(path[0] == '/') {
        stack.push_back(".");
    }
    
    for(string token : tokens) {
        if(token == "..") {
            if(stack.size() == 0 || stack[stack.size() - 1] == "..") {
                stack.push_back("..");
            } else if (stack[stack.size()-1] != "") {
                stack.pop_back();
            }
        } else {
            stack.push_back(token);
        }
    }
    
    if(stack.size() == 1 && stack[0] == "") {
        return "/";
    }
    
    string res = "";
    
    for(int i=0; i<stack.size(); i++) {
        if(i == stack.size()-1) {
            res += stack[i];
        } else {
            res += stack[i];
            res += '/';
        }
    }
    
    return res;
}

int main()
{
    string path = "/../x/y/../z/././w/a///../../c/./";
    //Output: /x/z/c
    string res = simplifyPath(path);
    cout<<"Result is "<<res<<endl;
    return 0;
}