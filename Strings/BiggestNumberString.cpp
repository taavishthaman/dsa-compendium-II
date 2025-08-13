#include<bits/stdc++.h>
using namespace std;

bool compare(int num1, int num2) {
    return to_string(num1) + to_string(num2) > to_string(num2) + to_string(num1);
}

string concatenate(vector<int> numbers){
    //complete this method and return the largest number you can form as a string
    sort(numbers.begin(), numbers.end(), compare);
    
    string res = "";
    
    for(int num : numbers) {
        res += to_string(num);
    }
    
    return res;
}