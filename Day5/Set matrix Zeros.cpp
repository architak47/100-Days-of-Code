#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& e) {
    int row = e.size() , col = e[0].size();

    bool r = false , c = false;

    for(int i=0 ; i<row ; i++) {
        if(e[i][0] == 0) c = true;
    }
    for(int j=0 ; j<col ; j++) {
        if(e[0][j] == 0) r = true;
    }

    for(int i=1; i<row ; i++) {
        for(int j=1 ; j<col ; j++) {
            if(e[i][j] == 0) {
                e[i][0] = 0;
                e[0][j] = 0;
            }
        }
    }

    for(int i=1 ; i<row ; i++) {
        if(e[i][0] == 0) {
            for(int j=1 ; j<col ; j++) {
                e[i][j] = 0;
            }
        }
    }

    for(int j=1; j<col ; j++) {
        if(e[0][j] == 0) {
            for(int i=1 ; i<row ; i++) {
                e[i][j] = 0;
            }
        }
    }

    if(r) {
        for(int j=0 ; j<col ; j++) {
            e[0][j] = 0;
        }
    }

    if(c) {
        for(int i=0 ; i<row ; i++) {
            e[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(matrix);

    cout << "The Final matrix is:\n";
    for (auto it : matrix) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }

    return 0;
}
