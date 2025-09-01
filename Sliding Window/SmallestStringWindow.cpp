#include <bits/stdc++.h>
using namespace std;

string find_window(string s, string p) {
    int n = s.size();
    int m = p.size();
    
    vector<int> FS(256, 0);
    vector<int> FP(256, 0);
    
    int cnt = 0;
    int start = 0;
    int min_window = INT_MAX;
    int min_window_start = -1;
    
    for(char ch : p) {
        FP[ch]++;
    }
    
    for(int i=0; i<n; i++) {
        char ch = s[i];
        FS[ch]++;
        
        //If the current character exists inside the pattern and frequency of character in string is lesser than or equal to frquency in pattern
        //Why equal to? Because in the previous line we have added the current character to the string map
        if(FP[ch] != 0 && FS[ch] <= FP[ch]) {
            cnt++;
        }
        
        if(cnt == m) {
            //Window contraction => Remove unwanted characters => Either not present in pattern or current window has more than required
            while(FP[s[start]] == 0 || FS[s[start]] > FP[s[start]]) {
                FS[s[start]]--;
                start++;
            }
            
            int window_len = (i - start + 1);
            
            if(window_len < min_window) {
                min_window = window_len;
                min_window_start = start;
            }
        }
    }
    
    if(min_window_start == -1) {
        return "No window Found!";
    }
    
    return s.substr(min_window_start, min_window_start + min_window);
}

int main()
{
    string s, p;
    cin>>s>>p;
    cout<<find_window(s, p)<<endl;
    return 0;
}