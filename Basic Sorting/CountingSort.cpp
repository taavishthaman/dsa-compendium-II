#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> & v) {
    int largest = 0;
    for(int num : v) {
        largest = max(largest, num);
    }

    vector<int> count(largest + 1, 0);
    
    for(int num : v) {
        count[num]++;
    }
    
    int index = 0;
    
    for(int i=0; i<largest+1; i++) {
        while(count[i] > 0) {
            v[index] = i;
            count[i]--;
            index++;
        }   
    }
}

int main()
{
    vector<int> v = {88, 97, 10, 12, 15, 1, 5, 6, 12, 5, 8};
    
    counting_sort(v);
    for(int num : v) {
        cout<<num<<", ";
    }
    return 0;
}