#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n == 0){
        return 0;
    }
    sort(begin(nums), end(nums));
    int seq = nums[0];
    int len = 1, ans = 1;

    for(int i = 1; i < n; i++){
        if(seq + 1 == nums[i]){
            len++;
        }
        else if(nums[i] != seq){
            len = 1;
        }
        seq = nums[i];
        ans = max(len, ans);
    }
    return ans;
}

int main()
{
  vector<int> arr = {100,4,200,1,3,2};

  cout << longestConsecutive(arr);

    return 0;
}
