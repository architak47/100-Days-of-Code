#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int k = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] != 0){
            swap(nums[i], nums[k]);
            k++;
        }
    }
}

int main()
{
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << ' ';
    }

    return 0;
}
