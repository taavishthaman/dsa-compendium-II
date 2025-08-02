#include<bits/stdc++.h>
using namespace std;

int earthLevel(int k)
{
    //your code goes here
    int steps = 0;
    int power = 1;
    
    while(k != 0) {
        while(power <= k) {
            power = power << 1;
        }
        
        power = power >> 1;
        k = k - power;
        power = 1;
        steps++;
    }
    
    return steps;
}