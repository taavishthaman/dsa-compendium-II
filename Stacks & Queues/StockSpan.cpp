#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterToLeft(vector<int> arr) {
    int n = arr.size();
    stack<int> s;
    vector<int> op;
    
    op.push_back(-1);
    s.push(0);
    
    for(int i=1; i<n; i++) {
        while(!s.empty() && arr[i] > arr[s.top()]) {
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

vector<int> stockSpan(vector<int> v) {
    //Write your code here. Do not modify the function or parameters.
    vector<int> ngl = nextGreaterToLeft(v);
    int n = ngl.size();
    
    for(int i=0; i<n; i++) {
        ngl[i] = i - ngl[i];
    }
    
    return ngl;
}

int main()
{
    vector<int> v = {100, 80, 60, 70, 60, 75, 85};
    
    vector<int> span = stockSpan(v);
    
    for(int num : span) {
        cout<<num<<", ";
    }
    return 0;
}