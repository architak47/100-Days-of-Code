#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> indegree(V, 0);
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            ans.push_back(f);

            for (auto it : adj[f])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        return ans;
    }
};

int main()
{
    int V = 5;
    int E = 6;
    
    vector<int> adj[V];
    
    // Example graph input
    adj[0].push_back(1);
    adj[0].push_back(3);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(4);

    Solution obj;
    vector<int> result = obj.topoSort(V, adj);

    cout << "Topological Order: ";
    for (int vertex : result)
    {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
