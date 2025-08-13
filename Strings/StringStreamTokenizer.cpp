#include <bits/stdc++.h>
using namespace std;

int main() {
   string input;
   getline(cin, input);
   
   stringstream ss(input);
   
   string token;
   vector<string> tokens;
   
   while(getline(ss, token, ' ')) {
       tokens.push_back(token);
   }
   
   for(string str : tokens) {
       cout<<str<<", ";
   }
}