#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int node = it.second.first;
            int dis = it.second.second;

            if (steps > k) continue;
            for (auto iter : adj[node]) {
                int adjNode = iter.first;
                int wt = iter.second;
                if (wt + dis < dist[adjNode] && steps <= k) {
                    dist[adjNode] = dis + wt;
                    q.push({steps + 1, {adjNode, dis + wt}});
                }
            }
        }

        if (dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};

int main() {
    Solution solution;
    int n = 4;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src = 0;
    int dst = 2;
    int k = 1;

    int cheapestPrice = solution.findCheapestPrice(n, flights, src, dst, k);

    if (cheapestPrice != -1) {
        cout << "Cheapest price from " << src << " to " << dst << " with at most " << k << " stops is: " << cheapestPrice << endl;
    } else {
        cout << "No valid path within " << k << " stops." << endl;
    }

    return 0;
}
