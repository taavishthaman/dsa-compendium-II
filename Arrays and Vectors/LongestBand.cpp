#include<bits/stdc++.h>
using namespace std;

int longestChain(vector<int> v) {
    int n = v.size();
    unordered_set<int> s;
    int largest = 0;
    
    for(int num : v) {
        s.insert(num);
    }
    
    for(int num : s) {
        int prev = num - 1;
        
        if(s.find(prev) == s.end()) {
            int next = num + 1;
            int cnt = 1;
            
            while(s.find(next) != s.end()) {
                next++;
                cnt++;
            }
            
            largest = max(largest, cnt);
        }
    }
    
    return largest;
}

int main() {
    vector<int> v = {1,9,3,0,18,5,2,4,10,7,12,6};
    int result = longestChain(v);
    cout<<"Result is "<<result<<endl;
}