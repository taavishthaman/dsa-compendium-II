#include<bits/stdc++.h>
using namespace std;

bool isPowerOftwo(int num) {
    //Why this works
    //16 in binary => 10000
    //15 in binary => 01111
    //Anding them together would make 0
    return (num) & (num-1) == 0;
}

int main() {
    int num;
    cin>>num;
    bool result = isPowerOftwo(num);
    if(result == true) {
        cout<<num<<" is a power of 2"<<endl;
    } else {
        cout<<num<<" is not a power of 2"<<endl;
    }
}