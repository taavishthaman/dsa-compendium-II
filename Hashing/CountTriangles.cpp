#include <bits/stdc++.h>
using namespace std;

int countTriangles(vector<pair<int, int>> points, int N) {
    unordered_map<int, int> freq_x;
    unordered_map<int, int> freq_y;
    
    for(auto p : points) {
        freq_x[p.first]++;
        freq_y[p.second]++;
    }
    
    int total = 0;
    
    for(int i=0; i<N; i++) {
        int x = points[i].first;
        int y = points[i].second;
        
        int cnt_x = freq_x[x];
        int cnt_y = freq_y[y];
        total += (cnt_x - 1) * (cnt_y - 1);
    }
    
    return total;
}

/*
5
1 2
2 1
2 2
2 3
3 2
*/

int main()
{
    vector<pair<int, int>> points;
    
    int N;
    cin>>N;
    
    for(int i=0; i<N; i++) {
        int x, y;
        cin>>x>>y;
        
        pair<int, int> p = {x, y};
        points.push_back(p);
    }
    
    int result = countTriangles(points, N);
    cout<<"Total triangles are "<<result<<endl;

    return 0;
}