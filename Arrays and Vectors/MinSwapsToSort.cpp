#include<bits/stdc++.h>
using namespace std;

int countMinSwaps(vector<int> v) {
    int n = v.size();
    vector<pair<int, int>> pv;
    
    for(int i=0; i<n; i++) {
        pv.push_back({v[i], i});
    }
    
    sort(pv.begin(), pv.end());
    int ans = 0;
    
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++) {
        if(visited[i] || pv[i].second == i) continue;
        
        int node = i;
        int cycles = 0;
        
        while(!visited[node]) {
            visited[node] = true;
            node = pv[node].second;
            cycles += 1;
        }
        
        ans += (cycles - 1);
    }
    
    return ans;
}

int main() {
    vector<int> v = {5,4,3,2,1};
    int result = countMinSwaps(v);
    cout<<"Result is "<<result<<endl;
}