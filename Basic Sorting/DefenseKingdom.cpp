#include<bits/stdc++.h>
using namespace std;

int defkin(int W, int H, vector<pair<int, int>> position)
{
    // your code goes here
    vector<int> x;
    vector<int> y;
    for(auto p : position) {
        cout<<p.first<<", "<<p.second<<endl;
    }
    
    for(auto p : position) {
        x.push_back(p.first);
        y.push_back(p.second);
    }
    x.push_back(0);
    y.push_back(0);
    x.push_back(W+1);
    y.push_back(H+1);
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    int max_width = 0;
    int max_height = 0;
    
    for(int i=1; i < x.size(); i++) {
        max_width = max(max_width, x[i] - x[i-1]);
        max_height = max(max_height, y[i] - y[i-1]);
    }
    
    int max_area = (max_width - 1) * (max_height - 1);
    
    return max_area;
}
