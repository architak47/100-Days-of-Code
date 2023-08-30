#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<vector<int>> ans;
    sort(begin(intervals), end(intervals));
    for(int i = 0; i < n; i++){
        if(ans.empty() or intervals[i][0] > ans.back()[1]){
            ans.push_back(intervals[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = merge(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

    return 0;
}
