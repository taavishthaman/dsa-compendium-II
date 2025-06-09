#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
    // your code goes here
    int count = 1;
    int n = chars.size();
    int i = 0;
    int j = 0;
    for(i=0; i < n-1; i++) {
        if(chars[i] != chars[i+1]) {
            if(count == 1) {
                chars[j] = chars[i];
                j++;
            } else {
                chars[j] = chars[i];
                string count_str = to_string(count);
                j++;
                for(char ch : count_str) {
                    chars[j] = ch;
                    j++;
                }
            }
            count = 1;
        } else {
            count++;
        }
    }
    
    if(count == 1) {
        chars[j] = chars[i];
        j++;
    } else {
        chars[j] = chars[i];
        string count_str = to_string(count);
        j++;
        for(char ch : count_str) {
            chars[j] = ch;
            j++;
        }
    }
    
    for(int i=0; i<j; i++) {
        cout<<chars[i];
    }
    
    return j;
}

int main()
{
    vector<char> v = {'a', 'a', 'a', 'b', 'b', 'c', 'c', 'd'};
    compress(v);

    return 0;
}