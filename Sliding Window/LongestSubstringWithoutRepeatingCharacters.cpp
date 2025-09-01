#include <bits/stdc++.h>
using namespace std;

string longest_substring(string str) {
    int n = str.size();
    int i = 0, j = 0, window_len = 0, max_window_len = 0;
    int start = -1; //start is used to keep track of start of the largest window found so far, its different than i
    unordered_map<char, int> m;
    
    while(j < n) {
        char ch = str[j];
        
        if(m.count(ch) && m[ch] >= i) {
            i = m[ch] + 1;
            window_len = j - i;
        }
        
        window_len++;
        m[ch] = j;
        j++;
        
        if(window_len > max_window_len) {
            max_window_len = window_len;
            start = i;
        }
    }
    
    return str.substr(start, window_len + start);
}

int main()
{
    string str;
    cin>>str;
    
    string res = longest_substring(str);
    cout<<"Result is "<<res<<endl;

    return 0;
}