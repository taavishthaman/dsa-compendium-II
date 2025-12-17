#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> v1, vector<int> v2) {
    return v1[2] < v2[2];
}

bool isSmaller(vector<int> curr_box, vector<int> comp_box) {
    if(comp_box[0] < curr_box[0] && comp_box[1] < curr_box[1] && comp_box[2] < curr_box[2]) {
        return true;
    }
    return false;
}

int boxStackingBu(vector<vector<int>> & boxes) {
    int n = boxes.size();
    sort(boxes.begin(), boxes.end(), compare);
    
    vector<int> dp(n, 0);
    for(int i=0; i<n; i++) {
        dp[i] = boxes[i][2];
    }
    
    int max_height = 0;
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            vector<int> curr_box = boxes[i];
            vector<int> comp_box = boxes[j];
            
            if(isSmaller(curr_box, comp_box)) {
                dp[i] = max(dp[i], dp[j] + curr_box[2]);
                max_height = max(max_height, dp[i]);
            }
        }
    }
    
    return max_height;
}

int main()
{
    vector<vector<int>> boxes = {
        {2,1,2},
        {3,2,3},
        {2,2,8},
        {2,3,4},
        {2,2,1},
        {4,4,5}
    };
    
    int resBu = boxStackingBu(boxes);
    cout<<"Res BU "<<resBu<<endl;
    return 0;
}