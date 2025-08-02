#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<string> books;
    
    books.push("C++");
    books.push("Python");
    books.push("Java");
    books.push("O.S.");
    
    while(!books.empty()) {
        cout<<books.top()<<", ";
        books.pop();
    }
}