#include <bits/stdc++.h>
using namespace std;

int sparse_search(vector<string> & arr, string target) {
    int n = arr.size();
    int s = 0;
    int e = arr.size() - 1;
    
    while(s <= e) {
        int mid = (s + e) / 2;
        
        if(arr[mid] == ""){
            //Update the mid
            int left = mid-1;
            int right = mid+1;
            
            while(true) {
                if(left < s && right > e) {
                    return -1;
                }
                else if(left >= s && arr[left] != "") {
                    mid = left;
                    break;
                } else if(right <= e && arr[right] != "") {
                    mid = right;
                    break;
                }
                
                left--;
                right++;
            }
            
        }
        if(arr[mid] == target) {
            return mid;
        }
        else if(target < arr[mid]) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    
    return -1;
}

int main() {
    vector<string> arr = {"ai","","","bat","","","car","cat","","","dog",""};
    string target;
    cin>>target;
    int result = sparse_search(arr, target);
    cout<<"Result is "<<result<<endl;
    return 0;
}