#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if (start == end) return 0;
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        int mod = 100000;

        while (!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            for (auto it : arr) {
                int num = (it * node) % mod;
                if (steps + 1 < dist[num]) {
                    dist[num] = steps + 1;
                    if (num == end) return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    
    // Example usage:
    vector<int> arr = {2, 3, 5};
    int start = 2;
    int end = 12;

    int minSteps = solution.minimumMultiplications(arr, start, end);

    if (minSteps != -1) {
        cout << "Minimum number of multiplications to reach " << end << " from " << start << " is: " << minSteps << endl;
    } else {
        cout << "It's not possible to reach " << end << " from " << start << " using the given operations." << endl;
    }

    return 0;
}
