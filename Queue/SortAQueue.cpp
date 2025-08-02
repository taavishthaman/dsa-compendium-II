#include <bits/stdc++.h>
using namespace std;

int findMinIndex(queue<int> & q, int sortedIndex) {
    int n = q.size();
    
    int minIndex = -1;
    int minElement = INT_MAX;
    
    for(int i=0; i<n; i++) {
        int f = q.front();
        q.pop();
        
        if(f < minElement && i <= sortedIndex) {
            minElement = f;
            minIndex = i;
        }
        
        q.push(f);
    }
    
    return minIndex;
}

void insertMinAtEnd(queue<int> & q, int minIndex) {
    int n = q.size();
    int data;
    for(int i=0; i<n; i++) {
        int f = q.front();
        q.pop();
        
        if(i == minIndex) {
            data = f;
        } else {
            q.push(f);
        }
    }
    
    q.push(data);
}

queue<int> sortqueue(queue<int> & q) {
    int n = q.size();
    
    for(int i=0; i<n; i++) {
        int minIndex = findMinIndex(q, n-1-i);
        insertMinAtEnd(q, minIndex);
    }
    
    return q;
}

int main()
{
    queue<int> q;
    
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);
    
    sortqueue(q);
    
    while(!q.empty()) {
        int data = q.front();
        cout<<data<<", ";
        q.pop();
    }

    return 0;
}