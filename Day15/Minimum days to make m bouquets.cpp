#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& V, int m, int k, int mid){
    int tot = 0, cnt = 0;
    for(int i = 0; i < V.size(); i++){
        if(V[i] <= mid){
            cnt++;
            if(cnt == k){
                tot++;
                cnt = 0;
            }
        }
        else{
            cnt = 0;
        }
    }
    if(tot >= m){
        return true;
    }
    return false;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    int start = 0, end = INT_MAX-1;
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(check(bloomDay, m, k, mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = minDays(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";

    return 0;
}
