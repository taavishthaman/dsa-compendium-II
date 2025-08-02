
#include<bits/stdc++.h>
using namespace std;

class Compare {
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    }
};

int minSetSize(vector<int>& arr) {
        // your code goes here
    int n = arr.size();
    unordered_map<int, int> m;
    
    for(int num : arr) {
        m[num]++;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
    
    for(auto p : m) {
        q.push(p);
    }
    
    int totalElements = n;
    int count = 0;
    while(!q.empty()) {
        int frq = q.top().second;
        totalElements -= frq;
        count++;
        
        if(totalElements <= n / 2) {
            return count;
        }
    }
    
    return count;
}

