#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            dfs(low, high, i, 0, ans);
        }
        sort(begin(ans), end(ans));
        return ans;
    }

    void dfs(int low, int high, int digit, int num, vector<int>& sequences) {
        if (num >= low && num <= high) {
            sequences.push_back(num);
        }
        if (num > high || digit > 9) {
            return;
        }
        dfs(low, high, digit + 1, num * 10 + digit, sequences);
    }
};

int main() {
    Solution solution;

    // Example test case
    int low = 100;
    int high = 300;

    vector<int> result = solution.sequentialDigits(low, high);

    cout << "Sequential digits between " << low << " and " << high << ":" << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
