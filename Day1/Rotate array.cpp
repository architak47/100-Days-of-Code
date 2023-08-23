#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int>& vec, int i, int j){
    while(i < j){
        swap(vec[i], vec[j]);
        i++;
        j--;
    }
}
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k%n;

    reverse(nums, 0, n-1);
    reverse(nums, k, n-1);
    reverse(nums, 0, k-1);
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7};
    rotate(v, 3);
    
    for(int i = 0; i < 7; i++){
        cout << v[i] << ' ';
    }
    return 0;
    
}
