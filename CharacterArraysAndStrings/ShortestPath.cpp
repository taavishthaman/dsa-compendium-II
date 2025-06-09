#include <bits/stdc++.h>
using namespace std;

int main()
{
    // string str = "SNNNEWE";
    char directions[1000];
    cin.getline(directions, 1000);
    
    int x = 0, y = 0;
    
    for(int i=0; directions[i] != '\0'; i++) {
        char ch = directions[i];
        switch(ch) {
            case 'S':
                y--;
                break;
            case 'N':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
        }    
    }
    
    string res = "";
    
    while(x != 0) {
        if(x < 0) {
            res += 'W';
            x++;
        } else {
            res += 'E';
            x--;
        }
    }
    
    while(y != 0) {
        if(y < 0) {
            res += 'S';
            y++;
        } else {
            res += 'N';
            y--;
        }
    }
    
    cout<<res<<endl;

    return 0;
}