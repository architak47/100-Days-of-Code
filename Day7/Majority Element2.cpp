#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    int cnt1 = 0, cnt2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN;

    for(int i = 0; i < n; i++){
        if(cnt1 == 0 and ele2 != nums[i]){
            cnt1 = 1;
            ele1 = nums[i];
        }
        else if(cnt2 == 0 and ele1 != nums[i]){
            cnt2 = 1;
            ele2 = nums[i];
        }
        else if(ele1 == nums[i]){
            cnt1++;
        }
        else if(ele2 == nums[i]){
            cnt2++;
        }
        else{
            cnt1--, cnt2--;
        }
    }
    cnt1 = 0, cnt2 = 0;
    vector<int> ans;

    for(int i = 0; i < n; i++){
        if(nums[i] == ele1){
            cnt1++;
        }
        if(nums[i] == ele2){
            cnt2++;
        }
    }
    int num = (n/3) + 1;
    if(cnt1 >= num){
        ans.push_back(ele1);
    }
    if(cnt2 >= num){
        ans.push_back(ele2);
    }
    return ans;
}

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";

    return 0;
}
