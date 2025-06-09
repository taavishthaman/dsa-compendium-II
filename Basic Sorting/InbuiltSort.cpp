#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main()
{
    vector<int> v = {10,9,8,6,5,4,3,2,11,16,8};
    
    // sort(v.begin(), v.end(), compare);
    sort(v.begin(), v.end(), greater<int>());
    
    for(int num : v) {
        cout<<num<<", ";
    }

    return 0;
}