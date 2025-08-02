#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterToLeft(vector<int> & v) {
    int n = v.size();
    stack<int> s;
    vector<int> op;
    
    s.push(0);
    op.push_back(-1);
    
    for(int i=1; i<n; i++) {
        int curr = v[i];
        while(!s.empty() && curr >= v[s.top()]) {
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

vector<int> stockSpanner(vector<int> &stocks){
	vector<int> ngl = nextGreaterToLeft(stocks);
	
	vector<int> span;
	
	for(int i=0; i<stocks.size(); i++) {
	    int curr_span = i - ngl[i];
	    
	    span.push_back(curr_span);
	}
	
	return span;
}