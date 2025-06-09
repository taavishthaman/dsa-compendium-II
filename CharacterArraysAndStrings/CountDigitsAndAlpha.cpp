#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ch;
    ch = cin.get();
    
    int count_alpha = 0;
    int count_digits = 0;
    int count_spaces = 0;
    
    while(ch != '\n') {
        if(ch >= '0' && ch <= '9') {
            count_digits += 1;
        } else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            count_alpha += 1;
        } else if(ch == ' ') {
            count_spaces += 1;
        }
        ch = cin.get();
    }
    
    cout<<"Count Alphabets "<<count_alpha<<endl;
    cout<<"Count Digits "<<count_digits<<endl;
    cout<<"Count Spaces "<<count_spaces<<endl;

    return 0;
}