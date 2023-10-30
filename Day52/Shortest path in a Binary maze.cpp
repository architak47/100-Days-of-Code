#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> dest) {
        // code here
        if(src == dest) return 0;
        
        int n  = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m,1e9));
        dist[src.first][src.second] = 0;
        q.push({0, {src.first, src.second}});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 &&
                dis + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = 1 + dis;
                    if(nrow == dest.first && ncol == dest.second){
                        return dis + 1;
                    }
                    q.push({1+dis, {nrow, ncol}});
                }
            }

        }
        
        return -1;
    }
int main() {
    // Sample input grid, where 1 represents a valid path, and 0 represents an obstacle.
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };

    pair<int, int> src = {0, 0}; // Source coordinates
    pair<int, int> dest = {4, 4}; // Destination coordinates

    int result = shortestPath(grid, src, dest);

    if (result == -1) {
        cout << "There is no valid path from source to destination." << endl;
    } else {
        cout << "Shortest path from source to destination: " << result << " steps." << endl;
    }

    return 0;
}
