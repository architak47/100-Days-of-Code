#include <bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) {
int start = 0, end = nums.size() - 1;
int mid;
while(start <= end){
    mid = (start + end) >> 1;
    if(nums[mid] == target) return true;
    else if((nums[mid] == nums[start]) and (nums[end] == nums[mid])){
        start++;
        end--;
    }
    else if(nums[start] <= nums[mid]){
        if((nums[start] <= target) and (nums[mid] > target)){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    else{
        if((nums[mid] < target) and (nums[end] >= target)){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
}
return false;
}


int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;
    bool ans = search(arr, k);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";
    return 0;
}
