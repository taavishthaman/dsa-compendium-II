#include <bits/stdc++.h>
using namespace std;

bool checkIfOdd(int num) {
    return num & 1 == 1 ? true : false;
}

int main()
{
    int x;
    cin>>x;
    int res = checkIfOdd(x);
    if(res == true) {
        cout<<"Number is Odd"<<endl;
    } else {
        cout<<"Number is Even"<<endl;
    }
    return 0;
}