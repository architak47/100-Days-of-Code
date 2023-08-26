#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n,0);
    int posidx = 0;
    int negidx = 1;
    
    for(int i = 0; i < n; i++){
        if(nums[i] > 0){
            ans[posidx] = nums[i];
            posidx+=2;
        }
        else{
            ans[negidx] = nums[i];
            negidx+=2;
        }
    }
    return ans;
}

int main()
{
  int n = 4;
  vector<int> A {1,2,-4,-5};

  vector<int> ans = rearrangeArray(A);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

    return 0;
}
