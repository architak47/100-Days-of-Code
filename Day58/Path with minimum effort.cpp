#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int minimumTimeTakingPath(vector<vector<int>> &heights) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});

    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> diff(n, vector<int>(m, 1e9));
    diff[0][0] = 0;

    int dr[] = {1, 0, -1, 0};
    int dc[] = {0, -1, 0, 1};

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if (row == n - 1 && col == m - 1) {
            return dis;
        }

        for (int i = 0; i < 4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                int newEffort = max(abs(heights[nrow][ncol] - heights[row][col]), dis);
                if (diff[nrow][ncol] > newEffort) {
                    diff[nrow][ncol] = newEffort;
                    pq.push({newEffort, {nrow, ncol}});
                }
            }
        }
    }

    return 0;
}

int main() {
    vector<vector<int>> heights = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int result = minimumTimeTakingPath(heights);
    cout << "Minimum time-taking path effort: " << result << endl;

    return 0;
}
