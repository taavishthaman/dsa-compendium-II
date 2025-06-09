#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    // your code goes here
    int n = str.size();
    bool isPalin = true;
    for(int i=0; i<n/2; i++) {
        if(str[i] != str[n-1-i]) {
            isPalin = false;
            break;
        }
    }
    
    return isPalin;
}