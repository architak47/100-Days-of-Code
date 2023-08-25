#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int t = 0;
    for(auto it : nums){
        t = t ^ it;
    }
    return t;
}
      

int main()
{
    vector<int> v = {4,1,2,1,2};
    cout << singleNumber(v);

    return 0;
}
