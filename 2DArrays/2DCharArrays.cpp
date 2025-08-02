#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Each row will be null terminated
    char numbers[][10] = {
        "one",
        "two",
        "three",
        "fourty",
        "eight",
        "hundered"
    };
    
    int i = 3;
    cout<<numbers[i][3]<<endl;
    
    for(int i=0; i<6; i++) {
        cout<<numbers[i]<<endl;
    }
    return 0;
}