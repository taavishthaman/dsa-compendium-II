#include <bits/stdc++.h>
using namespace std;

int gridWays(int i, int j, int n, int m) {
    if(i == n-1 && j == m-1) {
        return 1;
    }
    
    if(i >= n || j >= m) {
        return 0;
    }
    
    int result = gridWays(i+1, j, n, m) + gridWays(i, j+1, n, m);
    
    return result;
}

int factorial(int num) {
    if(num == 1) return 1;
    
    return num * factorial(num - 1);
}

int gridWaysFast(int n, int m) {
    /*
        [][][]
        [][][]
        [][][]
        
        In a 3X3 grid every solution would be a permutation of RRDD, could be RDRD or DRDR
        The result would be of form 4!/(2! * 2!)
        
        The general result would be of type (n + m - 2) / ((n-1)! * (m-1)!)
    */
    
    int numerator = factorial(n + m - 2);
    int denominator = factorial(n - 1) * factorial(m - 1);
    
    return numerator / denominator;
}

int main()
{
    int n, m;
    cin>>n>>m;
    int result = gridWays(0, 0, n, m);
    cout<<"Total ways : "<<result<<endl;
    int result2 = gridWaysFast(n, m);
    cout<<"Total ways : "<<result2<<endl;

    return 0;
}