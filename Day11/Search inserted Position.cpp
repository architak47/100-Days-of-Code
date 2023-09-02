#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int mid = (low + high) / 2;

    while(low <= high){
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
        mid = (low + high)/2;
    }
    return low;
}

int main()
{
    vector<int> arr = {1,3,5,6};
    int x = 5;
    cout << searchInsert(arr, x);

    return 0;
}
