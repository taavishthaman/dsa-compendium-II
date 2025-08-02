#include<bits/stdc++.h>
using namespace std;

class Compare {
public:
    bool operator()(int a, int b) {
        return a < b;
    }
};

int main() {
    vector<int> arr = {10,15,20,13,6,90};
    //By default a max heap would be created
    // priority_queue<int, vector<int>, greater<int>> heap;
    priority_queue<int, vector<int>, Compare> heap;
    
    for(int num : arr) {
        heap.push(num);
    }
    
    while(!heap.empty()) {
        int t = heap.top();
        cout<<t<<", ";
        heap.pop();
    }
}