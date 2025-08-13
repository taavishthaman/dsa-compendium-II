#include <bits/stdc++.h>
using namespace std;

int main() {
   string paragraph = "We are learning about STL strings. STL strings are quite powerful.";
   
   string target;
   getline(cin,target);
   
   int first_occ = paragraph.find(target);
   if(first_occ != -1) {
       cout<<"First Occurence "<<first_occ<<endl;
   }
   
   int second_occ = paragraph.find(target, first_occ + 1);
   if(second_occ != -1) {
       cout<<"Second Occurence "<<second_occ<<endl;
   }
}