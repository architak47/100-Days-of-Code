#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums, int x) {
    int total = 0;
    for(int num : nums) total += num;
    int maxi = -1, curr = 0;
    for(int i = 0, r = 0; r < nums.size(); r++){
        curr += nums[r];
        while(i <= r and curr > total - x){
            curr -= nums[i++];
        }
        if(curr == total - x){
            maxi = max(maxi, r - i + 1);
        }
    }
    return maxi == -1? -1:nums.size() - maxi;
}

int main()
{
    vector<int> v = {1,1,4,2,3};
    int x = 5;
    
    cout <<  minOperations(v, x);

    return 0;
}
