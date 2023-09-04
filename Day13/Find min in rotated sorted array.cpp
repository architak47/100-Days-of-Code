#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int>& nums) {
    int start = 0, end = nums.size() - 1;
    int mid, n = nums.size(), ans = INT_MAX;

    while(start <= end){
        if(nums[start] < nums[end]){
            ans = min(ans,nums[start]);
            break;
        } 
        mid = start + (end - start)/2;
        if (nums[start] <= nums[mid]) {
            ans = min(ans, nums[start]);
            start = mid + 1;
        }
        else {
            ans = min(ans, nums[mid]);
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << "\n";

    return 0;
}