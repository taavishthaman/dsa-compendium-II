#include <bits/stdc++.h>
using namespace std;

bool checkIfPowerOfTwo(int n) {
    //8 => 1000
    //7 => 0111
    return (n & (n-1)) == 0;
}

int main()
{
    int n;
    cin>>n;
    bool result = checkIfPowerOfTwo(n);
    if(result == true) {
        cout<<n<<" is a power of 2"<<endl;
    } else {
        cout<<n<<" is not a power of 2"<<endl;
    }
    
    return 0;
}