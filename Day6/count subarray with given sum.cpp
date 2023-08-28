#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0, sum = 0;
    unordered_map<int, int> mp;
    mp.insert({0,1});

    for(int i = 0; i < n; i++){
        sum += nums[i];
        auto it = mp.find(sum-k);
        if(it != mp.end()){
            ans += it->second;
        }
        it = mp.find(sum);
        if(it != mp.end()){
            it->second++;
        }
        else{
            mp.insert({sum, 1});
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
  
    cout<<subarraySum(arr, k);

    return 0;
}
