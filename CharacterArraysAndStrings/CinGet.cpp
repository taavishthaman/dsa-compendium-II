#include <bits/stdc++.h>
using namespace std;
int main()
{
    char arr[100];
    char temp = cin.get();
    
    int len = 0;
    while(temp != '#') {
        arr[len++] = temp;
        temp = cin.get();
    }
    cout<<endl;
    arr[len] = '\0';
    
    cout<<"Length "<<len<<endl;
    cout<<arr<<endl;
    return 0;
}