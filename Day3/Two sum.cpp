#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans = {-1, -1};
    int n = nums.size();
    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++){
        int remain = target - nums[i]; 
        if(mp.find(remain) != mp.end()){
            ans[0] = mp[remain];
            ans[1] = i;
        }
        else{
            mp[nums[i]] = i;
        }
    }
    return ans;
}
      

int main()
{
    vector<int> v = {2,7,11,15};
    int target = 9;
    vector<int> ans = twoSum(v, target);
    
    cout << ans[0] << ' ' << ans[1];
    
    return 0;
}
