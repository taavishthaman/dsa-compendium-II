#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Dereference variable is exactly the opposite of &
    //&bucket => Address
    //*Address => Bucket
    int x = 10;
    int * xPtr = &x;
    cout<<*xPtr<<endl;
    
    int * nullPtr = 0;
    cout<<*nullPtr<<endl;
}