#include <iostream>
#include <vector>

using namespace std;

bool bfs(int start, int col, vector<int> adjL[], vector<int> &vis){
	vis[start] = col;

	for(auto it : adjL[start]){
		if(vis[it] == -1){
			vis[it] = !vis[start];
			if(!bfs(it, !col, adjL, vis)) return false;
		}
		else if(vis[it] == col) return false;
	}
	return true;
}

bool isGraphBipartite(vector<vector<int>> &edges) {
	int n = edges.size();
	int m = edges[0].size();
	vector<int> adjL[n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if (edges[i][j] == 1) {
				adjL[i].push_back(j);
			}
		}
	}

	vector<int> vis(n, -1);
	for(int i = 0; i < n; i++){
		if(vis[i] == -1){
			if(!bfs(i, 0, adjL, vis)) return false;
		}
	}
	return true;
}

int main() {
	vector<vector<int>> edges = {
		{0, 1, 0},
		{1, 0, 1},
		{0, 1, 0}
	};

	if (isGraphBipartite(edges)) {
		cout << "The graph is bipartite." << endl;
	} else {
		cout << "The graph is not bipartite." << endl;
	}

	return 0;
}
