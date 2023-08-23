#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums) {
        int n = nums.size()-1;
        int ans = 0;
        
        for(int i = 1 ; i <= n ; i++){
            if(nums[i-1] > nums[i] ){
                ans++;
            }
        }
        if(nums[n]>nums[0]){
            ans++;
        }
        return ans<=1;
    }


int main()
{
    vector<int> v = {1,3,5,6};
    if(check(v)){
        cout << "Array is sorted \n";
    }
    else{
        cout << "Array is not sorted\n";
    }
    return 0;
    
}
