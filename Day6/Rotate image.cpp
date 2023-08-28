#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> store;
    for(int i = 0; i < row; i++){
        vector<int> temp;
        for(int j = col-1; j >= 0; j--){
            temp.push_back(matrix[j][i]);
        }
        store.push_back(temp);
    }
    matrix = store;
}

int main()
{
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
        cout << arr[i][j] << " ";
    }
    cout << "\n";
    }

    return 0;
}
