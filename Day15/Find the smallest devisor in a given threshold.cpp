#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> arr, int div){
	int s = 0;
	int n = arr.size();
	for(int i = 0; i < n; i++){
		s = s + ceil((double)(arr[i]) / (double)(div));
	}
	return s;
}
int smallestDivisor(vector<int>& arr, int limit)
{
	int low = 1, high = *max_element(arr.begin(), arr.end());
	while(low <= high){
		int mid = (low + high)/2;
		if(sum(arr, mid) <= limit){
			high = mid - 1;
		}
		else{
			low = mid+1;
		}
	}
	return low;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";

    return 0;
}
