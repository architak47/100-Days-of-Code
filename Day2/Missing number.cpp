#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();

    int Total = (n*(n+1))/2;
    int sum = 0;

    for(auto it : nums){
        sum += it;
    }

    return Total - sum;
}


int main()
{
    vector<int> arr = {9,6,4,2,3,5,7,0,1};
    
    cout << missingNumber(arr);
    
    return 0;
}
