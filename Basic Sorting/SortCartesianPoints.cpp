#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first == p2.first) {
        return p1.second < p2.second;
    }
    
    return p1.first < p2.first;
}

vector<pair<int, int>> sortCartesian(vector<pair<int, int>> v)
{
    int N = v.size();
    // your code goes here
    sort(v.begin(), v.end(), compare);
    
    return v;
}