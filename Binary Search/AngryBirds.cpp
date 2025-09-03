#include <bits/stdc++.h>
using namespace std;

bool canPlaceBirds(vector<int> nests, int B, int dist) {
    int n = nests.size();
    int last_location = nests[0];
    int birds = 1;
    
    for(int i=1; i<n; i++) {
        int current_dist = nests[i] - last_location;
        
        if(current_dist >= dist) {
            birds++;
            last_location = nests[i];
            if(birds == B) {
                return true;
            }
        }
    }
    
    return false;
}

int angry_birds(vector<int> nests, int B) {
    int n = nests.size();
    sort(nests.begin(), nests.end());
    
    int s = 0;
    int e = nests[n-1] - nests[0];
    
    int result = -1;
    
    while(s <= e) {
        int mid = (s + e) / 2;
        
        bool canPlace = canPlaceBirds(nests, B, mid);
        
        if(canPlace) {
            result = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    
    return result;
}

int main()
{
    int B = 3;
    vector<int> nests = {1, 2, 4, 8, 9};
    int result = angry_birds(nests, B);
    cout<<"Maxmium possible separation is "<<result<<endl;
    return 0;
}