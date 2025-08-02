#include <bits/stdc++.h>
using namespace std;

void decreasing(int n) {
    if(n == 0) {
        cout<<endl;
        return;
    }
    
    cout<<n<<", ";
    decreasing(n-1);
}

void increasing(int n) {
    if(n == 0) {
        return;
    }
    
    increasing(n-1);
    cout<<n<<", ";
}

int main()
{
    int n = 5;
    decreasing(n);
    increasing(n);
    return 0;
}