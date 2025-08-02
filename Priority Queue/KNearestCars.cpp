#include<bits/stdc++.h>
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

class CarCompare {
public:
    bool operator()(Car c1, Car c2) {
        return c1.dist() < c2.dist();
    }
};

vector<Car> printNearestCars(vector<Car> cars, int k) {
    priority_queue<Car, vector<Car>, CarCompare> heap(cars.begin(), cars.begin() + k);
    
    for(int i=k; i<cars.size(); i++) {
        Car currentCar = cars[i];
        
        if(currentCar.dist() < heap.top().dist()) {
            heap.pop();
            heap.push(currentCar);
        }
    }
    vector<Car> nearest;
    while(!heap.empty()) {
        Car c = heap.top();
        nearest.push_back(c);
        heap.pop();
    }
    
    return nearest;
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
int main() {
    int N, k;
    
    cin>>N>>k;
    
    string id;
    int x, y;
    
    vector<Car> cars;
    
    for(int i=0; i<N; i++) {
        cin>>id;
        cin>>x>>y;
        
        Car car(id, x, y);
        cars.push_back(car);
    }
    
    vector<Car> nearest = printNearestCars(cars, k);
    for(auto car : nearest) {
        cout<<car.id<<endl;
    }
}



