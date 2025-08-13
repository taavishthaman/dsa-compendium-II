#include <bits/stdc++.h>
using namespace std;

void replaceSpace(char * str) {
    int n = strlen(str);
    int spaces = 0;
    
    for(int i=0; i<n; i++) {
        if(str[i] == ' ') {
            spaces += 1;
        }
    }
    
    int idx = n + 2 * spaces;
    str[idx] = '\0';
    
    for(int i=n-1; i >= 0; i--) {
        char ch = str[i];
        if(ch == ' ') {
            str[idx-1] = '0';
            str[idx-2] = '2';
            str[idx-3] = '%';
            idx -= 3;
        } else {
            str[idx-1] = str[i];
            idx--;
        }
    }
}

int main() {
   char input[1000];
   cin.getline(input, 1000);
   replaceSpace(input);
   cout<<input<<endl;
}