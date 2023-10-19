#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(int start, int vis[], int pathVis[], vector<int> adj[]){
        vis[start] = 1;
        pathVis[start] = 1;
        
        for(auto it : adj[start]){
            if(!vis[it]){
                if(dfs(it, vis, pathVis, adj) == true) return true;
            }
            else if(pathVis[it])return true;
            
        }
        
        pathVis[start] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, vis, pathVis, adj) == true) return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);

    if (ans) cout << "True\n";
    else cout << "No\n";
}