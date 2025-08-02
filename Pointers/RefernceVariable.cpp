#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Reference variable is a variable that points to the original variable, essentially it is the original variable
    int x = 10;
    int &y = x;
    y++; //Incrementing y will also increment x, because x and y are the same variable
    cout<<x<<", "<<y<<endl;
}