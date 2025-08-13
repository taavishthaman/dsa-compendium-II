#include<bits/stdc++.h>
using namespace std;

int earthLevel(int k)
{
    //your code goes here
    int power = 0;
    int steps = 0;
    
    while(k > 0) {
        int factor = pow(2, power);
        while(factor <= k) {
            power += 1;
            factor = pow(2, power);
        }
        
        factor = factor / 2;
        k -= factor;
        steps += 1;
        power = 0;
    }
    
    return steps;
}