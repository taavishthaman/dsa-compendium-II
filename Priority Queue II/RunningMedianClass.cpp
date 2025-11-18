#include<bits/stdc++.h>
using namespace std;

//Note : Don't Edit the class name and given methods. 
// Add helper methods or any properties if needed.
class MedianHandler{
public:
    float median;
    priority_queue<int> leftheap;
    priority_queue<int, vector<int>, greater<int>> rightheap;
    
    void push(int number){
        //Complete this method to update median after every insertion 
        //Edge case
        if(leftheap.size() == 0 && rightheap.size() == 0) {
            leftheap.push(number);
            return;
        }
        
        if(leftheap.size() > rightheap.size()) {
            if(number < median) {
                rightheap.push(leftheap.top());
                leftheap.pop();
                leftheap.push(number);
            } else {
                rightheap.push(number);
            }
            
            median = (leftheap.top() + rightheap.top()) / 2.0;
        } else if (leftheap.size() == rightheap.size()) {
            if(number < median) {
                leftheap.push(number);
                median = leftheap.top();
            } else {
                rightheap.push(number);
                median = rightheap.top();
            }
        } else {
            if(number < median) {
                leftheap.push(number);
            } else {
                leftheap.push(rightheap.top());
                rightheap.pop();
                rightheap.push(number);
            }
            
            median = (leftheap.top() + rightheap.top()) / 2.0;
        }
    }
    float getMedian(){
        //Complete this , Should return the median in O(1) time
        return median;
    }
};