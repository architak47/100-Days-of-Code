#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int n = nums.size();
    
    sort(begin(nums), end(nums));

    for(int i = 0; i < n; i++){
        long long rem = target - nums[i];
        for(int j = i+1; j < n; j++){
            long long rem2 = rem - nums[j];
            int left = j+1, right = n-1;
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum < rem2){
                    left++;
                }
                else if(sum > rem2){
                    right--;
                }
                else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);

                    ans.push_back(temp);
                    left++, right--;
                    while(nums[left] == nums[left-1] and left < right)left++;
                    while(nums[right] == nums[right+1] and left < right)right--;
                }
            }
            while(j+1 < n and nums[j] == nums[j+1]) j++;
        }
        while(i+1 < n and nums[i] == nums[i+1]) i++;
    }
    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";

    return 0;
}
