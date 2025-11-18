#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {10,15,20,13,6,90};
    
    //priority_queue<int> heap; //Max Heap by default
    priority_queue<int, vector<int>, greater<int>> heap;
    
    for(int num : arr) {
        heap.push(num);
    }
    
    while(!heap.empty()) {
        cout<<heap.top()<<endl;
        heap.pop();
    }

    return 0;
}