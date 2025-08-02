#include <bits/stdc++.h>
using namespace std;

vector<string> arr = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void numberSpell(int n) {
    if(n == 0) return;
    
    int last_digit = n % 10;
    n = n / 10;
    numberSpell(n);
    cout<<arr[last_digit]<<" ";
}

int main() {
    int n;
    cin>>n;
    numberSpell(n);
}