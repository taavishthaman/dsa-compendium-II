#include <bits/stdc++.h>
using namespace std;

vector<string> keypad = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void printKeypadOutput(string input, string output, int i) {
    
    if(input[i] == '\0') {
        cout<<output<<endl;
        return;
    }
    
    int num = input[i] - '0';
    if(num == 0 || num == 1) {
        printKeypadOutput(input, output, i+1);
    }
    string keys = keypad[num];
    
    for(int k=0; k<keys.size(); k++) {
        printKeypadOutput(input, output + keys[k], i+1);
    }
}

int main()
{
    string input;
    cin>>input;
    
    printKeypadOutput(input, "", 0);
    return 0;
}