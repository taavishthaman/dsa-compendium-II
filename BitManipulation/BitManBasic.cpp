#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 5;
    int b = 7;
    
    cout<<(a & b)<<endl;
    cout<<(a | b)<<endl;
    
    //XOR ^, if both bits are same result is 0, if both bits are different result is 1
    cout<<(1^0)<<endl;
    cout<<(1^1)<<endl;
    
    //NOT ~, NOT of 0 is -1 because 0 at memory level is represented by 32 bits of zeroes. 
    //Doing a not of them would result in -1 since all 32 bits would be flipped
    cout<<(~0)<<endl; //-1
    cout<<(~1)<<endl; //-2

    return 0;
}