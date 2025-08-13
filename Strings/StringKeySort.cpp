#include <bits/stdc++.h>
using namespace std;

string extractStringAtKey(string str, int key) {
    stringstream ss(str);
    
    string token;
    vector<string> tokens;
    
    while(getline(ss, token, ' ')) {
        tokens.push_back(token);
    }
    
    return tokens[key-1];
}

bool numericCompare(pair<string, string> p1, pair<string, string> p2) {
    return stoi(p1.second) < stoi(p2.second);
}

bool lexicoCompare(pair<string, string> p1, pair<string, string> p2) {
    return p1.second < p2.second;
}

int main() {
    int n;
    cin>>n;
    cin.get(); //Consumes the extra \n, because while taking input we'll press enter key
    
    string temp;
    vector<string> arr;
    
    for(int i=0; i<n; i++) {
        getline(cin, temp); //Also includes space between string that the 
        arr.push_back(temp);
    }
    
    int key;
    string reversal;
    string ordering;
    cin>>key>>reversal>>ordering;
    
    vector<pair<string, string>> vp;
    
    for(int i=0; i<n; i++) {
        vp.push_back({arr[i], extractStringAtKey(arr[i], key)});
    }
    
    if(ordering == "numeric") {
        sort(vp.begin(), vp.end(), numericCompare);
    } else {
        sort(vp.begin(), vp.end(), lexicoCompare);
    }
    
    vector<string> result;
    for(auto p : vp) {
        result.push_back(p.first);
    }
    
    if(reversal == "true") {
        reverse(result.begin(), result.end());
    }
    
    for(string s : result) {
        cout<<s<<endl;
    }
}

/*
3
92 022
82 12
77 13
2 false numeric
*/