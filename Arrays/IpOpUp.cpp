#include <bits/stdc++.h>
using namespace std;

int main() {
    int marks[100] = {0};
    int n;
    cout<<"Enter the number of students"<<endl;
    cin>>n;
    marks[0] = -1;
    
    for(int i=0; i<=n; i++) {
        cin>>marks[i];
    }
    
    for(int i=1; i<=n; i++) {
        cout<<"Marks of student "<<i<<" "<<marks[i]<<endl;
    }
}