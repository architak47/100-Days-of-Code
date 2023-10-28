// This code is for finding the shortest path in directed acyclic graph
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // topoSort function code
    void topoSort(int start, int vis[], vector<pair<int, int>> adj[], stack<int> &st){
        vis[start] = 1;

        for(auto it : adj[start]){
            int v = it.first;
            if(!vis[v]){
                topoSort(v, vis, adj, st);
            }
        }

        st.push(start);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int, int>> adj[N];
        for(int i = 0; i < M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }

        // topo Sort
        int vis[N] = {0};
        stack<int> st;
        for(int i = 0; i < N; i++){
            if(!vis[i]){
                topoSort(i, vis, adj, st);
            }
        }

        // now go for distance
        vector<int> dist(N, 1e9);
        dist[0] = 0;

        while(!st.empty()){
            int top = st.top();
            st.pop();
            for(auto it : adj[top]){
                int v = it.first;
                int w = it.second;
                if(dist[top] + w < dist[v]){
                    dist[v] = dist[top] + w;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};

int main() {
    int N = 6;
    int M = 9;
    vector<vector<int>> edges = {{0, 1, 5}, {0, 2, 3}, {1, 2, 2}, {1, 3, 6}, {2, 3, 7}, {2, 4, 4}, {3, 4, 5}, {3, 5, 2}, {4, 5, 1}};
    Solution solution;

    vector<int> result = solution.shortestPath(N, M, edges);

    cout << "Shortest distances from node 0 to all other nodes:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Node " << i << ": " << result[i] << endl;
    }

    return 0;
}
