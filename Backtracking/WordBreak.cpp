#include <bits/stdc++.h>
using namespace std;

int countWays(string str, unordered_set<string> & collection, int i, int j) {
    if(j == str.size() && j == i) return 1;
    
    if(j == str.size() && j != i) return 0;
    
    string sub = str.substr(i, j-i+1);
    
    int ans = 0;
    
    if(collection.find(sub) != collection.end()) {
        ans += countWays(str, collection, j+1, j+1);
    }
    
    ans += countWays(str, collection, i, j+1);
    return ans;
}

int wordBreak(string str, vector<string> &dictionary){
    unordered_set<string> collection;
    
    for(string str : dictionary) {
        collection.insert(str);
    }
    
    int result = countWays(str, collection, 0, 0);
    
    return result;
}

int main() {
    string str = "ilikesamsungmobile";
    vector<string> dictionary = {"i", "like", "sam", "sung", "samsung", "mobile"};
    
    int result = wordBreak(str, dictionary);
    cout<<"Result is "<<result<<endl;
}