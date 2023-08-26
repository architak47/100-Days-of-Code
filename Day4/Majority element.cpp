#include<bits/stdc++.h>
using namespace std;

 int majorityElement(vector<int>& nums) {
    int n = nums.size(), cnt = 1, ans = nums[0];
    
    for(int i = 1; i < n; i++){
        if(cnt == 0){
            cnt++;
            ans = nums[i];
        }
        else if(ans == nums[i]){
            cnt++;
        }
        else{
            cnt--;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(arr);

    return 0;
}
