#include <bits/stdc++.h>
using namespace std;

//This is a min heap
class Heap {
    vector<int> arr;
    
    void heapify(int i) {
        int c1 = 2 * i;
        int c2 = 2 * i + 1;
        
        int minIndex = i;
        
        if(c1 < arr.size() && arr[c1] < arr[minIndex]) {
            minIndex = c1;
        }
        if(c2 < arr.size() && arr[c2] < arr[minIndex]) {
            minIndex = c2;
        }
        
        if(minIndex != i) {
            heapify(minIndex);
        }
    }
    
public:
    Heap(int default_size = 10) {
        arr.reserve(default_size);
        arr.push_back(-1);
    }
    
    void push(int data) {
        arr.push_back(data);
        int index = arr.size() - 1;
        int parent = index / 2;
        
        while(index > 1 && v[index] < v[parent]) {
            swap(v[index], v[parent]);
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
    
    bool isEmpty() {
        return arr.size() == 1;
    }
};

int main()
{
    

    return 0;
}