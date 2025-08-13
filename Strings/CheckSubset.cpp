#include <bits/stdc++.h>
using namespace std;

bool isSubset(string s1, string s2) {
     int i = s1.size() - 1;
    int j = s2.size() - 1;
    
    while(i >= 0 && j >= 0) {
        if(s1[i] == s2[j]) {
            j--;
        }
        i--;
    }
    
    return j == -1;
}

int main() {
    string s1 = "coding minutes";
    string s2 = "cines";
    
   bool result = isSubset(s1, s2);
   if(result == true) {
       cout<<s2<<" is a subset of "<<s1<<endl;
   } else {
       cout<<"Not a subset"<<endl;
   }
}