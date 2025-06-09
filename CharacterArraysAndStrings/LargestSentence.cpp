#include <bits/stdc++.h>
using namespace std;

int main()
{
    char sentence[1000];
    char largest[1000];
    int n;
    cin>>n;
    cin.get();
    
    int max_length = 0;
    
    while(n != 0) {
        cin.getline(sentence, 1000);
        int curr_len = strlen(sentence);
        
        if(curr_len > max_length) {
            max_length = curr_len;
            strcpy(largest, sentence);
        }
        
        n--;
    }
    
    cout<<"Largest sentence is "<<sentence<<endl;

    return 0;
}