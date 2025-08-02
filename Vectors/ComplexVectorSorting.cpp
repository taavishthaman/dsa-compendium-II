#include <bits/stdc++.h>
using namespace std;

int calculate_total_marks(vector<int> v) {
    return v[0] + v[1] + v[2];
}

bool compare(pair<string, vector<int>> s1, pair<string, vector<int>> s2) {
    vector<int> s1_marks = s1.second;
    vector<int> s2_marks = s2.second;
    
    return s1_marks > s2_marks;
}

int main() {
    vector<pair<string, vector<int>>> student_marks = {
        {"Rohan", {10, 20, 11}},
        {"Prateek", {10, 21, 3}},
        {"Vivek", {4, 5, 6}},
        {"Rijul", {10, 13, 20}}
    };
    
    sort(student_marks.begin(), student_marks.end(), compare);
    
    for(auto s : student_marks) {
        cout<<s.first<<", ";
    }
}