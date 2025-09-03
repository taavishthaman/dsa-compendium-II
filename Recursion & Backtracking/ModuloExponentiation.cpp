#include <bits/stdc++.h>
using namespace std;

long long int powerModulo(int a, int b){
    //Write your code here. Do not modify the function or parameters. Use helper functions if needed.
    if(b == 0) {
        return 1;
    }
    
    long long int halfPower = powerModulo(a, b/2);
    long long int fullPower = halfPower * halfPower;
    if(b % 2 == 1) {
        return ((a % 1000000007) * (fullPower % 1000000007)) % 1000000007;
    } else {
        return fullPower % 1000000007;
    }
}

int main()
{
    int a, b;
    cin>>a>>b;
    cout<<powerModulo(a, b)<<endl;
    return 0;
}