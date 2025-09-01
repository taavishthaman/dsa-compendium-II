#include <bits/stdc++.h>
using namespace std;

bool compare(pair<string, int> p1, pair<string, int> p2) {
    return p1.second < p2.second;
}

int badness(vector<pair<string,int> > teams){
    //Complete this function to return the min badness
    sort(teams.begin(), teams.end(), compare);
    
    int b = 0;
    for(int i=0; i<teams.size(); i++) {
        b += abs(teams[i].second - (i+1));
    }
    
    return b;
}

int main() {
    vector<pair<string, int>> v = {
        {"WinOrBooze", 1},
        {"BallOfDuty", 2},
        {"WhoKnows", 2},
        {"BholeChature", 1},
        {"DCECoders", 5},
        {"StrangeCase", 7},
        {"WhoKnows", 7}
    };
    
    int result = badness(v);
    cout<<"Badness is "<<result<<endl;
    return 0;
}