#include <bits/stdc++.h>
using namespace std;

int linearSearch(int n, int target, vector<int> &arr)
{
    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}


int main()
{
    vector<int> nums = {6,7,4,8,1};
    int target = 4;
    cout << linearSearch(5, 4, nums);

    return 0;
}
