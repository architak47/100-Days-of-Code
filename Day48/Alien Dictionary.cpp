#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

void dfs(int start, int vis[], vector<int> adj[], stack<int> &st) {
    vis[start] = 1;

    for (auto it : adj[start]) {
        if (!vis[it]) {
            dfs(it, vis, adj, st);
        }
    }
    st.push(start);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    int vis[V] = {0};
    stack<int> st;
    vector<int> ans;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }
    while (!st.empty()) {
        int t = st.top();
        st.pop();
        ans.push_back(t);
    }
    return ans;
}

string getAlienLanguage(vector<string> &dictionary, int k) {
    vector<int> adj[k];
    for (int i = 0; i < dictionary.size() - 1; i++) {
        string s1 = dictionary[i];
        string s2 = dictionary[i + 1];
        int len = min(s1.size(), s2.size());
        for (int ptr = 0; ptr < len; ptr++) {
            if (s1[ptr] != s2[ptr]) {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }
    vector<int> topo = topoSort(k, adj);
    string ans = "";
    for (auto it : topo) {
        ans += char(it + 'a');
    }
    return ans;
}

int main() {
    int k = 26;
    vector<string> dictionary = {"wrt", "wrf", "er", "ett", "rftt"};

    string alienLanguage = getAlienLanguage(dictionary, k);

    cout << "Alien Language: " << alienLanguage << endl;

    return 0;
}
