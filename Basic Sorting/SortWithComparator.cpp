#include<bits/stdc++.h>
using namespace std;

vector<int> sortingWithComparator(vector<int> a, bool flag){
    // your code  goes here
    if(flag == true) {
        sort(a.begin(), a.end());
    } else {
        sort(a.begin(), a.end(), greater<int>());
    }
    
    return a;
}