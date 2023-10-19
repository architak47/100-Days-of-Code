#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
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
        
        if (ans.size() == V) {
            return ans;
        } else {
            return {};
        }
    }
};

int main() {
    Solution obj;
    int V = 4; // Number of courses
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};

    vector<int> result = obj.findOrder(V, prerequisites);

    if (!result.empty()) {
        cout << "Valid order of courses: ";
        for (int course : result) {
            cout << course << " ";
        }
        cout << endl;
    } else {
        cout << "No valid order of courses exists due to prerequisites." << endl;
    }

    return 0;
}
