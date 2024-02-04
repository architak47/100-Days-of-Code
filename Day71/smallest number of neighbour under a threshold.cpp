#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (auto it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for (int i = 0; i < n; i++) dist[i][i] = 0;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) {
                        continue;
                    }
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int cntCity = n;
        int cityNo = -1;
        for (int city = 0; city < n; city++) {
            int cnt = 0;
            for (int adjCity = 0; adjCity < n; adjCity++) {
                if (dist[city][adjCity] <= distanceThreshold)
                    cnt++;
            }
            if (cnt <= cntCity) {
                cntCity = cnt;
                cityNo = city;
            }
        }
        return cityNo;
    }
};

int main() {
    Solution solution;
    
    // Example usage
    int n = 4;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 4}, {1, 2, 1}, {1, 3, 5}, {2, 3, 1}};
    int distanceThreshold = 4;

    int result = solution.findTheCity(n, edges, distanceThreshold);

    cout << "The city with the smallest number of cities within the distance threshold is: " << result << endl;

    return 0;
}
