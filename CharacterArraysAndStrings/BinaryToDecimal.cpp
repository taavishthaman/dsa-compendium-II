#include <iostream>
#include <string>
#include<cmath>
using namespace std;
 
int binaryToDecimal(string s)
{
    // your code goes here
    int res = 0;
    
    int n = s.size();
    int power = 0;
    
    for(int i=n-1; i>=0; i--) {
        char ch = s[i];
        int digit = ch - '0';
        
        res += digit * pow(2, power);
        power += 1;
    }
    
    return res;
}
 