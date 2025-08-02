#include <bits/stdc++.h>
using namespace std;

int tillingProblem(int n, int m){
    if(n <= m - 1) return 1;
    
    return tillingProblem(n-1, m) + tillingProblem(n-m, m);
}

int main() {
    int n, m;
    cin>>n>>m;
    
    int result = tillingProblem(n, m);
    cout<<"Result is "<<result<<endl;
}