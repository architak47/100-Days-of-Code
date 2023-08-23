#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int cnt = 0;

    for(int i = 1; i < n; i++){
        if(nums[i] == nums[i-1]){
            cnt++;
        }
        else{
            nums[i-cnt] = nums[i];
        }
    }
    return n-cnt;
}

int main()
{
    vector<int> v = {0,0,1,1,1,2,2,3,3,4};
    int size = removeDuplicates(v);
    
    for(int i = 0; i < size; i++){
        cout << v[i] << ' ';
    }
    return 0;
    
}
