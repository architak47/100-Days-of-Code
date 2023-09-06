#include <bits/stdc++.h>
using namespace std;

bool canShip(vector<int>& weights, int days, int capacity){
    int sum = 0, cnt = 1;
    for(auto &weight : weights){
        sum += weight;
        if(sum > capacity){
            sum = weight;
            ++cnt;
        }
    }
    return cnt <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int sum = 0;
    int maxi = 0;
    for(auto &weight : weights){
        sum += weight;
        maxi = max(maxi, weight);
    }
    int left = maxi, right = sum;
    while(left <= right){
        int mid = (left + right) >> 1;
        if(canShip(weights, days, mid)){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = shipWithinDays(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";

    return 0;
}
