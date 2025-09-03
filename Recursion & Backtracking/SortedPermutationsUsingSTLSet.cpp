#include <bits/stdc++.h>
using namespace std;

void permutations(string str, int i, set<string> & s) {
    if(i == str.size() - 1) {
        s.insert(str);
        return;
    }
    
    for(int j=i; j<str.size(); j++) {
        swap(str[i], str[j]);
        permutations(str, i+1, s);
        swap(str[i], str[j]);
    }
}

vector<string> findSortedPermutations(string s){
    set<string> se;
    vector<string> v;
    
    permutations(s, 0, se);
    for(string str : se) {
        v.push_back(str);
    }
    
    return v;
}

int main()
{
    string str;
    cin>>str;
    vector<string> arr = findSortedPermutations(str);
    
    for(string s : arr) {
        cout<<s<<", ";
    }
    return 0;
}