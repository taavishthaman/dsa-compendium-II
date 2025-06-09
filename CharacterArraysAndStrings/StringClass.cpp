#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    // getline(cin, s);
    // cout<<s<<endl;
    //getline is used to take a string input and the third argument is a delimiter.
    getline(cin, s, '.');
    cout<<s<<endl;
    
    vector<string> sarr;
    int n;
    cout<<"Enter the number of strings"<<endl;
    cin>>n;
    string temp;
    cin.get();
    while(n != 0) {
        getline(cin, temp);
        sarr.push_back(temp);
        n--;
    }
    
    for(string s : sarr) {
        cout<<s<<", ";
    }

    return 0;
}