#include <bits/stdc++.h>
using namespace std;

float square_root(int N, int p) {
    float ans = 0;
    
    int s = 0, e = N;
    
    while(s <= e) {
        int mid = (s + e) / 2;
        
        if(mid * mid == N) {
            return mid;
        } else if (mid * mid < N) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    
    float inc = 0.1;
    for(int place = 1; place <= p; place++) {
        while(ans * ans <= N) {
            ans += inc;
        }
        
        ans -= inc;
        inc = inc / 10.0;
    }
    
    return ans;
}

int main() {
    int N, p;
    cin>>N>>p;
    float result = square_root(N, p);
    cout<<result<<endl;
    return 0;
}