#include <bits/stdc++.h>
using namespace std;
 
int power(int x, int y, int mod)
{
    // your code goes here
    int res = 1;
    while(y > 0) {
        int last_bit = y & 1;
        if(last_bit == 1) {
            res = res * x;
        }
        x = x * x;
        y = y >> 1;
    }
    
    return res % mod;
}

int main()
{
    int x, y, mod;
    cin>>x;
    cin>>y;
    cin>>mod;
    
    int result = power(x, y, mod);
    
    cout<<"Result is "<<result<<endl;

    return 0;
}