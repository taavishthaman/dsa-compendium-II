#include <bits/stdc++.h>
using namespace std;
 
bool arePermutation(string A, string B)
{
    // your code goes here
    if(A.size() != B.size()) return false;
    
    vector<int> frq(26, 0);
    
    for(char ch : A) {
        int value = ch - 'a';
        frq[value]++;
    }
    
    for(char ch : B) {
        int value = ch - 'a';
        frq[value]--;
    }
    
    for(int num : frq) {
        if(num != 0) return false;
    }
    
    return true;
}