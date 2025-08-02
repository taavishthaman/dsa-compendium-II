#include <bits/stdc++.h>
using namespace std;

int findMaxScore(vector<int> a, vector<int> b, vector<int> c, int i, int prevArrIdx) {
    if(i == a.size()) {
        return 0;
    }
    
    int ans = 0;
    
    int max_value = 0;
    int new_array_index = 0;
    //Calculates Max Value
    for(int k=1; k<=3; k++) {
        if(prevArrIdx != k) {
            if(k == 1) {
                if(a[i] > max_value) {
                    max_value = max(max_value, a[i]);
                    new_array_index = k;
                }
            } else if(k == 2) {
                if(b[i] > max_value) {
                    max_value = max(max_value, b[i]);
                    new_array_index = k;
                }
                
            } else if(k == 3) {
                if(c[i] > max_value) {
                    max_value = max(max_value, c[i]);
                    new_array_index = k;
                }
            }
        }
        
    }
    
    ans += findMaxScore(a, b, c, i+1, new_array_index) + max_value;
    return ans;
}

int vacation(vector<int> a, vector<int> b, vector<int> c) {
    int score = findMaxScore(a,b,c,0,0);
    return score;
}

int main()
{
    vector<int> a = {10, 20, 30};
    vector<int> b = {40, 50, 60};
    vector<int> c = {70, 80, 90};
    
    cout<<vacation(a,b,c)<<endl;
    return 0;
}