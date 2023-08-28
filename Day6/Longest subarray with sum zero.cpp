#include<bits/stdc++.h>
using namespace std;

int getLongestZeroSumSubarrayLength(vector<int> &arr){
	int sum = 0;
	unordered_map<int, int> mp;
	int ans = 0;

	for(int i = 0; i < arr.size(); i++){
		sum += arr[i];
		if(sum == 0){
			ans = i+1;
		}
		if(mp.find(sum) == mp.end()){
			mp.insert({sum, i});
		}
		if(mp.find(sum) != mp.end()){
			ans = max(ans, i-mp[sum]);
		}
	}
	return ans;
}

int main()
{
    vector<int> v = {1, 2, -2, 4, -4};
    cout << getLongestZeroSumSubarrayLength(v);

    return 0;
}
