#include <bits/stdc++.h>
using namespace std;

void findSubsets(char * input, char * output, int i, int j, vector<string> & list) {
    if(input[i] == '\0') {
        output[j] = '\0';
        string temp(output);
        list.push_back(output);
        return;
    }
    
    output[j] = input[i];
    //Include ith character in output array
    findSubsets(input, output, i+1, j+1, list);
    //Exclude ith character, since we don't increment j, output[j] will be overwritten in the next recursive call
    findSubsets(input, output, i+1, j, list);
}

bool compare(string s1, string s2) {
    if(s1.length() == s2.length()) return s1 < s2;
    
    return s1.length() < s2.length();
}

int main()
{
    char input[100];
    char output[100];
    cin>>input;
    vector<string> list;
    findSubsets(input, output, 0, 0, list);
    
    sort(list.begin(), list.end(), compare);
    for(string s : list) {
        cout<<s<<", ";
    }

    return 0;
}