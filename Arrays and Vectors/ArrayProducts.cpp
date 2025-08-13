#include<vector>
using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    
    //update the output array and return
    //complete the code
    output[0] = arr[0];
    
    for(int i=1; i<n; i++) {
        output[i] = output[i-1] * arr[i];
    }
    
    int mult = 1;
    
    for(int i=n-1; i>0; i--) {
        int res = output[i-1] * mult;
        mult = mult * arr[i];
        output[i] = res;
    }
    
    output[0] = mult;
    
    
    return output;
}