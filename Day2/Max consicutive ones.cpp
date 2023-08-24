#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int cnt = 0, max_cnt = 0;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 1){
            cnt++;
        }
        else{
            cnt = 0;
        }
        max_cnt = max(cnt, max_cnt);
    }
    return max_cnt;
}


int main()
{
    vector<int> arr = {1,0,1,1,0,1};
    
    cout << findMaxConsecutiveOnes(arr);
    
    return 0;
}
