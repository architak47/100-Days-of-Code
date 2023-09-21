#include <iostream>
#include <vector>

using namespace std; 

void subset(vector<int> &nums, int i, vector<int> &sub, vector<vector<int>> &ans) {
    ans.push_back(sub);
    for (int j = i; j < nums.size(); j++) {
        sub.push_back(nums[j]);
        subset(nums, j + 1, sub, ans);
        sub.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> subs;
    vector<int> sub;
    subset(nums, 0, sub, subs);
    return subs;
}

int main() {
    vector<int> nums = {1, 2, 3}; 

    vector<vector<int>> result = subsets(nums);

    cout << "All subsets of the input vector are:" << endl;
    for (const auto &subset : result) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
