#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
    vector<int> arr;
    
    void heapify(int i) {
        int left = 2 * i;
        int right = 2 * i + 1;
        
        int maxIndex = i;
        
        if(left < arr.size() && arr[maxIndex] < arr[left]) {
            maxIndex = left;
        }
        if(right < arr.size() && arr[maxIndex] < arr[right]) {
            maxIndex = right;
        }
        
        if(maxIndex != i) {
            swap(arr[i], arr[maxIndex]);
            heapify(maxIndex);
        }
    }
    
public:
    MaxHeap(int default_size = 10) {
        arr.reserve(default_size);
        arr.push_back(-1);
    }
    
    void push(int data) {
        arr.push_back(data);
        int index = arr.size() - 1;
        int parent = index / 2;
        
        while(index > 1 && arr[parent] < arr[index]) {
            swap(arr[index], arr[parent]);
            index = parent;
            parent = parent / 2;
        }
    }
    
    int top() {
        return arr[1];
    }
    
    void pop() {
        swap(arr[1], arr[arr.size() - 1]);
        arr.pop_back();
        
        heapify(1);
    }
    
    bool empty() {
        return arr.size() == 1;
    }
};


int maxProduct(vector<int>& nums) {
    // your code goes here
    MaxHeap h;
    int n = nums.size();
    
    for(int i=0; i<n; i++) {
        h.push(nums[i]);
    }
    
    int largest = h.top();
    h.pop();
    int secondLargest = h.top();
    h.pop();
    
    return (largest - 1) * (secondLargest - 1);
}



