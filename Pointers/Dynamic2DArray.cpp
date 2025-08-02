#include <bits/stdc++.h>
using namespace std;

int ** create2DArray(int rows, int cols) {
    int ** arr = new int * [rows];
    
    //Allocate memory of each row
    for(int i=0; i<rows; i++) {
        arr[i] = new int[cols];
    }
    
    int value = 0;
    
    for(int i=0; i < rows; i++) {
        for(int j=0; j < cols; j++) {
            arr[i][j] = value;
            value++;
        }
    }
    
    return arr;
}

int main()
{
    int r, c;
    cin>>r>>c;
    int ** arr = create2DArray(r, c);
    
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout<<arr[i][j]<<", ";
        }
        cout<<endl;
    }

    return 0;
}