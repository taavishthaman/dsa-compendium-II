#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> & s, int data) {
    if(s.size() == 0) {
        s.push(data);
    }
    
    int curr = s.top();
    s.pop();
    insertAtBottom(s, data);
    s.push(curr);
}

void reverseStack(stack<int> & s) {
    if(s.empty()) {
        return;
    }
    
    int curr = s.top();
    s.pop();
    reverseStack(s);
    s.push(curr);
}

int reverse(int n){
	stack<int> s;
	
	while(n != 0) {
	    int num = n % 10;
	    n = n / 10;
	    
	    s.push(num);
	}
	
	reverseStack(s);
	
	int res = 0;
	int power = 0;
	
	while(!s.empty()) {
	    int curr = s.top();
	    s.pop();
	    res += curr * pow(10, power);
	    power += 1;
	}
	
	return res;
}

int main() {
    int n = 543;
    int res = reverse(n);
    cout<<res<<endl;
    
}