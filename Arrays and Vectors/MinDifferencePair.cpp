#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


pair<int,int> minDifference(vector<int> a,vector<int> b){
    //Complete this method
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int i = 0, j = 0;
    int min_diff = INT_MAX;
    pair<int, int> min_diff_pair;
    int n = a.size();
    int m = b.size();
    
    while(i < n && j < m) {
        int curr_diff = abs(a[i] - b[j]);
        if(curr_diff < min_diff) {
            min_diff = curr_diff;
            min_diff_pair.first = a[i];
            min_diff_pair.second = b[j];
        }
        
        if(a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    while(i < n) {
        int curr_diff = abs(a[i] - b[j]);
        if(curr_diff < min_diff) {
            min_diff = curr_diff;
            min_diff_pair.first = a[i];
            min_diff_pair.second = b[j];
        }
        i++;
    }
    
    while(j < m) {
        int curr_diff = abs(a[i] - b[j]);
        if(curr_diff < min_diff) {
            min_diff = curr_diff;
            min_diff_pair.first = a[i];
            min_diff_pair.second = b[j];
        }
        j++;
    }
    
    return min_diff_pair;
}