#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[1000] = "apple";
    char b[1000];
    
    //Length of string
    cout<<"Length is => "<<strlen(a)<<endl;
    
    //Copy string using strcpy(dest, src)
    strcpy(b, a);
    cout<<"Copied value is "<<b<<endl;
    
    //Compare
    int value = strcmp(b, a);
    if(value == 0) {
        cout<<"Strings are the same"<<endl;
    }
    
    char web[] = "www.";
    char domain[] = "codingminutes.com";
    
    //Concatenate strings using strcat
    strcpy(b, strcat(web, domain));
    cout<<b<<endl;
    
    cout<<strcmp(b, a)<<endl;

    return 0;
}