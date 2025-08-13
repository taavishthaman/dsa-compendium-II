#include<vector>
using namespace std;

int maxSubarraySum(vector<int> arr){
    //Complete this function, your function should return the maximum subarray sum
    int n = arr.size();
    
    int max_sum = 0;
    int curr_sum = 0;
    
    for(int i=0; i<n; i++) {
        curr_sum += arr[i];
        
        if(curr_sum < 0) {
            curr_sum = 0;
        }
        
        max_sum = max(max_sum, curr_sum);
    }
    
    return max_sum;
}