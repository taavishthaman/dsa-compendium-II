#include <bits/stdc++.h>
using namespace std;

vector<int> sortBalls(vector<int> balls){
    //sort the balls in place in a single pass (O(N) time, O(1) space)
    int n = balls.size();
    int i = 0, j = 0, k = n-1;
    
    while(j < k) {
        if(balls[j] == 0) {
            swap(balls[i], balls[j]);
            i++;
            j++;
        } else if (balls[j] == 1) {
            j++;
        } else {
            swap(balls[j], balls[k]);
            k--;
        }
    }
    return balls;
}

int main() {
    vector<int> balls = {0, 0, 1, 2, 0, 1, 2, 0};
    vector<int> sortedBalls = sortBalls(balls);
    
    for(int num : sortedBalls) {
        cout<<num<<", ";
    }
    return 0;
}