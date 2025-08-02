#include <bits/stdc++.h>
using namespace std;

void findPermutations(string s, int i) {
    if(i == s.size() - 1) {
        cout<<s<<", ";
        return;
    }
    
    for(int j=i; j<s.size(); j++) {
        swap(s[i], s[j]);
        findPermutations(s, i+1);
        swap(s[i], s[j]);
    }
}

int main()
{
    string s;
    cin>>s;
    
    findPermutations(s, 0);

    return 0;
}