#include <bits/stdc++.h>
using namespace std;

bool canweplace(vector<int> v, int mid, int k){
    int cntCows = 1, last = v[0];
    for(int i = 1; i < v.size(); i++){
        if(v[i] - last >= mid){
            cntCows++;
            last = v[i];
        }
        if(cntCows >= k) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n-1] - stalls[0];
    
    while(low <= high){
        int mid = (low + high) / 2;
        if(canweplace(stalls, mid, k)){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";

    return 0;
}
