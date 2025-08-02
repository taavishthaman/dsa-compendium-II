#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Address-Of operator => &, address are stored in hexadecimal
    //To store the address you need a pointer variable which initializes with a *
    
    int x = 10;
    float y = 5.5;
    
    int * xPtr = &x;
    float * yPtr = &y;
    
    cout<<xPtr<<endl;
    cout<<yPtr<<endl;
    
    //We can also create pointer to a pointer using **
    int ** xxPtr = &xPtr;
    cout<<&xPtr<<", "<<xxPtr<<endl;
    return 0;
}