#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
    if(n == 1 || n == 0) {
        return n;
    }
    
    int f1 = fibonacci(n-1);
    int f2 = fibonacci(n-2);
    
    return f1 + f2;
}

int main()
{
    int n;
    cin>>n;
    int result = fibonacci(n);
    cout<<"Result is..."<<result<<endl;

    return 0;
}