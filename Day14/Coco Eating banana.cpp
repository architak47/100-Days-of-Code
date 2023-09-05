#include<bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1, right = 1000000000;

    while(left < right){
        int mid = (left + right) / 2;
        int sum = 0;

        for(int it : piles){
            sum += (it + mid-1)/mid;
        }
        if(sum > h){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return left;
}

int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minEatingSpeed(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}
