#include <bits/stdc++.h>
using namespace std;

pair<int, int> findMinDiffPair(vector<int> a1, vector<int> a2) {
    sort(a2.begin(), a2.end());
    pair<int, int> res = {-1,-1};
    int diff = INT_MAX;
    
    for(int num : a1) {
        int lb = lower_bound(a2.begin(), a2.end(), num) - a2.begin();
        
        if(lb >= 1 && num - a2[lb-1] < diff) {
            diff = num - a2[lb-1];
            res.first = a2[lb-1];
            res.second = num;
        }
        
        if(lb != a2.size() && a2[lb] - num < diff) {
            diff = a2[lb] - num;
            res.first = num;
            res.second = a2[lb];
        }
    }
    
    return res;
}

int main()
{
    vector<int> a1 = {-1,5,10,20,3};
    vector<int> a2 = {26,134,135,15,17};
    /*
        lower_bound() => Finds the iterator to the element greater than or equal to target
        upper_bound() => Finds the iterator to the element strictly greater than the target
    */
    
    pair<int,int> p = findMinDiffPair(a1, a2);
    cout<<"["<<p.first<<", "<<p.second<<"]"<<endl;
    return 0;
}