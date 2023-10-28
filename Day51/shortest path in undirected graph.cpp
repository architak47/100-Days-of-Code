#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        vector<int> adj[N];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int dist[N];
        for (int i = 0; i < N; i++) dist[i] = 1e9;
        dist[src] = 0;

        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            for (auto it : adj[front]) {
                if (dist[front] + 1 < dist[it]) {
                    dist[it] = dist[front] + 1;
                    q.push(it);
                }
            }
        }
        vector<int> ans(N, -1);
        for (int i = 0; i < N; i++) {
            if (dist[i] != 1e9) {
                ans[i] = dist[i];
            }
        }
        return ans;
    }
};

int main() {
    int N = 6;  // Number of nodes
    int M = 7;  // Number of edges
    int src = 0;  // Source node

    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 4},
        {3, 5},
        {4, 5},
        {1, 2}
    };

    Solution solution;
    vector<int> result = solution.shortestPath(edges, N, M, src);

    cout << "Shortest distances from source node " << src << " to all other nodes:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Node " << i << ": ";
        if (result[i] != -1) {
            cout << result[i];
        } else {
            cout << "Not reachable";
        }
        cout << endl;
    }

    return 0;
}
