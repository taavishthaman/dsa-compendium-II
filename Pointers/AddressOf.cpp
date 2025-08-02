#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Address-Of operator => &, address are stored in hexadecimal
    //To store the address you need a pointer variable which initializes with a *
    
    int x = 10;
    int * y = &x;
    cout<<&x<<", "<<y<<endl;
    return 0;
}