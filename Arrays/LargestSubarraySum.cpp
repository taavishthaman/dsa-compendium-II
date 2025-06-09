#include <bits/stdc++.h>
using namespace std;

int subArraySum1(int * arr, int n) {
    int max_sum = 0;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            int subarray_sum = 0;
            for(int k = i; k <= j; k++) {
                subarray_sum += arr[k];
            }
            max_sum = max(max_sum, subarray_sum);
        }
    }
    
    return max_sum;
}

int subArraySum2(int * arr, int n) {
    int prefix[n] = {0};
    prefix[0] = arr[0];
    for(int i=1; i<n; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }
    
    int max_sum = 0;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            int curr_sub_sum = i > 0 ? prefix[j] - prefix[i-1] : prefix[j];
            max_sum = max(max_sum , curr_sub_sum);
        }
    }
    
    return max_sum;
}

int kadane(int * arr, int n) {
    int largest = 0;
    int curr_sum = 0;
    for(int i=0; i<n; i++) {
        curr_sum += arr[i];
        
        if(curr_sum < 0) {
            curr_sum = 0;
        }
        
        largest = max(curr_sum, largest);
    }
    
    return largest;
}

int main() {
    int arr[] = {-2,3,4,-1,5,-12,6,1,3};
    int n = sizeof(arr) / sizeof(int);
    int sub_sum_1 = subArraySum1(arr, n);
    cout<<"Subarray Sum One "<<sub_sum_1<<endl;
    int sub_sum_2 = subArraySum2(arr, n);
    cout<<"Subarray Sum Two "<<sub_sum_2<<endl;
    int sub_sum_3 = kadane(arr, n);
    cout<<"Subarray Sum Three "<<sub_sum_3<<endl;
}