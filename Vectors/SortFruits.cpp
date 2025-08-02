#include<bits/stdc++.h>
using namespace std;

bool compare_price(pair<string, int> p1, pair<string, int> p2) {
    return p1.second < p2.second;
}

bool compare_string(pair<string, int> p1, pair<string, int> p2) {
    return p1.first < p2.first;
}

vector<pair<string,int>> sortFruits(vector<pair<string,int>> v, string S){
    // your code  goes here
    if(S == "price") {
        sort(v.begin(), v.end(), compare_price);
    } else {
        sort(v.begin(), v.end(), compare_string);
    }
    
    return v;
}