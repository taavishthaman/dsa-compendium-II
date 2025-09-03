#include <bits/stdc++.h>
using namespace std;

int findMaxValue(vector<int> & v, int n, int l, int r) {
    if(l > r) {
        return 0;
    }
    
    int pick_left = v[l] + min({(findMaxValue(v, n, l+2, r), findMaxValue(v, n, l+1, r-1))});
    int pick_right = v[r] + min({findMaxValue(v, n, l+1, r-1), findMaxValue(v, n, l, r-2)});
    
    return max(pick_left, pick_right);
}

int MaxValue(int n, vector<int> v){
//Write your code here. Do not modify the function or parameters. You can use a helper function if needed.
    return findMaxValue(v, n, 0, n-1);
}

int main()
{
    vector<int> v = {1,2,3,4};
    int n = v.size();
    
    cout<<MaxValue(n, v)<<endl;
    
    return 0;
}