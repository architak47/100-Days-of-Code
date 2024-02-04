#include <bits/stdc++.h>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.size() < t.size()) return "";
        std::unordered_map<char, int> mp;
        for (auto it : t) mp[it]++;
        int i = 0, j = 0, mini = INT_MAX;
        std::string ans = "";
        int count = mp.size();

        while (j < s.size()) {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    count--;
                }
            }
            if (count == 0) {
                if (mini > j - i + 1) {
                    mini = j - i + 1;
                    ans = s.substr(i, mini);
                }
                while (count == 0) {
                    if (mp.find(s[i]) != mp.end()) {
                        mp[s[i]]++;
                        if (mp[s[i]] == 1) {
                            if (mini > j - i + 1) {
                                mini = j - i + 1;
                                ans = s.substr(i, mini);
                            }
                            count++;
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Example usage
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";

    std::string result = solution.minWindow(s, t);

    if (!result.empty()) {
        std::cout << "Minimum window substring: " << result << std::endl;
    } else {
        std::cout << "No such window substring found." << std::endl;
    }

    return 0;
}
