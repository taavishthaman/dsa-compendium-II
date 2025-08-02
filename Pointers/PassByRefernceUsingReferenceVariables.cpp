#include <bits/stdc++.h>
using namespace std;

//Pass by reference using refrence variables
void applyTax(int & money) {
    float tax = 0.1;
    money = money - tax * money;
}

int main()
{
    int income = 100;
    cout<<income<<endl;
    applyTax(income);
    cout<<income<<endl;
}