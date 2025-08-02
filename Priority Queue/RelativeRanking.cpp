#include<bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
    // your code goes here
    priority_queue<int> q;
    
    for(int num : score) {
        q.push(num);
    }
    
    int count = 1;
    int n = score.size();
    vector<string> res(n, "");
    while(!q.empty()) {
        int top = q.top();
        
        q.pop();
        for(int i=0; i<n; i++) {
            if(score[i] == top && count == 1) {
                res[i] = "Gold Medal";
            } else if(score[i] == top && count == 2) {
                res[i] = "Silver Medal";
            } else if(score[i] == top && count == 3) {
                res[i] = "Bronze Medal";
            } else if(score[i] == top && count >= 4) {
                res[i] = to_string(count);
            }
        }
        count += 1;
    }
    
    return res;
}

int main() {
    vector<int> score = {10, 3, 8, 9, 4};
    vector<string> res = findRelativeRanks(score);
    
    for(string s : res) {
        cout<<s<<" ";
    }
}