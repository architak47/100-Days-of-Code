#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        vector<int> indeg(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < graph[i].size(); j++){
                int t = graph[i][j];
                adj[t].push_back(i);
                indeg[i]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int f = q.front();
            q.pop();
            ans.push_back(f);
            for(auto it : adj[f]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};

int main() {
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};

    Solution solution;
    vector<int> result = solution.eventualSafeNodes(graph);

    cout << "Eventual Safe Nodes: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
