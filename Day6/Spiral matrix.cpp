#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int row = matrix.size(), col = matrix[0].size();
    int startRow = 0, endRow = row-1;
    int startCol = 0, endCol = col-1;
    int total = row * col;
    int count = 0;

    while(count < total){
        for(int i = startCol; count < total and i <= endCol; i++){
            ans.push_back(matrix[startRow][i]);
            count++;
        }
        startRow++;
        for(int i = startRow; count < total and i <= endRow; i++){
            ans.push_back(matrix[i][endCol]);
            count++;
        }
        endCol--;
        for(int i = endCol; count < total and i >= startCol; i--){
            ans.push_back(matrix[endRow][i]);
            count++;
        }
        endRow--;
        for(int i = endRow; count < total and i >= startRow; i--){
            ans.push_back(matrix[i][startCol]);
            count++;
        }
        startCol++;
    }
    return ans;
}

int main()
{
     vector<vector<int>> mat   {{1, 2, 3, 4},
                             {5, 6, 7, 8},
	                         {9, 10, 11, 12},
		                     {13, 14, 15, 16}};
		                     
    vector<int> ans = spiralOrder(mat);

    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
  
  cout<<endl;

    return 0;
}
