#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool dfs(int start, int vis[], int pathVis[], vector<int> adj[], int check[]) {
        vis[start] = 1;
        pathVis[start] = 1;
        check[start] = 0;

        for (auto it : adj[start]) {
            if (!vis[it]) {
                if (dfs(it, vis, pathVis, adj, check)) {
                    check[start] = 0;
                    return true;
                }
            } else if (pathVis[it]) {
                check[start] = 0;
                return true;
            }
        }

        check[start] = 1;
        pathVis[start] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        int check[V] = {0};
        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, pathVis, adj, check);
            }
        }
        for (int i = 0; i < V; i++) {
            if (check[i] == 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices (V): ";
    cin >> V;

    vector<int> adj[V];
    cout << "Enter the adjacency list for each vertex (space-separated):" << endl;
    for (int i = 0; i < V; i++) {
        int edges;
        cin >> edges;
        for (int j = 0; j < edges; j++) {
            int destination;
            cin >> destination;
            adj[i].push_back(destination);
        }
    }

    Solution sol;
    vector<int> safeNodes = sol.eventualSafeNodes(V, adj);

    cout << "Eventual Safe Nodes:" << endl;
    for (int node : safeNodes) {
        cout << node << " ";
    }

    return 0;
}
