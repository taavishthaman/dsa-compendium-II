#include <bits/stdc++.h>
using namespace std;

bool canDivideAmongK(vector<int> arr, int friends, int amount) {
    int partitions = 0;
    int current_friend = 0;
    
    int n = arr.size();
    
    for(int i=0; i<n; i++) {
        if(current_friend + arr[i] >= amount) {
            partitions += 1;
            current_friend = 0;
        } else {
            current_friend += arr[i];
        }
    }
    
    return partitions >= friends;
}

int divideAmongK(vector<int> arr, int friends) {
    //We must not sort the array, because the partitions need to match the original order of the array
    int s = 0, e = 0, res = -1;
    
    for(int num : arr) {
        e += num;
    }
    
    while(s <= e) {
        int mid = (s + e) / 2;
        
        bool canDivide = canDivideAmongK(arr, friends, mid);
        if(canDivide) {
            res = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    
    return res;
}

int main()
{
    vector<int> arr = {1,2,3,4};
    int friends = 3;
    int result = divideAmongK(arr, friends);
    cout<<"Partitions => "<<result<<endl;
    return 0;
}