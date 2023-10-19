#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    void dfs(int start, int vis[], vector<int> adj[], stack<int> &st)
    {
        vis[start] = 1;

        for (auto it : adj[start])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, st);
            }
        }
        st.push(start);
    }
    // Function to return a list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }
        while (!st.empty())
        {
            int t = st.top();
            st.pop();
            ans.push_back(t);
        }
        return ans;
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    vector<int> adj[V];
    cout << "Enter the edges in the format (source destination):" << endl;
    for (int i = 0; i < E; i++)
    {
        int source, destination;
        cin >> source >> destination;
        adj[source].push_back(destination);
    }

    Solution sol;
    vector<int> topologicalOrder = sol.topoSort(V, adj);

    cout << "Topological Sort Order:" << endl;
    for (int i : topologicalOrder)
    {
        cout << i << " ";
    }

    return 0;
}
