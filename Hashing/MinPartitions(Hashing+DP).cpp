#include <bits/stdc++.h>
using namespace std;

int minimumPartitonsHelper(string & str, unordered_set<string> & s, int idx, vector<int> & dp) {
    if(str[idx] == '\0') {
        return 0;
    }
    
    int ans = INT_MAX;
    string op = "";
    
    if(dp[idx] != -1) {
        return dp[idx];
    }
    
    for(int j=idx; str[j] != '\0'; j++) {
        op += str[j];
        if(s.find(op) != s.end()) {
            int sub = minimumPartitonsHelper(str, s, j+1, dp);
            if(sub != -1) {
                ans = min(ans, 1 + sub);
            }
        }
    }
    
    if(ans == INT_MAX) {
        return -1;
    }
    
    return dp[idx] = ans;
}

int minimumPartitons(vector<string> words, string str) {
    unordered_set<string> s;
    
    for(string w : words) {
        s.insert(w);
    }
    
    vector<int> dp(str.size() + 1, -1);
    
    int result = minimumPartitonsHelper(str, s, 0, dp);
    
    return result-1;
}

int main()
{
    // vector<string> words = {"the", "quick", "quickbrown", "brown", "fox"};
    // string str = "thequickbrownfox";
    vector<string> words = {"the", "fox", "thequickbrownfox", "jumps", "lazy", "lazyfox", "highbridge", "the", "over", "bridge", "high", "tall", "quick", "brown"};
    string str = "thequickbrownfoxjumpsoverthehighbridge";
    
    cout<<"Min Partitons "<<minimumPartitons(words, str)<<endl;
    return 0;
}