#include<bits/stdc++.h>
using namespace std;

//str is the input the string
string compressString(const string &str) {
    int n = str.size();
    string res = "";
    int count = 1;
    int i;
    for(i=0; i<n-1; i++) {
        char ch = str[i];
        if(ch == str[i+1]) {
            count++;
        } else {
            res += (ch + to_string(count));
            count = 1;
        }
    }
    
    res += (str[i] + to_string(count));
    return res.size() < str.size() ? res : str;
}

int main() {
    string str = "bbbaaaadexxxxxx";
    string res = compressString(str);
    cout<<"Result is "<<res<<endl;
}