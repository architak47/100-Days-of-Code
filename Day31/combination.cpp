#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ans;

void dfs(int i, int n, int k, vector<int>& temp) {
    if (k == 0) {
        ans.push_back(temp);
        return;
    }
    if (i == n) return;
    dfs(i + 1, n, k, temp);
    temp.push_back(i + 1);
    dfs(i + 1, n, k - 1, temp);
    temp.pop_back();
}

vector<vector<int>> combine(int n, int k) {
    vector<int> temp;
    dfs(0, n, k, temp);
    return ans;
}

int main() {
    int n = 4; // Replace with your desired 'n'
    int k = 2; // Replace with your desired 'k'

    vector<vector<int>> result = combine(n, k);

    cout << "Combinations of " << k << " elements from [1, 2, ..., " << n << "] are:" << endl;

    for (const vector<int>& combination : result) {
        cout << "[";
        for (int i = 0; i < combination.size(); i++) {
            cout << combination[i];
            if (i < combination.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
