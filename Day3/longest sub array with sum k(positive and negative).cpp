#include <bits/stdc++.h>
using namespace std;
 
int getLongestSubarray(vector<int>& nums, int k){
    int n = nums.size();
    int sum = 0;
    int maxlen = 0;

    map<int, int> mp;

    for(int i = 0; i < n; i++){
        sum += nums[i];
        if(sum == k){
            maxlen = max(maxlen, i+1);
        }
        int rem = sum - k;

        if(mp.find(rem) != mp.end()){
            int len = i - mp[rem];
            maxlen = max(maxlen, len);
        }
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
    }
    return maxlen;
}
      

int main()
{
    vector<int> v = {2, 3, 5, 1, 9};
    long long k = 10;
    cout << getLongestSubarray(v, k);

    return 0;
}
