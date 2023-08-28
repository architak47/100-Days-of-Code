#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin() , nums.end());
    vector<vector<int>> vec;
    
    for(int i = 0 ; i < nums.size()-2; i++){
        
        if(i==0 || (i > 0 && nums[i] != nums[i-1])){
            int start = i+1;
            int end = nums.size()-1;
            int sum = 0 - nums[i];
            
            while(start < end){
                 if(nums[start] + nums[end] == sum){
                     
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[start]);
                    temp.push_back(nums[end]);
                     
                    vec.push_back(temp);
                    
                    while(start < end && nums[start] == nums[start+1]) start++;
                    while(start < end && nums[end] == nums[end-1]) end--;
                    start++;
                    end--;
                }
                else if(nums[start] + nums[end-1] < sum){
                    start++;
                }
                else end--;      
            }
        }
    }
    return vec;
   
}

int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";

    return 0;
}
