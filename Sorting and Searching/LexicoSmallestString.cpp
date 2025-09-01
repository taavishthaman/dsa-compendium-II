#include <bits/stdc++.h>
using namespace std;

bool compare(string s1, string s2) {
    return s1 + s2 < s2 + s1;
}

int main() {
    vector<string> arr = {"a", "ab", "aba"};
    
    sort(arr.begin(), arr.end(), compare);
    
    for(string str : arr) {
        cout<<str;
    }
    return 0;
}