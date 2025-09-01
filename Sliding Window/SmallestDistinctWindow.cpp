#include <bits/stdc++.h>
using namespace std;

string smallestWindow(string str){
    if(str.size() == 0) return "";
    //Create the pattern string
    int n = str.size();
    unordered_map<char, int> m;
    
    for(char ch : str) {
        m[ch]++;
    }
    
    string p = "";
    for(auto pair : m) {
        p += pair.first;
    }
    
    vector<int> FS(256, 0);
    vector<int> FP(256, 0);
    int cnt = 0;
    int start = 0;
    int min_window_len = INT_MAX;
    int min_window_start = -1;
    
    for(char ch : p) {
        FP[ch]++;
    }
    
    for(int i=0; i<n; i++) {
        char ch = str[i];
        FS[ch]++;
        
        if(FP[ch] != 0 && FS[ch] <= FP[ch]) {
            cnt++;
        }
        
        if(cnt == p.size()) {
            while(FP[str[start]] == 0 || FS[str[start]] > FP[str[start]]) {
                FS[str[start]]--;
                start++;
            }
            
            int window_len = i - start + 1;
            if(window_len < min_window_len) {
                min_window_len = window_len;
                min_window_start = start;
            }
        }
    }
    
    return str.substr(min_window_start, min_window_len);
}

int main()
{
    string str = "aaaa";
    string res = smallestWindow(str);
    cout<<"Result is "<<res<<endl;
}