#include <bits/stdc++.h>
using namespace std;

class Point {
public:
    int x, y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class Compare {
public:
    bool operator()(const Point p1, const Point p2) {
        if(p1.x == p2.x) {
            return p1.y < p2.y;
        }
        return p1.x < p2.x;
    }
};

int countRectangles(vector<Point> points) {
    set<Point, Compare> s;
    
    for(Point p : points) {
        s.insert(p);
    }
    
    int count = 0;
    
    for(auto it = s.begin(); it != prev(s.end()); it++) {
        for(auto jt = next(it); jt != s.end(); jt++) {
            Point p1 = *it;
            Point p2 = *jt;
            
            if(p1.x == p2.x || p1.y == p2.y) {
                continue;
            }
            
            Point p3(p2.x, p1.y);
            Point p4(p1.x, p2.y);
            
            if(s.find(p3) != s.end() && s.find(p4) != s.end()) {
                count += 1;
            }
        }
    }
    
    return count / 2;
}

/*
8
4 1
4 0
0 0
0 1
1 1
1 0
2 0
2 1
*/

int main()
{
    vector<Point> points;
    int N;
    cin>>N;
    
    for(int i=0; i<N; i++) {
        int x, y;
        cin>>x>>y;
        
        Point p(x,y);
        points.push_back(p);
    }
    
    cout<<countRectangles(points)<<endl;
    return 0;
}