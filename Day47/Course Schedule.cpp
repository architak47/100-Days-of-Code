#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> indegree(V, 0);
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int f = q.front();
            q.pop();
            ans.push_back(f);

            for (auto it : adj[f]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        return ans.size() == V;
    }
};

int main() {
    Solution obj;
    int V = 4; // Number of courses
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};

    bool result = obj.canFinish(V, prerequisites);

    if (result) {
        cout << "Yes it is possible to complete all courses." << endl;
    } else {
        cout << "It is not possible to complete all courses." << endl;
    }

    return 0;
}
