#include <bits/stdc++.h>
using namespace std;

int joinRopes(vector<int> & ropes) {
    priority_queue<int, vector<int>, greater<int>> heap;
    
    for(int rope : ropes) {
        heap.push(rope);
    }
    
    int total = 0;
    
    while(heap.size() > 1) {
        int first = heap.top();
        heap.pop();
        int second = heap.top();
        heap.pop();
        int sum = first + second;
        heap.push(sum);
        total += sum;
    }
    
    return total;
}

int main()
{
    vector<int> ropes = {4,3,2,6};
    
    cout<<joinRopes(ropes)<<endl;
    return 0;
}