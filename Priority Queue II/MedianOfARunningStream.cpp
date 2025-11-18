#include <bits/stdc++.h>
using namespace std;

void runningMedian(vector<int> & nums) {
    int n = nums.size();
    
    priority_queue<int> leftheap;
    priority_queue<int, vector<int>, greater<int>> rightheap;
    
    float med = nums[0];
    leftheap.push(nums[0]);
    cout<<med<<" ";
    
    for(int i=1; i<n; i++) {
        int num = nums[i];
        if(leftheap.size() > rightheap.size()) {
            if(num < med) {
                rightheap.push(leftheap.top());
                leftheap.pop();
                leftheap.push(num);
            } else {
                rightheap.push(num);
            }
            
            med = (leftheap.top() + rightheap.top()) / 2.0;
            cout<<med<<" ";
        } else if (leftheap.size() == rightheap.size()) {
            if(num < med) {
                leftheap.push(num);
                med = leftheap.top();
            } else {
                rightheap.push(num);
                med = rightheap.top();
            }
            cout<<med<<" ";
        } else {
            if(num < med) {
                leftheap.push(num);
            } else {
                leftheap.push(rightheap.top());
                rightheap.pop();
                rightheap.push(num);
            }
            
            med = (leftheap.top() + rightheap.top()) / 2.0;
            cout<<med<<" ";
        }
    }
}

int main()
{
    vector<int> nums = {10,5,2,3,0,12,18,20,22};
    
    runningMedian(nums);
    return 0;
}