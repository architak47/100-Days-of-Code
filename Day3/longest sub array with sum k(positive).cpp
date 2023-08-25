#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size();
    int maxlen = 0;
    int left = 0, right = 0;

    long long sum = a[0];

    while(right < n){
        while(left <= right && sum > k){
            sum -= a[left];
            left++;
        }

        if(sum == k){
            maxlen = max(maxlen, right - left +1);
        }
        right++;
        if(right < n){
            sum += a[right];
        }
    }
    return maxlen;
}
      

int main()
{
    vector<int> v = {2, 3, 5, 1, 9};
    long long k = 10;
    cout << longestSubarrayWithSumK(v, k);

    return 0;
}
