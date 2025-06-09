#include <bits/stdc++.h>
using namespace std;
int main()
{
    char arr[100] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', '\0'};
    char arr2[] = "abcdefhg";
    cout<<arr<<endl;
    cout<<arr2<<endl;
    //Sizeof would give an output 1 more than 
    cout<<"STRLEN "<<strlen(arr2)<<endl;
    cout<<"SIZEOF "<<sizeof(arr2)<<endl;
    char arr3[100];
    cin>>arr3;
    cout<<arr3;
    return 0;
}