#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallestToLeft(vector<int> v) {
    int n = v.size();
    vector<int> op;
    stack<int> s;
    
    op.push_back(-1);
    s.push(0);
    
    for(int i=1; i<n; i++) {
        int curr = v[i];
        
        while(!s.empty() && curr <= v[s.top()]) {
            s.pop();
        }
        
        if(s.empty()) {
            op.push_back(-1);
        } else {
            op.push_back(s.top());
        }
        
        s.push(i);
    }
    
    return op;
}

vector<int> nextSmallestToRight(vector<int> v) {
    int n = v.size();
    
    vector<int> op;
    stack<int> s;
    
    op.push_back(n);
    s.push(v.size() - 1);
    
    for(int i=n-2; i >= 0; i--) {
        int curr = v[i];
        
        while(!s.empty() && curr <= v[s.top()]) {
            s.pop();
        }
        
        if(s.empty()) {
            op.insert(op.begin(), n);
        } else {
            op.insert(op.begin(), s.top());
        }
        
        s.push(i);
    }
    
    return op;
}
 
int getMaxArea(vector<int> hist){
    vector<int> nsl = nextSmallestToLeft(hist);
    vector<int> nsr = nextSmallestToRight(hist);
    
    int max_area = 0;
    int n = hist.size();
    
    for(int i=0; i<n; i++) {
        int base = (nsr[i] - nsl[i] - 1);
        int height = hist[i];
        int area = base * height;
        
        max_area = max(max_area, area);
    }
    
    return max_area;
}

int main() {
    vector<int> v = {6, 2, 5, 4, 5, 1, 6};
    
    int result = getMaxArea(v);
    
    cout<<"Result "<<result<<endl;
}