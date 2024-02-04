#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n % 3 != 0) return {};
        int i = 0;
        int first, second, third;
        while (i < n) {
            vector<int> temp;
            first = nums[i];
            ++i;
            if (i < n) {
                second = nums[i];
                ++i;
            } else return {};
            if (i < n) {
                third = nums[i];
                ++i;
            } else return {};
            if (third - first <= k) {
                temp.push_back(first);
                temp.push_back(second);
                temp.push_back(third);
            } else {
                return {};
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<int> nums = {1, 2, 3, 5, 6, 7, 9, 10, 11};
    int k = 2;

    vector<vector<int>> result = solution.divideArray(nums, k);

    if (!result.empty()) {
        cout << "Arrays with consecutive elements having a difference less than or equal to " << k << ":" << endl;
        for (const auto& arr : result) {
            cout << "[";
            for (int num : arr) {
                cout << num << " ";
            }
            cout << "]" << endl;
        }
    } else {
        cout << "No valid arrays found." << endl;
    }

    return 0;
}
