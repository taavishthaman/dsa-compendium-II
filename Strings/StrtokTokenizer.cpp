#include <bits/stdc++.h>
using namespace std;

int main() {
    char str[1000];
    cin.getline(str, 1000);
    
    char * token = strtok(str, " ");
    
    while(token != NULL) {
        cout<<token<<", ";
        token = strtok(NULL, " ");
    }
}