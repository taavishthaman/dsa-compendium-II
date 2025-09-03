#include <bits/stdc++.h>
using namespace std;

void generateBrackets(int N, string s, int open, int close) {
    if(s.size() == 2 * N) {
        cout<<s<<endl;
        return;
    }
    
    if(open < N) {
        generateBrackets(N, s + '(', open + 1, close);
    }
    
    if(close < open) {
        generateBrackets(N, s + ')', open, close + 1);
    }
}

int main()
{
    int N;
    cin>>N;
    generateBrackets(N, "", 0, 0);
    return 0;
}