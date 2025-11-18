#include <bits/stdc++.h>
using namespace std;

class Car {
public:
    string id;
    int x, y;
    
    Car(string id, int x, int y) {
        this->id = id;
        this->x = x;
        this->y = y;
    }
    
    int dist() const {
        return x*x + y*y;
    }
};

class Compare {
public:
    bool operator()(const Car c1, const Car c2) {
        return c1.dist() < c2.dist();
    }
};

void printNearestCars(vector<Car> v, int N, int k) {
    
    priority_queue<Car, vector<Car>, Compare> heap(v.begin(), v.begin() + k); //Construct a Max Heap
    
    for(int i=k; i<N; i++) {
        Car c = v[i];
        
        if(c.dist() < heap.top().dist()) {
            heap.pop();
            heap.push(c);
        }
    }
    
    vector<string> res;
    
    while(!heap.empty()) {
        res.push_back(heap.top().id);
        heap.pop();
    }
    
    reverse(res.begin(), res.end());
    
    for(string x : res) {
        cout<<x<<", ";
    }
}

/*
5
3
C1 1 1
C2 2 1
C3 3 2
C4 0 1
C5 2 3
*/

int main()
{
    int N, k;
    cin>>N>>k;
    vector<Car> v;
    
    for(int i=0; i<N; i++) {
        string id;
        int x, y;
        cin>>id>>x>>y;
        
        Car c(id, x, y);
        v.push_back(c);
    }
    
    printNearestCars(v, N, k);
    
    return 0;
}