#include <bits/stdc++.h>
using namespace std;

int friendsParty(int n) {
    if(n <= 1) return 1;
    
    //If one guy decides to go alone, then the subproblem would be reduced to n-1
    //If one guy decides to pair up, he can pair up with n-1 people, and then the subproblem will be reduces to n-2
    return friendsParty(n-1) + (n-1) * friendsParty(n-2);
}

int main()
{
    int n;
    cin>>n;
    
    int result = friendsParty(n);
    cout<<"Result is "<<result<<endl;

    return 0;
}