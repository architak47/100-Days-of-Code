#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = nums[0], pre = 0, suf = 0;
        for (int i = 0; i < n; i++) {
            pre =  (pre ? pre : 1) * nums[i];
            suf =  (suf ? suf : 1) * nums[n - 1 - i];
            res = max(res, max(pre, suf));
        }
        return res;
    }

int main()
{
    vector<int> arr = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray is: " << maxProduct(arr) << "\n";

    return 0;
}
